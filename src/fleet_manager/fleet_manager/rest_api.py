#!/usr/bin/env python3
"""
REST API bridge between Robot Scheduler and the ROS path-planning action server.
"""

import argparse
import json
import sys
import threading
import time
from dataclasses import dataclass
from http import HTTPStatus
from http.server import BaseHTTPRequestHandler, ThreadingHTTPServer
from pathlib import Path
from typing import Any, Optional

import rclpy
import yaml
from action_msgs.msg import GoalStatus
from ament_index_python.packages import get_package_share_directory
from fleet_interfaces.action import ExecutePath
from rclpy.action import ActionClient
from rclpy.executors import MultiThreadedExecutor
from rclpy.node import Node


@dataclass
class MoveResult:
    success: bool
    path_id: int
    message: str
    status_code: int = HTTPStatus.OK
    action_status: Optional[int] = None

    def as_response(self, station_start: str, station_end: str) -> dict[str, Any]:
        response = {
            "success": self.success,
            "path_id": self.path_id,
            "message": self.message,
            "station_start": station_start,
            "station_end": station_end,
        }

        if self.action_status is not None:
            response["action_status"] = self.action_status

        return response


@dataclass
class RouteEntry:
    path_id: int
    enabled: bool = True
    reason: str = ""

    def as_response(self) -> dict[str, Any]:
        response = {
            "path_id": self.path_id,
            "enabled": self.enabled,
        }
        if self.reason:
            response["reason"] = self.reason
        return response


class RouteConfig:
    def __init__(self, action_name: str, default_timeout_s: float, routes: dict[str, dict[str, RouteEntry]]) -> None:
        self.action_name = action_name
        self.default_timeout_s = default_timeout_s
        self.routes = routes

    @classmethod
    def from_file(cls, path: str) -> "RouteConfig":
        config_path = Path(path).expanduser()
        with config_path.open("r", encoding="utf-8") as file:
            raw_config = yaml.safe_load(file) or {}

        action_name = str(raw_config.get("action_name", "/execute_path"))
        default_timeout_s = float(raw_config.get("default_timeout_s", 900))
        routes = cls._normalize_routes(raw_config.get("routes", {}))

        return cls(action_name=action_name, default_timeout_s=default_timeout_s, routes=routes)

    @staticmethod
    def _normalize_routes(raw_routes: dict[str, Any]) -> dict[str, dict[str, RouteEntry]]:
        routes: dict[str, dict[str, RouteEntry]] = {}

        for station_start, destinations in raw_routes.items():
            if not isinstance(destinations, dict):
                raise ValueError(f"Routes for '{station_start}' must be a mapping")

            start = str(station_start)
            routes[start] = {}

            for station_end, route_definition in destinations.items():
                if isinstance(route_definition, dict):
                    path_id = route_definition.get("path_id")
                    enabled = bool(route_definition.get("enabled", True))
                    reason = str(route_definition.get("reason", ""))
                else:
                    path_id = route_definition
                    enabled = True
                    reason = ""

                if path_id is None:
                    raise ValueError(f"Route '{station_start}' -> '{station_end}' is missing path_id")

                routes[start][str(station_end)] = RouteEntry(
                    path_id=int(path_id),
                    enabled=enabled,
                    reason=reason,
                )

        return routes

    def resolve_route(self, station_start: str, station_end: str) -> Optional[RouteEntry]:
        return self.routes.get(station_start, {}).get(station_end)

    def as_response(self) -> dict[str, Any]:
        return {
            "action_name": self.action_name,
            "default_timeout_s": self.default_timeout_s,
            "routes": {
                station_start: {
                    station_end: route.as_response()
                    for station_end, route in destinations.items()
                }
                for station_start, destinations in self.routes.items()
            },
        }


