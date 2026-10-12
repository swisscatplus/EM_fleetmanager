"""
path.py  -  station path planner for the lab robots (plain Python, no ROS).

Inputs (YAML files from the EM_fleetmanager repo):
    src/tracker/config/map_pois.yaml        : road centre lines (nodes + edges)
    src/fleet_manager/config/stations.yaml  : docking pose (x, y, yaw) of each station

Use:
    planner = Planner(<path to map_pois.yaml>, <path to stations.yaml>)
    planner.plan("LC MS", "Chemspeed SwingSP")             # station -> station
    planner.plan_from_pose(x, y, yaw, "LC MS")             # robot anywhere -> station

What it does for one trip:
    1. attach every station (and the robot) to the closest road: node on the centre line
    2. A* on the road graph                -> which roads to take
    3. replace node names by coordinates
    4. near each end: 0.5 m straight + slow sideways shift (<= 1.5 m) between
       the road centre and the station lane, never past a corner
    5. forward / backward from the start yaw + check the arrival heading
    6. round the corners (arcs, R <= 0.4 m) so the MPC turns smoothly

Adding a station = adding it in stations.yaml. Tests and plots: test_path.py.
"""

import heapq
import math

import yaml

# ---------------------------------------------------------------- parameters
D_STRAIGHT = 0.5    # straight part right before/after the station (m)
D_SHIFT_MAX = 1.5   # max length of the slow sideways shift (m)
HEADING_TOL = 0.15  # same tolerance as the MPC (rad)
SAME_POINT = 0.02   # two points closer than this are considered the same (m)
TURN_RADIUS = 0.4   # radius of the rounded corners (m); MPC turns at v/R = 0.15/0.4 = 0.38 rad/s
MIN_CORNER = 20.0   # corners sharper than this (deg) are rounded; smaller ones (lane shifts) are kept
ARC_STEP = 0.05     # distance between two points on a rounded corner (m)


# ---------------------------------------------------------------- small geometry helpers
def heading(p, q):
    """direction (rad) of the move p -> q"""
    return math.atan2(q[1] - p[1], q[0] - p[0])


def angle_diff(a, b):
    """smallest absolute difference between two angles (rad)"""
    return abs((a - b + math.pi) % (2 * math.pi) - math.pi)


def unit(p, q):
    """unit vector from p to q"""
    d = math.dist(p, q)
    return ((q[0] - p[0]) / d, (q[1] - p[1]) / d)


def move(p, u, dist):
    """point p moved by `dist` metres along unit vector u"""
    return (p[0] + u[0] * dist, p[1] + u[1] * dist)


def project_on_segment(p, a, b):
    """closest point to p on segment a-b, and its distance to p"""
    ax, ay = a
    dx, dy = b[0] - ax, b[1] - ay
    t = ((p[0] - ax) * dx + (p[1] - ay) * dy) / (dx * dx + dy * dy)
    t = max(0.0, min(1.0, t))          # stay on the segment
    proj = (ax + t * dx, ay + t * dy)
    return proj, math.dist(p, proj)


# ---------------------------------------------------------------- loading
def load_graph(path):
    """
    Reads the road map. Works with both formats:
      - lab_graph.yaml : nodes: {name: [x, y]}
      - map_pois.yaml  : points_of_interest: {group: {name: [x, y]}}  (EM_fleetmanager/src/tracker/config)
    """
    data = yaml.safe_load(open(path))
    if "points_of_interest" in data:                       # map_pois.yaml: points are inside groups
        nodes = {}
        for group in data["points_of_interest"].values():  # intersections, corners, path_ends
            for name, xy in group.items():
                nodes[name] = tuple(xy)
        edges = [tuple(e) for e in data["road_graph"]["edges"]]
    else:                                                  # lab_graph.yaml: flat list
        nodes = {name: tuple(xy) for name, xy in data["nodes"].items()}
        edges = [tuple(e) for e in data["edges"]]
    return nodes, edges


def load_stations(path):
    data = yaml.safe_load(open(path))["stations"]
    stations, skipped = {}, []
    for name, s in data.items():
        p = s["docking_pose"]
        if None in (p["x"], p["y"], p["yaw"]):
            skipped.append(name)
        else:
            stations[name] = (float(p["x"]), float(p["y"]), float(p["yaw"]))
    return stations, skipped


# ---------------------------------------------------------------- step 1: attach stations to the roads
def attach_stations(nodes, edges, stations):
    """
    For each station, find the closest road and put a node there (on the centre line).
    The road is cut in two at that node.
    Returns new nodes, new edges, and {station name: road node name}.
    """
    nodes, edges = dict(nodes), list(edges)
    station_node = {}
    for name, (x, y, _) in stations.items():
        # closest road (edge)
        best = None
        for a, b in edges:
            proj, d = project_on_segment((x, y), nodes[a], nodes[b])
            if best is None or d < best[1]:
                best = (proj, d, a, b)
        proj, _, a, b = best

        # if a node already exists there (junction, end, or another station), reuse it
        existing = [n for n, xy in nodes.items() if math.dist(xy, proj) < SAME_POINT]
        if existing:
            station_node[name] = existing[0]
            continue

        # otherwise create a node and cut the road a-b into a-new and new-b
        new = "road@" + name
        nodes[new] = proj
        edges.remove((a, b))
        edges += [(a, new), (new, b)]
        station_node[name] = new
    return nodes, edges, station_node


