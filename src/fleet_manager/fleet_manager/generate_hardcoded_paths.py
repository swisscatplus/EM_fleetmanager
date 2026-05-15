#!/usr/bin/env python3
"""
Generate temporary hardcoded MPC paths from Fleet Manager station and track geometry.
"""

import argparse
import heapq
import math
from pathlib import Path
from typing import Any, Optional

import yaml
from ament_index_python.packages import get_package_share_directory


ROAD_WIDTH_M = 0.65
TRACK_LENGTH_M = 2.0
JUNCTION_TOLERANCE_M = 0.75
PATH_SAMPLE_SPACING_M = 1.0

Point = tuple[float, float]


def load_yaml(path: str) -> dict[str, Any]:
    with Path(path).expanduser().open("r", encoding="utf-8") as file:
        return yaml.safe_load(file) or {}


def write_yaml(path: str, data: dict[str, Any]) -> None:
    with Path(path).expanduser().open("w", encoding="utf-8") as file:
        yaml.safe_dump(data, file, sort_keys=False, allow_unicode=False)


def package_config_path(package: str, file_name: str) -> str:
    try:
        return str(Path(get_package_share_directory(package)) / "config" / file_name)
    except Exception:  # pylint: disable=broad-exception-caught
        return file_name


def local_config_path(file_name: str) -> str:
    return str(Path(__file__).resolve().parents[1] / "config" / file_name)


def round_point(point: Point) -> list[float]:
    return [round(point[0], 3), round(point[1], 3)]


def distance(a: Point, b: Point) -> float:
    return math.hypot(a[0] - b[0], a[1] - b[1])


def track_centerline(track: dict[str, Any], width_m: float = ROAD_WIDTH_M, length_m: float = TRACK_LENGTH_M) -> tuple[Point, Point]:
    x = float(track.get("t_x", 0.0))
    y = float(track.get("t_y", 0.0))
    yaw = float(track.get("yaw", 0.0))

    normal = (math.cos(yaw), math.sin(yaw))
    forward = (-math.sin(yaw), math.cos(yaw))
    start = (x + normal[0] * width_m / 2.0, y + normal[1] * width_m / 2.0)
    end = (start[0] + forward[0] * length_m, start[1] + forward[1] * length_m)
    return start, end


def marker_tracks(markers_config: dict[str, Any]) -> dict[str, tuple[Point, Point]]:
    tracks = (
        markers_config
        .get("fleet_manager", {})
        .get("ros__parameters", {})
        .get("tracks", {})
    )
    return {
        str(track_id): track_centerline(track)
        for track_id, track in tracks.items()
    }


def valid_station_pose(station: dict[str, Any]) -> Optional[tuple[float, float, float]]:
    pose = station.get("docking_pose", {})
    x = pose.get("x")
    y = pose.get("y")
    yaw = pose.get("yaw")
    if x is None or y is None or yaw is None:
        return None
    return float(x), float(y), float(yaw)


def project_point_to_segment(point: Point, a: Point, b: Point) -> tuple[Point, float]:
    ax, ay = a
    bx, by = b
    dx = bx - ax
    dy = by - ay
    length_sq = dx * dx + dy * dy
    if length_sq <= 1e-12:
        return a, distance(point, a)

    t = ((point[0] - ax) * dx + (point[1] - ay) * dy) / length_sq
    t = max(0.0, min(1.0, t))
    projection = (ax + t * dx, ay + t * dy)
    return projection, distance(point, projection)


def nearest_road_point(point: Point, segments: list[tuple[Point, Point]]) -> Point:
    best_point = segments[0][0]
    best_distance = math.inf
    for a, b in segments:
        projection, projection_distance = project_point_to_segment(point, a, b)
        if projection_distance < best_distance:
            best_point = projection
            best_distance = projection_distance
    return best_point


def key(point: Point) -> tuple[float, float]:
    return round(point[0], 4), round(point[1], 4)