class MovementActionBridge(Node):
    def __init__(self, action_name: str) -> None:
        super().__init__("fleet_manager_rest_api")
        self.action_name = action_name
        self._client = ActionClient(self, ExecutePath, action_name)

    def action_server_available(self, timeout_s: float = 0.2) -> bool:
        return self._client.wait_for_server(timeout_sec=timeout_s)

    def execute_path(self, path_id: int, timeout_s: float) -> MoveResult:
        start = time.monotonic()

        if not self.action_server_available(timeout_s=5.0):
            return MoveResult(
                success=False,
                path_id=path_id,
                message=f"ROS action server '{self.action_name}' is not available",
                status_code=HTTPStatus.SERVICE_UNAVAILABLE,
            )

        goal = ExecutePath.Goal()
        goal.path_id = int(path_id)

        self.get_logger().info(f"Sending execute_path goal for path_id={path_id}")
        goal_future = self._client.send_goal_async(goal, feedback_callback=self._feedback_callback)

        if not self._wait_for_future(goal_future, self._remaining_timeout(start, timeout_s)):
            return MoveResult(
                success=False,
                path_id=path_id,
                message=f"Timed out while sending path {path_id}",
                status_code=HTTPStatus.GATEWAY_TIMEOUT,
            )

        try:
            goal_handle = goal_future.result()
        except Exception as exc:  # pylint: disable=broad-exception-caught
            return MoveResult(
                success=False,
                path_id=path_id,
                message=f"Failed to send path {path_id}: {exc}",
                status_code=HTTPStatus.INTERNAL_SERVER_ERROR,
            )

        if goal_handle is None or not goal_handle.accepted:
            return MoveResult(
                success=False,
                path_id=path_id,
                message=f"Path {path_id} was rejected by the action server",
                status_code=HTTPStatus.CONFLICT,
            )

        result_future = goal_handle.get_result_async()
        if not self._wait_for_future(result_future, self._remaining_timeout(start, timeout_s)):
            try:
                goal_handle.cancel_goal_async()
            except Exception:  # pylint: disable=broad-exception-caught
                pass

            return MoveResult(
                success=False,
                path_id=path_id,
                message=f"Timed out while executing path {path_id}",
                status_code=HTTPStatus.GATEWAY_TIMEOUT,
            )

        try:
            action_result = result_future.result()
        except Exception as exc:  # pylint: disable=broad-exception-caught
            return MoveResult(
                success=False,
                path_id=path_id,
                message=f"Failed while waiting for path {path_id}: {exc}",
                status_code=HTTPStatus.INTERNAL_SERVER_ERROR,
            )

        result = action_result.result
        status = action_result.status

        if status != GoalStatus.STATUS_SUCCEEDED or not result.success:
            message = result.message or f"Path {path_id} failed with action status {status}"
            return MoveResult(
                success=False,
                path_id=path_id,
                message=message,
                status_code=HTTPStatus.INTERNAL_SERVER_ERROR,
                action_status=status,
            )

        return MoveResult(
            success=True,
            path_id=result.path_id,
            message=result.message or f"Path {path_id} completed",
            status_code=HTTPStatus.OK,
            action_status=status,
        )

    @staticmethod
    def _remaining_timeout(start: float, timeout_s: float) -> float:
        return max(0.0, timeout_s - (time.monotonic() - start))

    @staticmethod
    def _wait_for_future(future, timeout_s: float) -> bool:
        if future.done():
            return True

        done = threading.Event()
        future.add_done_callback(lambda _: done.set())

        if future.done():
            return True

        return done.wait(timeout_s)

    def _feedback_callback(self, feedback_msg) -> None:
        feedback = feedback_msg.feedback
        self.get_logger().debug(
            f"path_id={feedback.path_id} state={feedback.state_label} distance={feedback.distance_to_goal:.3f}"
        )


