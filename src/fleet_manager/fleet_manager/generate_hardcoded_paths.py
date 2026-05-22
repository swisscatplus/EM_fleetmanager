#!/usr/bin/env python3
"""
Generate station-to-station MPC paths from a named POI road graph.
"""

import argparse
import heapq
import math
from pathlib import Path
from typing import Any, Optional

import yaml

try:
    from ament_index_python.packages import get_package_share_directory
except Exception:  # pylint: disable=broad-exception-caught
    get_package_share_directory = None


PATH_SAMPLE_SPACING_M = 1.0
CORNER_INSET_M = 0.4
MIN_CORNER_ANGLE_DEG = 20.0
KEY_PRECISION = 4

Point = tuple[float, float]
Graph = dict[tuple[float, float], dict[tuple[float, float], float]]


def load_yaml(path: str) -> dict[str, Any]:
    with Path(path).expanduser().open("r", encoding="utf-8") as file:
        return yaml.safe_load(file) or {}


def write_yaml(path: str, data: dict[str, Any]) -> None:
    with Path(path).expanduser().open("w", encoding="utf-8") as file:
        yaml.safe_dump(data, file, sort_keys=False, allow_unicode=False)


def package_config_path(package: str, file_name: str) -> str:
    try:
        if get_package_share_directory is None:
            raise RuntimeError("ament index unavailable")
        return str(Path(get_package_share_directory(package)) / "config" / file_name)
    except Exception:  # pylint: disable=broad-exception-caught
        return file_name


def local_config_path(file_name: str) -> str:
    return str(Path(__file__).resolve().parents[1] / "config" / file_name)


def round_point(point: Point) -> list[float]:
    return [round(point[0], 3), round(point[1], 3)]


def distance(a: Point, b: Point) -> float:
    return math.hypot(a[0] - b[0], a[1] - b[1])


def key(point: Point) -> tuple[float, float]:
    return (round(point[0], KEY_PRECISION), round(point[1], KEY_PRECISION))


def unkey(point_key: tuple[float, float]) -> Point:
    return (point_key[0], point_key[1])


def add_edge(graph: Graph, a: Point, b: Point) -> None:
    edge_distance = distance(a, b)
    if edge_distance <= 1e-9:
        return

    ka = key(a)
    kb = key(b)
    graph.setdefault(ka, {})
    graph.setdefault(kb, {})
    graph[ka][kb] = min(graph[ka].get(kb, math.inf), edge_distance)
    graph[kb][ka] = min(graph[kb].get(ka, math.inf), edge_distance)


def remove_edge(graph: Graph, a: Point, b: Point) -> None:
    ka = key(a)
    kb = key(b)
    graph.get(ka, {}).pop(kb, None)
    graph.get(kb, {}).pop(ka, None)


def project_point_to_segment(point: Point, a: Point, b: Point) -> tuple[Point, float, float]:
    ax, ay = a
    bx, by = b
    dx = bx - ax
    dy = by - ay
    length_sq = dx * dx + dy * dy
    if length_sq <= 1e-12:
        return a, distance(point, a), 0.0

    t = ((point[0] - ax) * dx + (point[1] - ay) * dy) / length_sq
    t = max(0.0, min(1.0, t))
    projection = (ax + t * dx, ay + t * dy)
    return projection, distance(point, projection), t


def dedupe_points(points: list[Point], epsilon: float = 1e-6) -> list[Point]:
    deduped: list[Point] = []
    for point in points:
        if not deduped or distance(deduped[-1], point) > epsilon:
            deduped.append(point)
    return deduped


def vector(a: Point, b: Point) -> Point:
    return (b[0] - a[0], b[1] - a[1])


def norm(vec: Point) -> float:
    return math.hypot(vec[0], vec[1])


def unit(vec: Point) -> Point:
    magnitude = norm(vec)
    if magnitude <= 1e-9:
        return (0.0, 0.0)
    return (vec[0] / magnitude, vec[1] / magnitude)


def scale(vec: Point, factor: float) -> Point:
    return (vec[0] * factor, vec[1] * factor)


def add(a: Point, b: Point) -> Point:
    return (a[0] + b[0], a[1] + b[1])


def subtract(a: Point, b: Point) -> Point:
    return (a[0] - b[0], a[1] - b[1])