def add_edge(graph: dict[tuple[float, float], dict[tuple[float, float], float]], a: Point, b: Point) -> None:
    ka = key(a)
    kb = key(b)
    graph.setdefault(ka, {})
    graph.setdefault(kb, {})
    edge_distance = distance(a, b)
    if edge_distance <= 1e-9:
        return
    graph[ka][kb] = min(graph[ka].get(kb, math.inf), edge_distance)
    graph[kb][ka] = min(graph[kb].get(ka, math.inf), edge_distance)


def build_graph(segments: list[tuple[Point, Point]], extra_points: list[Point]) -> dict[tuple[float, float], dict[tuple[float, float], float]]:
    graph: dict[tuple[float, float], dict[tuple[float, float], float]] = {}
    all_points: list[Point] = []

    for a, b in segments:
        add_edge(graph, a, b)
        all_points.extend([a, b])

    for point in extra_points:
        nearest = nearest_road_point(point, segments)
        add_edge(graph, point, nearest)
        all_points.append(point)
        for a, b in segments:
            projection, projection_distance = project_point_to_segment(point, a, b)
            if projection_distance < 1e-6:
                add_edge(graph, projection, a)
                add_edge(graph, projection, b)
                all_points.append(projection)

    keyed_points = [key(point) for point in all_points]
    for index, a in enumerate(keyed_points):
        for b in keyed_points[index + 1:]:
            if distance(a, b) <= JUNCTION_TOLERANCE_M:
                add_edge(graph, a, b)

    return graph


def shortest_path(graph: dict[tuple[float, float], dict[tuple[float, float], float]], start: Point, end: Point) -> list[Point]:
    start_key = key(start)
    end_key = key(end)
    queue: list[tuple[float, tuple[float, float]]] = [(0.0, start_key)]
    previous: dict[tuple[float, float], Optional[tuple[float, float]]] = {start_key: None}
    distances: dict[tuple[float, float], float] = {start_key: 0.0}

    while queue:
        current_distance, current = heapq.heappop(queue)
        if current == end_key:
            break
        if current_distance > distances.get(current, math.inf):
            continue

        for neighbor, edge_distance in graph.get(current, {}).items():
            next_distance = current_distance + edge_distance
            if next_distance < distances.get(neighbor, math.inf):
                distances[neighbor] = next_distance
                previous[neighbor] = current
                heapq.heappush(queue, (next_distance, neighbor))

    if end_key not in previous:
        raise RuntimeError(f"No road graph path from {start} to {end}")

    path = []
    current: Optional[tuple[float, float]] = end_key
    while current is not None:
        path.append((current[0], current[1]))
        current = previous[current]
    return list(reversed(path))


def dedupe_points(points: list[Point]) -> list[Point]:
    deduped: list[Point] = []
    for point in points:
        if not deduped or distance(deduped[-1], point) > 1e-6:
            deduped.append(point)
    return deduped