class MovementRestService:
    def __init__(
        self,
        bridge: MovementActionBridge,
        routes: RouteConfig,
        stations: dict[str, Any],
        roads: dict[str, Any],
    ) -> None:
        self.bridge = bridge
        self.routes = routes
        self.stations = stations
        self.roads = roads
        self._move_lock = threading.Lock()

    def health(self) -> tuple[int, dict[str, Any]]:
        action_available = self.bridge.action_server_available()
        status_code = HTTPStatus.OK if action_available else HTTPStatus.SERVICE_UNAVAILABLE
        disabled_routes_count = sum(
            1
            for destinations in self.routes.routes.values()
            for route in destinations.values()
            if not route.enabled
        )
        return status_code, {
            "status": "ok" if action_available else "degraded",
            "action_name": self.routes.action_name,
            "action_server_available": action_available,
            "routes_count": sum(len(destinations) for destinations in self.routes.routes.values()),
            "disabled_routes_count": disabled_routes_count,
            "stations_count": len(self.stations.get("stations", {})),
            "road_segments_count": len(self.roads.get("segments", {})),
        }

    def station_config(self) -> dict[str, Any]:
        return self.stations

    def road_config(self) -> dict[str, Any]:
        return self.roads

    def move(self, payload: dict[str, Any]) -> tuple[int, dict[str, Any]]:
        station_start = str(payload.get("station_start", "")).strip()
        station_end = str(payload.get("station_end", "")).strip()

        if not station_start or not station_end:
            return HTTPStatus.UNPROCESSABLE_ENTITY, {
                "success": False,
                "message": "station_start and station_end are required",
            }

        route = self.routes.resolve_route(station_start, station_end)
        if route is None:
            return HTTPStatus.NOT_FOUND, {
                "success": False,
                "message": f"No route configured from '{station_start}' to '{station_end}'",
                "station_start": station_start,
                "station_end": station_end,
            }

        if not route.enabled:
            return HTTPStatus.CONFLICT, {
                "success": False,
                "message": route.reason or "Route is disabled",
                "station_start": station_start,
                "station_end": station_end,
                "path_id": route.path_id,
                "enabled": False,
            }

        if not self._move_lock.acquire(blocking=False):
            return HTTPStatus.CONFLICT, {
                "success": False,
                "message": "Robot is already executing a move",
                "station_start": station_start,
                "station_end": station_end,
                "path_id": route.path_id,
            }

        try:
            timeout_s = float(payload.get("timeout_s", self.routes.default_timeout_s))
            result = self.bridge.execute_path(path_id=route.path_id, timeout_s=timeout_s)
            return result.status_code, result.as_response(station_start, station_end)
        finally:
            self._move_lock.release()


def make_handler(service: MovementRestService):
    class FleetManagerRequestHandler(BaseHTTPRequestHandler):
        protocol_version = "HTTP/1.1"

        def do_OPTIONS(self) -> None:  # pylint: disable=invalid-name
            self._send_json(HTTPStatus.NO_CONTENT, None)

        def do_GET(self) -> None:  # pylint: disable=invalid-name
            path = self._normalized_path()

            if path == "/api/v1/health":
                status_code, body = service.health()
                self._send_json(status_code, body)
                return

            if path == "/api/v1/routes":
                self._send_json(HTTPStatus.OK, service.routes.as_response())
                return

            if path == "/api/v1/stations":
                self._send_json(HTTPStatus.OK, service.station_config())
                return

            if path == "/api/v1/roads":
                self._send_json(HTTPStatus.OK, service.road_config())
                return

            self._send_json(HTTPStatus.NOT_FOUND, {"message": f"Unknown endpoint: {path}"})

        def do_POST(self) -> None:  # pylint: disable=invalid-name
            path = self._normalized_path()

            if path != "/api/v1/moves":
                self._send_json(HTTPStatus.NOT_FOUND, {"message": f"Unknown endpoint: {path}"})
                return

            try:
                payload = self._read_json()
            except ValueError as exc:
                self._send_json(HTTPStatus.BAD_REQUEST, {"success": False, "message": str(exc)})
                return

            status_code, body = service.move(payload)
            self._send_json(status_code, body)

        def log_message(self, fmt: str, *args) -> None:
            service.bridge.get_logger().debug(fmt % args)

        def _normalized_path(self) -> str:
            return self.path.split("?", 1)[0].rstrip("/") or "/"

        def _read_json(self) -> dict[str, Any]:
            content_length = int(self.headers.get("Content-Length", "0"))
            if content_length <= 0:
                return {}

            raw_body = self.rfile.read(content_length)
            try:
                payload = json.loads(raw_body.decode("utf-8"))
            except json.JSONDecodeError as exc:
                raise ValueError(f"Invalid JSON body: {exc}") from exc

            if not isinstance(payload, dict):
                raise ValueError("JSON body must be an object")

            return payload

        def _send_json(self, status_code: int, body: Optional[dict[str, Any]]) -> None:
            if body is None:
                payload = b""
            else:
                payload = json.dumps(body).encode("utf-8")

            self.send_response(int(status_code))
            self.send_header("Access-Control-Allow-Origin", "*")
            self.send_header("Access-Control-Allow-Methods", "GET, POST, OPTIONS")
            self.send_header("Access-Control-Allow-Headers", "Content-Type, Authorization")
            self.send_header("Content-Type", "application/json")
            self.send_header("Content-Length", str(len(payload)))
            self.end_headers()

            if payload:
                self.wfile.write(payload)

    return FleetManagerRequestHandler


