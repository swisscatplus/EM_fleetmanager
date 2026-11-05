"""
path_planner.py  -  station path planner for the lab robots (plain Python, no ROS).

Inputs (YAML files from the EM_fleetmanager repo):
    src/tracker/config/map_pois.yaml        : road centre lines (nodes + edges)
    src/fleet_manager/config/stations.yaml  : docking pose (x, y, yaw) of each station

Use:
    planner = Planner(<path to map_pois.yaml>, <path to stations.yaml>)
    planner.plan("LC MS", "Chemspeed SwingSP")             # station -> station
    planner.plan_from_pose(x, y, yaw, "LC MS")             # robot anywhere -> station

What it does for one trip:
    1. attach every station (and the robot) to the closest road: node on the centre line
    2. A* on (road node, which way the robot faces, how it is moving)
         -> which roads to take, forward or backward on each part,
            and WHERE to turn in place (only at junctions, or at the start if the
            robot is already on the centre line)
    3. the result is a list of STEPS, e.g.
         drive forward  (robot -> top_right_t)
         turn to -90 deg (at top_right_t)
         drive backward (top_right_t -> Battery)
    4. near the start and the goal: 0.5 m straight + slow sideways shift (<= 1.5 m)
       between the road centre and the station lane
    5. round the corners (arcs, R <= 0.4 m) so the MPC turns smoothly
    6. special case: a station whose yaw points ACROSS its road (SFC QTOF, robot docked sideways).
       The robot cannot turn at the docking point itself (too close to the border), so:
         arriving: drive along the road to the point of the CENTRE LINE level with the station,
                   turn in place there to the docking yaw, then a short straight "creep"
                   (forward or backward, slow) sideways into the station
         leaving : the same backwards: creep straight back to the centre line, then plan as usual
       If that station is at the END of a dead-end road (SFC QTOF, past right_top_end), the robot must
       arrive REVERSING (back toward the end wall: the back sticks out 0.071 m, the front 0.229 m),
       and it never turns in place to face the end wall there.
       All other stations are planned exactly as before.

Adding a station = adding it in stations.yaml. Tests and plots: test_path.py.
"""

import heapq
import math

import yaml

# ---------------------------------------------------------------- parameters
D_STRAIGHT = 0.5    # straight part right before/after the station (m)
D_SHIFT_MAX = 1.5   # max length of the slow sideways shift (m)
HEADING_TOL = 0.15  # same tolerance as the MPC (rad)
START_TOL = 0.35    # start yaw error (rad, ~20 deg) the MPC can fix while driving (no turn needed)
FACING_TOL = 0.6    # rad (~34 deg): a robot in a lane must be at least this straight to drive out
TURN_MAX_OFFSET = 0.08  # turning in place sweeps r = 0.245 m; road half-width 0.325 -> must be within 8 cm of the centre
SAME_POINT = 0.02   # two points closer than this are considered the same (m)
SNAP_TO_NODE = 0.10  # robot closer than this to a map node: start from that node (m)
TURN_RADIUS = 0.4   # radius of the rounded corners (m); MPC turns at v/R = 0.15/0.4 = 0.38 rad/s
MIN_CORNER = 20.0   # corners sharper than this (deg) are rounded; smaller ones (lane shifts) are kept
ARC_STEP = 0.05     # distance between two points on a rounded corner (m)

# A* costs, in SECONDS (so driving and turning can be compared)
V_NOMINAL = 0.15    # m/s, driving speed
W_TURN = 0.4        # rad/s, average turning speed
T_STOP = 2.0        # s, stopping + starting again (before/after a turn, or forward <-> backward)
T_BACK = 1.0        # s, small extra cost for each backward part (forward is preferred when equal)
TURN_ONLY_AT_JUNCTIONS = True   # True: turns only at map junctions/corners (more room than mid-road)
AT_STATION = 0.10   # m: robot this close to an across-road station = arrived there (only the final turn is left)
MAX_CREEP = 0.30    # m: longest straight sideways move between the centre line and an across-road station

FORWARD, BACKWARD, STOP, LANE = "forward", "backward", "stop", "lane"

# ---------------------------------------------------------------- small geometry helpers
def heading(p, q):
    """direction (rad) of the move p -> q"""
    return math.atan2(q[1] - p[1], q[0] - p[0])