def dot(a: Point, b: Point) -> float:
    return a[0] * b[0] + a[1] * b[1]


def quadratic_bezier(a: Point, b: Point, c: Point, t: float) -> Point:
    omt = 1.0 - t
    return (
        omt * omt * a[0] + 2.0 * omt * t * b[0] + t * t * c[0],
        omt * omt * a[1] + 2.0 * omt * t * b[1] + t * t * c[1],
    )


def corner_angle_deg(previous: Point, current: Point, following: Point) -> float:
    incoming = unit(vector(current, previous))
    outgoing = unit(vector(current, following))
    if norm(incoming) <= 1e-9 or norm(outgoing) <= 1e-9:
        return 0.0
    value = max(-1.0, min(1.0, dot(incoming, outgoing)))
    return math.degrees(math.acos(value))


def smooth_polyline(points: list[Point], corner_inset_m: float = CORNER_INSET_M) -> list[Point]:
    points = dedupe_points(points)
    if len(points) < 3:
        return points

    smoothed = [points[0]]
    for previous, current, following in zip(points[:-2], points[1:-1], points[2:]):
        len_in = distance(previous, current)
        len_out = distance(current, following)
        turn_angle = corner_angle_deg(previous, current, following)

        if min(len_in, len_out) <= 1e-6 or turn_angle < MIN_CORNER_ANGLE_DEG or abs(turn_angle - 180.0) < 1.0:
            smoothed.append(current)
            continue

        inset = min(corner_inset_m, len_in * 0.35, len_out * 0.35)
        if inset <= 1e-3:
            smoothed.append(current)
            continue

        incoming_dir = unit(vector(previous, current))
        outgoing_dir = unit(vector(current, following))
        before_corner = subtract(current, scale(incoming_dir, inset))
        after_corner = add(current, scale(outgoing_dir, inset))

        smoothed.append(before_corner)
        for step in (0.33, 0.66):
            smoothed.append(quadratic_bezier(before_corner, current, after_corner, step))
        smoothed.append(after_corner)

    smoothed.append(points[-1])
    return dedupe_points(smoothed)