def default_config_path(file_name: str = "routes.yaml") -> Path:
    try:
        return Path(get_package_share_directory("fleet_manager")) / "config" / file_name
    except Exception:  # pylint: disable=broad-exception-caught
        return Path(__file__).resolve().parents[1] / "config" / file_name


def load_yaml_config(path: str) -> dict[str, Any]:
    config_path = Path(path).expanduser()
    with config_path.open("r", encoding="utf-8") as file:
        return yaml.safe_load(file) or {}


def parse_args(args: Optional[list[str]] = None) -> argparse.Namespace:
    parser = argparse.ArgumentParser(description="Fleet Manager REST API bridge")
    parser.add_argument("--config", default=str(default_config_path()), help="Route configuration YAML path")
    parser.add_argument(
        "--stations-config",
        default=str(default_config_path("stations.yaml")),
        help="Station geometry YAML path",
    )
    parser.add_argument(
        "--roads-config",
        default=str(default_config_path("roads.yaml")),
        help="Road geometry YAML path",
    )
    parser.add_argument("--host", default="0.0.0.0", help="REST bind address")
    parser.add_argument("--port", type=int, default=8000, help="REST bind port")
    parsed, _ = parser.parse_known_args(args)
    return parsed


def main(args: Optional[list[str]] = None) -> None:
    cli_args = sys.argv[1:] if args is None else args
    parsed_args = parse_args(cli_args)
    routes = RouteConfig.from_file(parsed_args.config)
    stations = load_yaml_config(parsed_args.stations_config)
    roads = load_yaml_config(parsed_args.roads_config)

    rclpy.init(args=cli_args)
    bridge = MovementActionBridge(routes.action_name)
    executor = MultiThreadedExecutor()
    executor.add_node(bridge)

    executor_thread = threading.Thread(target=executor.spin, daemon=True)
    executor_thread.start()

    service = MovementRestService(bridge=bridge, routes=routes, stations=stations, roads=roads)
    server = ThreadingHTTPServer((parsed_args.host, parsed_args.port), make_handler(service))

    bridge.get_logger().info(
        f"Fleet Manager REST API listening on http://{parsed_args.host}:{parsed_args.port}/api/v1"
    )
    bridge.get_logger().info(f"Loaded {sum(len(v) for v in routes.routes.values())} configured route(s)")
    bridge.get_logger().info(f"Loaded {len(stations.get('stations', {}))} station(s)")
    bridge.get_logger().info(f"Loaded {len(roads.get('segments', {}))} road segment(s)")

    try:
        server.serve_forever()
    except KeyboardInterrupt:
        bridge.get_logger().info("Stopping Fleet Manager REST API")
    finally:
        server.server_close()
        executor.shutdown()
        executor_thread.join(timeout=2)
        bridge.destroy_node()
        rclpy.shutdown()


if __name__ == "__main__":
    main()