def angle_diff(a, b):
    """smallest absolute difference between two angles (rad)"""
    return abs((a - b + math.pi) % (2 * math.pi) - math.pi)


def wrap(a):
    """angle brought back between -pi and pi"""
    return math.atan2(math.sin(a), math.cos(a))


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


def straight_road(graph, nodes, a, b):
    """length of straight road starting at node a and going through b (continues straight through junctions)"""
    u = unit(nodes[a], nodes[b])
    total = math.dist(nodes[a], nodes[b])
    prev, cur = a, b
    while True:
        nxt = [n for n in graph[cur] if n != prev
               and angle_diff(heading(nodes[cur], nodes[n]), math.atan2(u[1], u[0])) < 0.01]
        if not nxt:
            return total
        prev, cur = cur, nxt[0]
        total += math.dist(nodes[prev], nodes[cur])


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

        before:  ----------+          after:  --------._
                           |                           \\
                           |                            |

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



# ---------------------------------------------------------------- facings: 4 directions along the roads
#   0 = right (+x)   1 = up (+y)   2 = left (-x)   3 = down (-y)
def facing_of(angle):
    """angle (rad) -> closest of the 4 road directions, and how far it is from it (rad)"""
    k = round(angle / (math.pi / 2)) % 4
    return k, angle_diff(angle, k * math.pi / 2)


def facing_angle(k):
    return wrap(k * math.pi / 2)


def turn_angle(k1, k2):
    """angle (rad) of the turn in place from facing k1 to facing k2"""
    d = (k2 - k1) % 4
    return math.pi / 2 * min(d, 4 - d)


# ---------------------------------------------------------------- across-road station: centre point + creep
def centre_point(p, graph, nodes, n):
    """
    Point of the road CENTRE LINE level with p, on the road through node n.
    (p projected on the road's line; it may be a bit past the end of the road in the map.)
    Returns (that point, how far along the road from n it is (m), sideways distance p <-> point (m))
    """
    nb = next(iter(graph[n]))                       # any road leaving n gives the road's direction
    u = unit(nodes[n], nodes[nb])
    along = (p[0] - nodes[n][0]) * u[0] + (p[1] - nodes[n][1]) * u[1]
    c = move(nodes[n], u, along)
    return c, along, math.dist(p[:2], c)


def road_offset(p, graph, nodes, n):
    """
    sideways distance between point p and the road centre line, p being attached to node n.
    Normally = distance to n (n is the closest point of the centre line).
    At the END of a dead-end road (e.g. SFC QTOF, 14 cm past right_top_end), the point can be
    ON the centre line but further along: then only the sideways part counts.
    """
    if len(graph[n]) == 1:
        return centre_point(p, graph, nodes, n)[2]
    return math.dist(p[:2], nodes[n])


def away_from_end(graph, nodes, n):
    """at a dead-end node n (only one road): the facing pointing back along the road, away from the end"""
    return facing_of(heading(nodes[n], nodes[next(iter(graph[n]))]))[0]


def creep_step(frm, to, yaw, at):
    """
    a short STRAIGHT move from `frm` to `to` (no tracker: path_sender drives it slowly itself),
    keeping the robot's heading `yaw`. Forward if `to` is in front of the robot, else backward.
    """
    ahead = (to[0] - frm[0]) * math.cos(yaw) + (to[1] - frm[1]) * math.sin(yaw)
    return {"type": "creep", "from": tuple(frm[:2]), "to": tuple(to[:2]), "yaw": yaw, "at": at,
            "direction": FORWARD if ahead > 0 else BACKWARD}