# ---------------------------------------------------------------- step 2: A*
def build_graph(nodes, edges):
    """adjacency list: graph[a][b] = length of the road a-b"""
    graph = {n: {} for n in nodes}
    for a, b in edges:
        graph[a][b] = graph[b][a] = math.dist(nodes[a], nodes[b])
    return graph


def astar(graph, nodes, start, goal):
    h = lambda n: math.dist(nodes[n], nodes[goal])
    open_list = [(h(start), start)]
    cost, came_from = {start: 0.0}, {start: None}
    while open_list:
        _, cur = heapq.heappop(open_list)
        if cur == goal:
            route = []
            while cur is not None:
                route.append(cur)
                cur = came_from[cur]
            return route[::-1]
        for nb, d in graph[cur].items():
            if cost[cur] + d < cost.get(nb, math.inf):
                cost[nb] = cost[cur] + d
                came_from[nb] = cur
                heapq.heappush(open_list, (cost[nb] + h(nb), nb))
    raise RuntimeError(f"no road between {start} and {goal}")


# ---------------------------------------------------------------- step 4: station approach
def straight_length(points):
    """length of the straight line at the START of `points` (stops at the first corner)"""
    u0 = unit(points[0], points[1])
    length = 0.0
    for p, q in zip(points[:-1], points[1:]):
        if angle_diff(heading(p, q), math.atan2(u0[1], u0[0])) > 0.01:
            break                                   # corner: the straight part ends here
        length += math.dist(p, q)
    return length


def station_end(dock, road_pts, available):
    """
    Points at one end of the path, ordered FROM the station TOWARD the rest of the route:
        dock -> shift_end (in the station lane) -> shift_start (back on the centre line)
    road_pts : route coordinates starting at the station's road node
    available: straight road length we are allowed to use for this end
    Returns (points, how much road was used, warning or None)
    """
    road = road_pts[0]
    u = unit(road, road_pts[1])                     # along the road, away from the station
    warning = None
    d_straight = D_STRAIGHT
    if available < D_STRAIGHT + 0.2:
        d_straight = max(0.1, available / 2)
        warning = f"short road ({available:.2f} m): straight part reduced to {d_straight:.2f} m"
    lateral = abs(u[0] * (dock[1] - road[1]) - u[1] * (dock[0] - road[0]))
    if lateral < SAME_POINT and math.dist(dock[:2], road) < SAME_POINT:
        return [dock[:2]], 0.0, None                # already on the centre line: nothing to shift
    used = min(d_straight + D_SHIFT_MAX, available)
    shift_end = move(dock[:2], u, d_straight)       # still in the station lane
    shift_start = move(road, u, used)               # back on the centre line
    return [dock[:2], shift_end, shift_start], used, warning


def drop_points_before(points, origin, dist):
    """remove the route points that lie less than `dist` from `origin` (they are inside the shift zone)"""
    return [p for p in points if math.dist(p, origin) > dist + 1e-6]


def dedupe(points):
    out = [points[0]]
    for p in points[1:]:
        if math.dist(p, out[-1]) > 1e-6:
            out.append(p)
    return out


# ---------------------------------------------------------------- step 6: round the corners
def round_corners(points, radius=TURN_RADIUS):
    """
    Replace every sharp corner by a circular arc (like a road curve), so the MPC
    turns smoothly at a constant rate instead of stopping and spinning.

    - corners below MIN_CORNER degrees (the slow lane shifts) are left as they are
    - the first/last D_STRAIGHT metres stay straight: they hold the start/arrival heading
    - the radius is reduced automatically when a road piece is too short
    """
    out = [points[0]]
    for i in range(1, len(points) - 1):
        prev, corner, nxt = out[-1], points[i], points[i + 1]
        a = unit(prev, corner)                      # incoming direction
        b = unit(corner, nxt)                       # outgoing direction
        turn = math.acos(max(-1.0, min(1.0, a[0] * b[0] + a[1] * b[1])))   # 0 = straight on
        if math.degrees(turn) < MIN_CORNER or math.degrees(turn) > 170:
            out.append(corner)                      # keep the corner as it is
            continue

        # how far before/after the corner the arc starts/ends (tangent length)
        len_in, len_out = math.dist(prev, corner), math.dist(corner, nxt)
        max_in = len_in - D_STRAIGHT if i == 1 else 0.45 * len_in               # keep the start straight
        max_out = len_out - D_STRAIGHT if i == len(points) - 2 else 0.45 * len_out  # keep the arrival straight
        d = min(radius * math.tan(turn / 2), max_in, max_out)
        if d < 0.03:                                # no room to round this corner
            out.append(corner)
            continue
        r = d / math.tan(turn / 2)                  # radius actually used

        t1 = move(corner, a, -d)                    # arc start, on the incoming road
        left = a[0] * b[1] - a[1] * b[0] > 0        # turning left or right?
        n = (-a[1], a[0]) if left else (a[1], -a[0])  # normal pointing to the arc centre
        centre = move(t1, n, r)

        start_angle = math.atan2(t1[1] - centre[1], t1[0] - centre[0])
        sweep = turn if left else -turn
        steps = max(3, math.ceil(r * turn / ARC_STEP))
        for k in range(steps + 1):
            ang = start_angle + sweep * k / steps
            out.append((centre[0] + r * math.cos(ang), centre[1] + r * math.sin(ang)))
    out.append(points[-1])
    return dedupe(out)