def densify_points(points: list[Point], spacing_m: float = PATH_SAMPLE_SPACING_M) -> list[Point]:
    points = dedupe_points(points)
    if len(points) < 2 or spacing_m <= 0:
        return points

    dense = [points[0]]
    for start, end in zip(points[:-1], points[1:]):
        segment_length = distance(start, end)
        if segment_length <= 1e-9:
            continue
        step_count = int(segment_length // spacing_m)
        direction = unit(vector(start, end))
        for index in range(1, step_count + 1):
            travel = index * spacing_m
            if travel >= segment_length:
                break
            dense.append(add(start, scale(direction, travel)))
        dense.append(end)
    return dedupe_points(dense)


def valid_station_pose(station: dict[str, Any]) -> Optional[tuple[float, float, float]]:
    pose = station.get("docking_pose", {})
    x = pose.get("x")
    y = pose.get("y")
    yaw = pose.get("yaw")
    if x is None or y is None or yaw is None:
        return None
    return (float(x), float(y), float(yaw))


def flatten_pois(poi_config: dict[str, Any]) -> dict[str, Point]:
    named_points: dict[str, Point] = {}
    for group_points in (poi_config.get("points_of_interest") or {}).values():
        for name, point in (group_points or {}).items():
            named_points[str(name)] = (float(point[0]), float(point[1]))
    return named_points


def road_edges(poi_config: dict[str, Any], named_points: dict[str, Point]) -> list[tuple[str, str, Point, Point]]:
    edges = []
    for index, edge in enumerate((poi_config.get("road_graph") or {}).get("edges", []), start=1):
        if not isinstance(edge, list) or len(edge) != 2:
            raise RuntimeError(f"Invalid road_graph edge #{index}: {edge}")
        start_name, end_name = str(edge[0]), str(edge[1])
        if start_name not in named_points or end_name not in named_points:
            raise RuntimeError(f"Unknown POI in edge #{index}: {edge}")
        edges.append((start_name, end_name, named_points[start_name], named_points[end_name]))
    return edges


def base_graph(edges: list[tuple[str, str, Point, Point]]) -> Graph:
    graph: Graph = {}
    for _, _, start, end in edges:
        add_edge(graph, start, end)
    return graph


def station_attachment(
    station_name: str,
    station_pose: tuple[float, float, float],
    edges: list[tuple[str, str, Point, Point]],
) -> dict[str, Any]:
    station_point = (station_pose[0], station_pose[1])
    best_distance = math.inf
    best_attachment: Optional[dict[str, Any]] = None

    for start_name, end_name, start, end in edges:
        projection, candidate_distance, t = project_point_to_segment(station_point, start, end)
        if candidate_distance < best_distance:
            best_distance = candidate_distance
            best_attachment = {
                "station_name": station_name,
                "station_point": station_point,
                "edge_start_name": start_name,
                "edge_end_name": end_name,
                "edge_start": start,
                "edge_end": end,
                "projection": projection,
                "projection_t": t,
                "distance_to_road": candidate_distance,
            }

    if best_attachment is None:
        raise RuntimeError(f"Could not attach station '{station_name}' to the road graph")
    return best_attachment


def graph_with_attachments(graph: Graph, attachments: list[dict[str, Any]]) -> Graph:
    attached_graph: Graph = {node: neighbors.copy() for node, neighbors in graph.items()}
    processed_edges: set[tuple[tuple[float, float], tuple[float, float]]] = set()

    grouped: dict[tuple[tuple[float, float], tuple[float, float]], list[dict[str, Any]]] = {}
    for attachment in attachments:
        edge_key = tuple(sorted((key(attachment["edge_start"]), key(attachment["edge_end"]))))
        grouped.setdefault(edge_key, []).append(attachment)

    for edge_key, edge_attachments in grouped.items():
        start_key, end_key = edge_key
        start_point = unkey(start_key)
        end_point = unkey(end_key)
        if edge_key not in processed_edges:
            remove_edge(attached_graph, start_point, end_point)
            processed_edges.add(edge_key)

        points_on_edge = [start_point]
        for attachment in edge_attachments:
            points_on_edge.append(attachment["projection"])
        points_on_edge.append(end_point)

        start_to_end = vector(start_point, end_point)
        length_sq = dot(start_to_end, start_to_end)
        if length_sq <= 1e-12:
            continue

        points_on_edge.sort(
            key=lambda point: dot(subtract(point, start_point), start_to_end) / length_sq
        )
        ordered_points = dedupe_points(points_on_edge, epsilon=1e-4)
        for a, b in zip(ordered_points[:-1], ordered_points[1:]):
            add_edge(attached_graph, a, b)

    return attached_graph


def shortest_path(graph: Graph, start: Point, end: Point) -> list[Point]:
    start_key = key(start)
    end_key = key(end)
    queue: list[tuple[float, tuple[float, float]]] = [(0.0, start_key)]
    previous: dict[tuple[float, float], Optional[tuple[float, float]]] = {start_key: None}
    distances: dict[tuple[float, float], float] = {start_key: 0.0}

    while queue:
        current_distance, current_key = heapq.heappop(queue)
        if current_key == end_key:
            break
        if current_distance > distances.get(current_key, math.inf):
            continue

        for neighbor_key, edge_distance in graph.get(current_key, {}).items():
            next_distance = current_distance + edge_distance
            if next_distance < distances.get(neighbor_key, math.inf):
                distances[neighbor_key] = next_distance
                previous[neighbor_key] = current_key
                heapq.heappush(queue, (next_distance, neighbor_key))

    if end_key not in previous:
        raise RuntimeError(f"No graph path between {start} and {end}")

    path: list[Point] = []
    current_key: Optional[tuple[float, float]] = end_key
    while current_key is not None:
        path.append(unkey(current_key))
        current_key = previous[current_key]
    return list(reversed(path))


def direction_for_path(points: list[Point], start_yaw: float) -> str:
    if len(points) < 2:
        return "forward"

    start = points[0]
    first_motion = next((point for point in points[1:] if distance(start, point) > 0.05), None)
    if first_motion is None:
        return "forward"

    heading = (math.cos(start_yaw), math.sin(start_yaw))
    motion = vector(start, first_motion)
    return "forward" if dot(heading, motion) >= 0.0 else "backward"


def routes_to_generate(
    routes_config: dict[str, Any],
    station_poses: dict[str, tuple[float, float, float]],
) -> list[tuple[str, str, int]]:
    routes = []
    for station_start, destinations in (routes_config.get("routes") or {}).items():
        if station_start not in station_poses:
            continue
        if not isinstance(destinations, dict):
            continue
        for station_end, route in destinations.items():
            if station_end not in station_poses:
                continue
            path_id = route.get("path_id") if isinstance(route, dict) else route
            if path_id is None:
                continue
            routes.append((str(station_start), str(station_end), int(path_id)))
    return routes


def generate_station_path(
    start_name: str,
    start_pose: tuple[float, float, float],
    end_name: str,
    end_pose: tuple[float, float, float],
    base_road_graph: Graph,
    road_graph_edges: list[tuple[str, str, Point, Point]],
) -> dict[str, Any]:
    start_attachment = station_attachment(start_name, start_pose, road_graph_edges)
    end_attachment = station_attachment(end_name, end_pose, road_graph_edges)
    routed_graph = graph_with_attachments(base_road_graph, [start_attachment, end_attachment])
    centerline = shortest_path(routed_graph, start_attachment["projection"], end_attachment["projection"])

    raw_points = [start_attachment["station_point"], *centerline, end_attachment["station_point"]]
    smoothed = smooth_polyline(raw_points)
    dense = densify_points(smoothed)

    return {
        "direction": direction_for_path(dense, start_pose[2]),
        "generated_from": {
            "station_start": start_name,
            "station_end": end_name,
            "generator": "poi_graph_v2",
        },
        "points": [round_point(point) for point in dense],
    }


def generate_paths(
    poi_config: dict[str, Any],
    stations_config: dict[str, Any],
    routes_config: dict[str, Any],
) -> dict[int, dict[str, Any]]:
    stations = stations_config.get("stations") or {}
    station_poses = {
        station_name: pose
        for station_name, station in stations.items()
        if (pose := valid_station_pose(station)) is not None
    }

    named_points = flatten_pois(poi_config)
    graph_edges = road_edges(poi_config, named_points)
    road_graph = base_graph(graph_edges)

    generated: dict[int, dict[str, Any]] = {}
    for station_start, station_end, path_id in routes_to_generate(routes_config, station_poses):
        generated[path_id] = generate_station_path(
            station_start,
            station_poses[station_start],
            station_end,
            station_poses[station_end],
            road_graph,
            graph_edges,
        )

    return generated


def should_overwrite(existing_path: Any) -> bool:
    if not isinstance(existing_path, dict):
        return True
    if existing_path.get("generated_from"):
        return True
    return not bool(existing_path.get("locked", False))


def main() -> None:
    parser = argparse.ArgumentParser(description="Generate station-to-station MPC paths from the POI graph")
    parser.add_argument("--stations-config", default=local_config_path("stations.yaml"))
    parser.add_argument("--routes-config", default=local_config_path("routes.yaml"))
    parser.add_argument("--poi-config", default=package_config_path("tracker", "map_pois.yaml"))
    parser.add_argument("--paths-config", default=package_config_path("tracker", "paths.yaml"))
    parser.add_argument("--dry-run", action="store_true")
    args = parser.parse_args()

    poi_config = load_yaml(args.poi_config)
    stations_config = load_yaml(args.stations_config)
    routes_config = load_yaml(args.routes_config)
    paths_config = load_yaml(args.paths_config)

    generated = generate_paths(poi_config, stations_config, routes_config)
    if args.dry_run:
        print(yaml.safe_dump({"paths": generated}, sort_keys=False))
        return

    paths = paths_config.setdefault("paths", {})
    written_count = 0
    skipped_count = 0
    for path_id, path in generated.items():
        existing_path = paths.get(path_id) or paths.get(str(path_id))
        if not should_overwrite(existing_path):
            skipped_count += 1
            continue
        paths[int(path_id)] = path
        written_count += 1

    write_yaml(args.paths_config, paths_config)
    print(
        f"Generated {written_count} station path(s) into {args.paths_config}; "
        f"skipped {skipped_count} locked manual path(s)"
    )


if __name__ == "__main__":
    main()