# ---------------------------------------------------------------- step 2: A* with the heading
def astar_heading(graph, nodes, starts, goal, goal_f, can_turn):
    """
    A* where a STATE is (node, facing, mode):
        node   : road node name
        facing : which way the robot's FRONT points (0..3, see facing_of)
        mode   : how the robot arrived there
                   'forward' / 'backward' : it is driving (it can go on through a corner)
                   'stop'                 : it is standing still (after a turn, or at the start)
                   'lane'                 : start, robot in a station lane (cannot turn here)

    Moves (cost in seconds):
        turn in place (only where can_turn(node))        T_STOP + angle / W_TURN
        drive forward  along a road  (front first)         length / V_NOMINAL
        drive backward along a road  (back first)          length / V_NOMINAL + T_BACK
        changing forward <-> backward costs T_STOP (the robot must stop)

    Corners: while driving, the robot can go on into a road at 90 deg (rounded arc),
    but it cannot do a U-turn while driving, and it cannot start into a corner
    from standing still.

    starts : list of (state, cost, first_action) -- first_action is None or ("turn", facing)
    goal   : goal node; goal_f : facing required at the goal (one facing, or a set of allowed facings);
             the robot must ARRIVE driving.
    Returns the list of (action, state) from the start, or None.
    """
    def moves(state):
        n, f, m = state
        out = []
        if m != LANE and can_turn(n):
            for df in (1, 2, 3):
                f2 = (f + df) % 4
                out.append(("turn", (n, f2, STOP), T_STOP + turn_angle(f, f2) / W_TURN))
        for nb, length in graph[n].items():
            e, _ = facing_of(heading(nodes[n], nodes[nb]))     # direction of this road
            t = length / V_NOMINAL
            # forward: the front leads -> after this road the robot faces e
            if (m == FORWARD and e != (f + 2) % 4) or e == f:
                extra = T_STOP if m == BACKWARD else 0.0
                out.append((FORWARD, (nb, e, FORWARD), t + extra))
            # backward: the back leads -> after this road the robot faces e + 180 deg
            if (m == BACKWARD and e != f) or e == (f + 2) % 4:
                extra = 0.0 if m == BACKWARD else T_BACK + (T_STOP if m == FORWARD else 0.0)
                out.append((BACKWARD, (nb, (e + 2) % 4, BACKWARD), t + extra))
        return out

    goal_fs = set(goal_f) if isinstance(goal_f, (set, frozenset, tuple, list)) else {goal_f}
    h = lambda n: math.dist(nodes[n], nodes[goal]) / V_NOMINAL
    open_list, cost, came_from = [], {}, {}
    for state, c, first in starts:
        if c < cost.get(state, math.inf):
            cost[state] = c
            came_from[state] = (None, first)
            heapq.heappush(open_list, (c + h(state[0]), c, state))

    while open_list:
        _, c, cur = heapq.heappop(open_list)
        if c > cost[cur]:
            continue                                     # old entry, a cheaper way was found since
        n, f, m = cur
        if n == goal and f in goal_fs and m in (FORWARD, BACKWARD):
            plan = []
            while cur is not None:
                prev, action = came_from[cur]
                plan.append((action, cur))
                cur = prev
            return plan[::-1]
        for action, nxt, dc in moves(cur):
            new = c + dc
            if new < cost.get(nxt, math.inf):
                cost[nxt] = new
                came_from[nxt] = (cur, action)
                heapq.heappush(open_list, (new + h(nxt[0]), new, nxt))
    return None