def densify_points(points: list[Point], spacing_m: float = PATH_SAMPLE_SPACING_M) -> list[Point]:
    points = dedupe_points(points)
    if spacing_m <= 0:
        return points

    dense = [points[0]]
    for a, b in zip(points[:-1], points[1:]):
        segment_distance = distance(a, b)
        if segment_distance <= 1e-9:
            continue
        steps = int(segment_distance // spacing_m)
        for step in range(1, steps + 1):
            ratio = min(1.0, step * spacing_m / segment_distance)
            dense.append((a[0] + (b[0] - a[0]) * ratio, a[1] + (b[1] - a[1]) * ratio))
        dense.append(b)
    return dedupe_points(dense)


def simplify_collinear(points: list[Point]) -> list[Point]:
    points = dedupe_points(points)
    if len(points) < 3:
        return points

    simplified = [points[0]]
    for index, point in enumerate(points[1:-1], start=1):
        previous = simplified[-1]
        following = points[index + 1]
        ab = (point[0] - previous[0], point[1] - previous[1])
        bc = (following[0] - point[0], following[1] - point[1])
        cross = abs(ab[0] * bc[1] - ab[1] * bc[0])
        if cross <= 1e-6:
            continue
        simplified.append(point)

    simplified.append(points[-1])
    return simplified


def direction_for_path(points: list[Point], start_yaw: float) -> str:
    if len(points) < 2:
        return "forward"

    start = points[0]
    first_motion = next((point for point in points[1:] if distance(start, point) > 0.05), None)
    if first_motion is None:
        return "forward"

    heading = (math.cos(start_yaw), math.sin(start_yaw))
    motion = (first_motion[0] - start[0], first_motion[1] - start[1])
    return "forward" if heading[0] * motion[0] + heading[1] * motion[1] >= 0.0 else "backward"


def generated_path(start_pose: tuple[float, float, float], end_pose: tuple[float, float, float], segments: list[tuple[Point, Point]]) -> list[Point]:
    start_point = (start_pose[0], start_pose[1])
    end_point = (end_pose[0], end_pose[1])
    start_road = nearest_road_point(start_point, segments)
    end_road = nearest_road_point(end_point, segments)
    graph = build_graph(segments, [start_road, end_road])
    centerline_path = shortest_path(graph, start_road, end_road)
    return densify_points(simplify_collinear([start_point, *centerline_path, end_point]))


def routes_to_generate(routes_config: dict[str, Any], station_poses: dict[str, tuple[float, float, float]]) -> list[tuple[str, str, int]]:
    routes = []
    for station_start, destinations in (routes_config.get("routes") or {}).items():
        if station_start not in station_poses:
            continue
        for station_end, route in destinations.items():
            if station_end not in station_poses:
                continue
            path_id = route.get("path_id") if isinstance(route, dict) else route
            if path_id is not None:
                routes.append((station_start, station_end, int(path_id)))
    return routes


def generate_paths(markers_config: dict[str, Any], stations_config: dict[str, Any], routes_config: dict[str, Any]) -> dict[int, dict[str, Any]]:
    segments = list(marker_tracks(markers_config).values())
    stations = stations_config.get("stations") or {}
    station_poses = {
        station_name: pose
        for station_name, station in stations.items()
        if (pose := valid_station_pose(station)) is not None
    }

    generated: dict[int, dict[str, Any]] = {}
    for station_start, station_end, path_id in routes_to_generate(routes_config, station_poses):
        start_pose = station_poses[station_start]
        end_pose = station_poses[station_end]
        points = generated_path(start_pose, end_pose, segments)
        generated[path_id] = {
            "direction": direction_for_path(points, start_pose[2]),
            "generated_from": {
                "station_start": station_start,
                "station_end": station_end,
            },
            "points": [round_point(point) for point in points],
        }

    return generated


def main() -> None:
    parser = argparse.ArgumentParser(description="Generate hardcoded MPC paths from Fleet Manager geometry")
    parser.add_argument("--markers-config", default=local_config_path("markers.yaml"))
    parser.add_argument("--stations-config", default=local_config_path("stations.yaml"))
    parser.add_argument("--routes-config", default=local_config_path("routes.yaml"))
    parser.add_argument("--paths-config", default=package_config_path("tracker", "paths.yaml"))
    parser.add_argument("--dry-run", action="store_true")
    args = parser.parse_args()

    markers_config = load_yaml(args.markers_config)
    stations_config = load_yaml(args.stations_config)
    routes_config = load_yaml(args.routes_config)
    paths_config = load_yaml(args.paths_config)

    generated = generate_paths(markers_config, stations_config, routes_config)
    paths = paths_config.setdefault("paths", {})
    written_count = 0
    for path_id, path in generated.items():
        existing_path = paths.get(path_id) or paths.get(str(path_id))
        if isinstance(existing_path, dict) and existing_path.get("locked", False):
            continue
        paths[int(path_id)] = path
        written_count += 1

    if args.dry_run:
        print(yaml.safe_dump({"paths": generated}, sort_keys=False))
        return

    write_yaml(args.paths_config, paths_config)
    skipped_count = len(generated) - written_count
    print(f"Generated {written_count} path(s) into {args.paths_config}; skipped {skipped_count} locked path(s)")


if __name__ == "__main__":
    main()