# ---------------------------------------------------------------- the planner
class Planner:
    def __init__(self, graph_file, stations_file):
        base_nodes, base_edges = load_graph(graph_file)
        self.stations, self.skipped = load_stations(stations_file)
        self.nodes, self.edges, self.station_node = attach_stations(
            base_nodes, base_edges, self.stations)
        self.graph = build_graph(self.nodes, self.edges)

    def plan(self, start, goal):
        """Path from station `start` to station `goal` (see _plan for the result)."""
        return self._plan(start, self.stations[start], self.station_node[start],
                          goal, self.nodes, self.graph)

    def plan_from_pose(self, x, y, yaw, goal, max_dist_to_road=0.30):
        """
        Path from ANY robot pose (x, y, yaw) to station `goal`.
        The robot is attached to the closest road exactly like a station,
        but only for this request (the map itself is not changed).
        """
        nodes, edges, attached = attach_stations(self.nodes, self.edges, {"robot": (x, y, yaw)})
        road_xy = nodes[attached["robot"]]
        if math.dist((x, y), road_xy) > max_dist_to_road:
            return {"warnings": [f"robot is {math.dist((x, y), road_xy):.2f} m from the closest road: "
                                 "drive it back on a road first"]}
        return self._plan("robot", (x, y, yaw), attached["robot"], goal, nodes, build_graph(nodes, edges))

    def _plan(self, start, s, ns, goal, nodes, graph):
        """
        start/s/ns : name, pose (x, y, yaw) and road node of the starting point
        Returns a dict:
            route     : A* node names
            points    : path corners (x, y) to send to the tracker
            direction : 'forward' or 'backward' (whole path)
            ok        : True if the robot arrives with the station's yaw
            warnings  : list of strings
        or a dict with only 'warnings' if no path is possible.
        """
        g, ng = self.stations[goal], self.station_node[goal]
        if ns == ng:
            if math.dist(s[:2], g[:2]) < SAME_POINT and angle_diff(s[2], g[2]) < HEADING_TOL:
                return {"warnings": ["already at the station"]}
            if angle_diff(s[2], g[2]) > HEADING_TOL and math.dist(s[:2], g[:2]) < SAME_POINT:
                return {"warnings": ["same spot: no path, only a turn in place"]}

        # step 2-3: A* then names -> coordinates
        route = astar(graph, nodes, ns, ng)
        pts = [nodes[n] for n in route]
        if len(pts) == 1:                            # start and goal on the same road point
            pts = [pts[0], pts[0]]
        if math.dist(pts[0], pts[-1]) < 1e-6:
            return {"warnings": ["start is level with the station on the same road: "
                                 "move along the road first"]}

        # how much straight road each end may use (shared if the whole trip is one straight line)
        avail_s = straight_length(pts)
        avail_g = straight_length(pts[::-1])
        total = sum(math.dist(p, q) for p, q in zip(pts[:-1], pts[1:]))
        if avail_s >= total - 1e-6:                 # no corner at all between start and goal
            avail_s = avail_g = total / 2

        # step 4: both ends
        leave, used_s, w1 = station_end(s, pts, avail_s)
        arrive, used_g, w2 = station_end(g, pts[::-1], avail_g)
        middle = drop_points_before(pts, pts[0], used_s)
        middle = drop_points_before(middle, pts[-1], used_g)
        points = dedupe(leave + middle + arrive[::-1])
        warnings = [f"{start}: {w1}"] * bool(w1) + [f"{goal}: {w2}"] * bool(w2)

        # step 5: forward/backward from the start yaw, then check the arrival heading
        first = heading(points[0], points[1])
        forward = angle_diff(first, s[2]) < math.pi / 2
        final = heading(points[-2], points[-1]) + (0.0 if forward else math.pi)
        ok = angle_diff(final, g[2]) < HEADING_TOL
        if min(angle_diff(first, s[2]), math.pi - angle_diff(first, s[2])) > 0.35:
            warnings.append(f"{start}: yaw is not along the road -> turn in place first "
                            f"(on the road centre, not in a station lane)")
        if not ok:
            warnings.append("arrives facing the wrong way -> needs a 180 deg turn or a split path")

        # step 6: round the sharp corners for the MPC
        points = round_corners(points)

        return {"route": route, "points": points,
                "direction": "forward" if forward else "backward",
                "ok": ok, "warnings": warnings}