# ---------------------------------------------------------------- the planner
class Planner:
    def __init__(self, graph_file, stations_file):
        base_nodes, base_edges = load_graph(graph_file)
        self.junctions = {n for n in base_nodes                       # map points where 2+ roads meet
                          if sum(n in e for e in base_edges) >= 2}
        self.stations, self.skipped = load_stations(stations_file)
        self.nodes, self.edges, self.station_node = attach_stations(
            base_nodes, base_edges, self.stations)
        self.graph = build_graph(self.nodes, self.edges)

    def plan(self, start, goal):
        """Path from station `start` to station `goal` (see _plan for the result)."""
        s, ns = self.stations[start], self.station_node[start]
        return self._plan(start, s, ns, goal, self.nodes, self.graph,
                          offset=road_offset(s, self.graph, self.nodes, ns))

    def plan_from_pose(self, x, y, yaw, goal, max_dist_to_road=0.30):
        """
        Path from ANY robot pose (x, y, yaw) to station `goal`.
        The robot is attached to the closest road exactly like a station,
        but only for this request (the map itself is not changed).
        If the robot seems to be far from the road centre, the path is still made,
        but a warning says the localization may be wrong.
        """
        nodes, edges, attached = attach_stations(self.nodes, self.edges, {"robot": (x, y, yaw)})
        ns = attached["robot"]
        graph = build_graph(nodes, edges)
        dist = road_offset((x, y), graph, nodes, ns)
        far = math.dist((x, y), nodes[ns])              # to the map's road (also counts "past the end")
        # robot almost on a node (e.g. stopped a few cm from a junction): start from that node
        for nb, length in graph[ns].items():
            if length < SNAP_TO_NODE:
                ns = nb
                break
        result = self._plan("robot", (x, y, yaw), ns, goal, nodes, graph, offset=dist)
        if far > max_dist_to_road:
            result["warnings"].insert(0, f"robot at ({x:.2f}, {y:.2f}) is {far:.2f} m from the road centre: "
                                         "localization may be wrong")
        return result

    # ------------------------------------------------------------------ internals
    def _can_turn(self, n):
        if TURN_ONLY_AT_JUNCTIONS:
            return n in self.junctions
        return len(self.graph.get(n, ())) >= 2          # anywhere on the centre line, but not at a dead end

    def _plan(self, start, s, ns, goal, nodes, graph, offset):
        """
        start/s/ns : name, pose (x, y, yaw) and road node of the starting point
        offset     : sideways distance between the start and the road centre line (m)
        Returns a dict:
            steps     : list of steps, in order:
                          {"type": "turn",  "yaw": rad, "at": node}
                          {"type": "drive", "direction": "forward"/"backward",
                           "points": [(x, y), ...], "nodes": [...], "last": bool}
            points    : all drive points one after the other (for plots)
            route     : node names visited
            direction : short summary, e.g. "forward > turn > backward"
            ok        : True if a plan was found
            warnings  : list of strings
        """
        g, ng = self.stations[goal], self.station_node[goal]
        warnings = []
        if math.dist(s[:2], g[:2]) < 0.05 and angle_diff(s[2], g[2]) < HEADING_TOL:
            return {"steps": [], "points": [], "route": [], "direction": "-", "ok": True,
                    "warnings": ["already at the station"]}

        goal_f, goal_err = facing_of(g[2])
        if goal_err > HEADING_TOL:
            warnings.append(f"{goal}: docking yaw {math.degrees(g[2]):.0f} deg is not along a road "
                            "-> check stations.yaml")

        # ---- station docked ACROSS its road (robot sideways, e.g. SFC QTOF)?
        #      Then the last drive leg ends on the CENTRE LINE, level with the station (g_end),
        #      arriving along the road (either way); then: turn in place to the docking yaw,
        #      then creep straight into the station.
        #      For every other station `across` is False, g_end = g and nothing below changes.
        road_dirs = {facing_of(heading(nodes[ng], nodes[nb]))[0] for nb in graph[ng]}
        across = goal_f not in road_dirs and (goal_f + 2) % 4 not in road_dirs
        arrive_f = goal_f
        g_end = g                                    # where the last drive leg ends
        tail = []                                    # steps after the last drive leg
        if across:
            centre, along, side = centre_point(g, graph, nodes, ng)
            if side > MAX_CREEP:
                return {"steps": [], "points": [], "route": [], "direction": "-", "ok": False,
                        "warnings": warnings + [
                            f"{goal}: docking yaw is across the road and the station is {side * 100:.0f} cm "
                            f"from the road centre (max {MAX_CREEP * 100:.0f} cm) -> check stations.yaml"]}
            if math.dist(centre, nodes[ng]) > SAME_POINT and not any(
                    project_on_segment(centre, nodes[ng], nodes[nb])[1] < SAME_POINT for nb in graph[ng]):
                warnings.append(f"{goal}: station is {abs(along) * 100:.0f} cm past the end of the road "
                                "in map_pois.yaml (the robot drives there anyway, on the same line)")
            g_end = (centre[0], centre[1], g[2])
            tail = [{"type": "turn", "facing": goal_f, "at": ng, "yaw": g[2]}]
            if side >= SAME_POINT:
                tail.append(creep_step(centre, g, g[2], ng))

            if math.dist(s[:2], g[:2]) < AT_STATION and angle_diff(s[2], g[2]) < HEADING_TOL:
                return {"steps": [], "points": [], "route": [], "direction": "-", "ok": True,
                        "warnings": ["already at the station"]}
            if math.dist(s[:2], centre) <= TURN_MAX_OFFSET:
                # the robot is already at the turning point: only the turn (if needed) + creep are left
                steps = [st for st in tail if st["type"] == "creep" or angle_diff(s[2], g[2]) >= HEADING_TOL]
                if steps and steps[-1]["type"] == "creep":
                    steps[-1] = creep_step(s[:2], g, g[2], ng)
                return {"steps": steps, "points": [], "route": [ng],
                        "direction": " > ".join(step_name(st) for st in steps) or "-",
                        "ok": True, "warnings": warnings}
            if len(graph[ng]) == 1:
                # station at the END of a dead-end road (SFC QTOF): arrive REVERSING, back toward the
                # end wall. The back sticks out only 0.071 m behind base_link, the front 0.229 m.
                arrive_f = {away_from_end(graph, nodes, ng)}
            else:
                arrive_f = road_dirs | {(k + 2) % 4 for k in road_dirs}   # along the road, either way

        # ---- start states: which way may the robot face when it leaves?
        starts = []
        if offset <= TURN_MAX_OFFSET:
            # on the centre line: it may turn in place right here to any of the 4 directions,
            # except, at the end of a dead end, turn to face the end wall (the front would hit it)
            wall_f = (away_from_end(graph, nodes, ns) + 2) % 4 if len(graph[ns]) == 1 else None
            for k in range(4):
                err = angle_diff(s[2], k * math.pi / 2)
                if err < START_TOL:
                    starts.append(((ns, k, STOP), 0.0, None))                     # already facing k
                elif k != wall_f:
                    starts.append(((ns, k, STOP), T_STOP + err / W_TURN, ("turn", k)))
        else:
            # in a station lane: no room to turn, it must drive out the way it faces
            k, err = facing_of(s[2])
            if err > FACING_TOL:
                return {"steps": [], "points": [], "route": [], "direction": "-", "ok": False,
                        "warnings": warnings + [
                            f"{start} at ({s[0]:.2f}, {s[1]:.2f}, {math.degrees(s[2]):.0f} deg) is "
                            f"{offset:.2f} m from the road centre AND {math.degrees(err):.0f} deg crooked: "
                            "cannot turn there nor drive out straight -> straighten it by hand (teleop)"]}
            along = any(facing_of(heading(nodes[ns], nodes[nb]))[0] in (k, (k + 2) % 4) for nb in graph[ns])
            if not along:
                # facing ACROSS the road (e.g. docked sideways at SFC QTOF):
                # creep straight back to the centre line first, then plan from there as usual
                centre, _, side = centre_point(s, graph, nodes, ns)
                if side > MAX_CREEP:
                    return {"steps": [], "points": [], "route": [], "direction": "-", "ok": False,
                            "warnings": warnings + [
                                f"{start} at ({s[0]:.2f}, {s[1]:.2f}, {math.degrees(s[2]):.0f} deg) is "
                                f"{offset:.2f} m from the road centre and faces ACROSS the road: "
                                "too far to creep back -> check the localization, or drive it by hand"]}
                rest = self._plan(start, (centre[0], centre[1], s[2]), ns, goal, nodes, graph, offset=0.0)
                rest["warnings"] = warnings + [w for w in rest["warnings"] if w not in warnings]
                if not rest["ok"] or not rest["steps"]:
                    return rest
                if side >= SAME_POINT:                  # already on the centre line (past a road end): no creep
                    rest["steps"].insert(0, creep_step(s, centre, s[2], ns))
                rest["direction"] = " > ".join(step_name(st) for st in rest["steps"])
                return rest
            starts.append(((ns, k, LANE), 0.0, None))

        # ---- A*
        plan = astar_heading(graph, nodes, starts, ng, arrive_f, self._can_turn)
        if plan is None:
            return {"steps": [], "points": [], "route": [], "direction": "-", "ok": False,
                    "warnings": warnings + [f"no way to reach {goal} facing "
                                            f"{math.degrees(facing_angle(goal_f)):.0f} deg"]}

        # ---- group the A* moves into steps: a turn, or a drive leg (same direction, no stop)
        steps = []
        first_action = plan[0][0]
        if first_action is not None:                     # turn at the start
            steps.append({"type": "turn", "facing": first_action[1], "at": ns})
        for action, (n, f, m) in plan[1:]:
            if action == "turn":
                steps.append({"type": "turn", "facing": f, "at": n})
                continue
            prev = steps[-1] if steps else None
            if prev and prev["type"] == "drive" and prev["direction"] == action:
                prev["nodes"].append(n)
            else:
                start_node = prev["nodes"][-1] if prev and prev["type"] == "drive" else (
                    prev["at"] if prev else plan[0][1][0])
                steps.append({"type": "drive", "direction": action, "nodes": [start_node, n]})

        # ---- coordinates of each drive leg (+ station lane shifts at both ends)
        drives = [st for st in steps if st["type"] == "drive"]
        for i, st in enumerate(drives):
            pts = [nodes[n] for n in st["nodes"]]
            first, last = i == 0, i == len(drives) - 1
            st["last"] = last
            in_lane = first and offset >= 0.05          # the start needs a lane exit (shift to the centre)
            avail_s = straight_length(pts) if in_lane else 0.0
            avail_g = straight_length(pts[::-1]) if last else 0.0
            total = sum(math.dist(p, q) for p, q in zip(pts[:-1], pts[1:]))
            if in_lane and last and avail_s >= total - 1e-6:   # one straight line: share it
                avail_s = avail_g = total / 2
            if in_lane:
                # leave the lane from where the robot REALLY is
                leave, used_s, w1 = station_end(s, pts, avail_s)
                middle = drop_points_before(pts, pts[0], used_s)
            elif first:
                # on the centre line, maybe a few cm from the start node (e.g. it stopped just
                # before a junction, turned, and now leaves on the other road):
                # start from the robot and join the road gently, 30 cm further along it
                leave, w1 = [s[:2]], None
                a, b = pts[0], pts[1]
                u = unit(a, b)
                along = (s[0] - a[0]) * u[0] + (s[1] - a[1]) * u[1]
                join = max(along, 0.0) + 0.3
                middle = ([move(a, u, join)] if join < math.dist(a, b) - 0.05 else []) + pts[1:]
            else:
                leave, w1, middle = [], None, pts
            arrive, used_g, w2 = station_end(g_end, pts[::-1], avail_g) if last else ([pts[-1]], 0.0, None)
            middle = drop_points_before(middle, pts[-1], used_g) if last else middle
            st["points"] = round_corners(dedupe(leave + middle + arrive[::-1]))
            for w, who in ((w1, start), (w2, goal)):
                if w and f"{who}: {w}" not in warnings:
                    warnings.append(f"{who}: {w}")

        # ---- exact yaw of each turn = direction of the ROAD the next leg starts on
        #      (+180 deg if that leg is driven backward)
        for i, st in enumerate(steps):
            if st["type"] != "turn":
                continue
            nxt = next((d for d in steps[i + 1:] if d["type"] == "drive"), None)
            if nxt is None:
                st["yaw"] = facing_angle(st["facing"])
            else:
                road = heading(nodes[nxt["nodes"][0]], nodes[nxt["nodes"][1]])
                st["yaw"] = wrap(road + (math.pi if nxt["direction"] == BACKWARD else 0.0))

        # ---- across-road station: turn in place on the centre line, then creep into the station
        steps += tail

        route = [steps[0]["at"] if steps[0]["type"] == "turn" else drives[0]["nodes"][0]]
        for d in drives:
            route += d["nodes"][1:]
        return {"steps": steps,
                "points": [p for d in drives for p in d["points"]],
                "route": route,
                "direction": " > ".join(step_name(st) for st in steps),
                "ok": True,
                "warnings": warnings}


def step_name(st):
    """short name of a step, for the summary line"""
    return {"turn": "turn", "creep": "creep"}.get(st["type"], st.get("direction", st["type"]))


def describe(result):
    """one line per step, for printing"""
    lines = []
    for st in result["steps"]:
        if st["type"] == "turn":
            lines.append(f"turn in place to {math.degrees(st['yaw']):.0f} deg at {st['at']}")
        elif st["type"] == "creep":
            lines.append(f"creep {st['direction']:<8} {math.dist(st['from'], st['to']) * 100:4.0f} cm straight "
                         f"(sideways station), to ({st['to'][0]:.3f}, {st['to'][1]:.3f})")
        else:
            length = sum(math.dist(p, q) for p, q in zip(st["points"][:-1], st["points"][1:]))
            lines.append(f"drive {st['direction']:<8} {length:5.2f} m  {' -> '.join(st['nodes'])}")
    return lines