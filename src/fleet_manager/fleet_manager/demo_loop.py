"""
demo_loop.py  -  DEMO DAY: the robot drives from station to station, again and again.

Put this file in the SAME folder as path_sender.py and path_planner.py
(/ros2_ws/src/fleet_manager/fleet_manager in the container), then run:

    python3 demo_loop.py --ros-args -p robot:=robot1
    python3 demo_loop.py --ros-args -p robot:=robot1 -p stations:="LC MS,Chemspeed SwingSP" -p pause:=10.0

Parameters (-p name:=value):
    stations      the tour, in order, comma separated
                  (default: LC MS, PrepFire, Chemspeed SwingSP, OmniFire, Battery)
                  SFC QTOF is left out on purpose. After the last station it starts again at the first.
                  Stations still null in stations.yaml are skipped automatically (warning printed).
                  Tip: "LC MS,Chemspeed SwingSP,Battery,Chemspeed SwingSP" = back and forth
    pause         seconds to wait at each station (like the arm picking the plate)  default 5
    laps          number of full tours, 0 = forever (until Ctrl+C)                  default 0
    max_failures  trips in a row that may fail before the demo stops by itself     default 2

How it works:
    It re-uses PathSender (path_sender.py) for every trip, so each trip works exactly like
    `python3 path_sender.py -p goal:=...`: plan from where the robot really is, turn if needed,
    send the legs to the tracker, wait until arrived.
    Between trips:  check the robot really is at the station -> wait `pause` s -> next station.
    If a trip fails, it waits a bit and tries the SAME station again (planning from the real pose).
    After `max_failures` failures in a row it stops the robot and quits: a human should look.

Ctrl+C = stops the robot (like path_sender) and prints the demo statistics.
Emergency stop is still Ctrl+C in the up_stack terminal.
"""

import math
import time

import rclpy
from nav_msgs.msg import Path

from path_sender import PathSender, wrap

DEFAULT_STATIONS = "LC MS,PrepFire,Chemspeed SwingSP,OmniFire,Battery" #sfc qtof excluded as its still doesnt work well yet
AT_STATION_DIST = 0.15   # m: robot this close to the docking point = trip OK
AT_STATION_YAW = 0.3     # rad (~17 deg)
RETRY_WAIT = 3.0         # s to wait before trying a failed trip again


def reset_for_trip(node, goal):
    """put the PathSender back in its starting state, with a new goal"""
    node.goal = goal
    node.state = "plan"
    node.done = False
    node.n_plans = 0
    node.steps, node.step = [], None
    node.step_start = node.settle_until = 0.0
    node.final_turn = False
    node.still_pose, node.still_since = None, 0.0
    node.final_points, node.errors = [], []
    node.last_log = 0.0
    node.driven = Path()                        # new trail in RViz for each trip
    node.driven.header.frame_id = "map"


def at_station(node, goal):
    """True if the robot really is at the station (position AND heading)"""
    pose = node.robot_pose()
    if pose is None:
        return False
    gx, gy, gyaw = node.planner.stations[goal]
    return math.dist(pose[:2], (gx, gy)) < AT_STATION_DIST and abs(wrap(pose[2] - gyaw)) < AT_STATION_YAW


def spin_for(node, seconds):
    """wait, but keep ROS running (TF keeps arriving)"""
    end = time.monotonic() + seconds
    while rclpy.ok() and time.monotonic() < end:
        rclpy.spin_once(node, timeout_sec=0.1)


def main():
    # handle Ctrl+C ourselves, so ROS is still running when we send the stop (same as path_sender)
    try:
        from rclpy.signals import SignalHandlerOptions
        rclpy.init(signal_handler_options=SignalHandlerOptions.NO)
    except (ImportError, TypeError):
        rclpy.init()

    node = PathSender()
    tour = [s.strip() for s in node.declare_parameter("stations", DEFAULT_STATIONS).value.split(",") if s.strip()]
    pause = float(node.declare_parameter("pause", 5.0).value)
    laps = int(node.declare_parameter("laps", 0).value)
    max_failures = int(node.declare_parameter("max_failures", 2).value)
    log = node.get_logger()

    # stations without a docking pose yet (null in stations.yaml) are skipped, with a warning
    for s in [s for s in tour if s in node.planner.skipped]:
        log.warn(f"'{s}' has no docking pose in stations.yaml yet -> left out of the tour")
    tour = [s for s in tour if s not in node.planner.skipped]
    unknown = [s for s in tour if s not in node.planner.stations]
    if unknown or len(tour) < 2:
        log.error(f"bad tour {tour} (unknown: {unknown}). Known stations: {', '.join(node.planner.stations)}")
        node.destroy_node()
        rclpy.shutdown()
        return

    log.info(f"DEMO tour: {' -> '.join(tour)} -> ...   pause {pause:.0f} s, "
             f"laps {'forever' if laps == 0 else laps}")

    ok_trips, failed_trips, failures_in_a_row = 0, 0, 0
    t_start = time.monotonic()
    i = 0
    interrupted = False
    try:
        while rclpy.ok():
            if laps and i >= laps * len(tour):
                log.info("all laps done")
                break
            goal = tour[i % len(tour)]
            log.info(f"===== trip {i + 1}: -> {goal}  (lap {i // len(tour) + 1}) =====")

            # one trip = one PathSender run
            reset_for_trip(node, goal)
            t_trip = time.monotonic()
            while rclpy.ok() and not node.done:
                rclpy.spin_once(node, timeout_sec=0.1)
            node.summary()

            spin_for(node, 0.5)                        # let TF catch up before checking
            if at_station(node, goal):
                ok_trips += 1
                failures_in_a_row = 0
                log.info(f"OK at {goal} in {time.monotonic() - t_trip:.0f} s   "
                         f"(total: {ok_trips} OK, {failed_trips} failed)")
                spin_for(node, pause)
                i += 1                                 # next station
            else:
                failed_trips += 1
                failures_in_a_row += 1
                node.stop_everything()
                node.clear_tracker()
                log.warn(f"trip to {goal} FAILED ({failures_in_a_row} in a row)")
                if failures_in_a_row >= max_failures:
                    log.error("too many failures in a row: robot stopped, demo ended. "
                              "Check the robot (localization? stuck?), then start demo_loop again.")
                    break
                log.info(f"trying {goal} again in {RETRY_WAIT:.0f} s")
                spin_for(node, RETRY_WAIT)             # same i -> same station again
    except KeyboardInterrupt:
        interrupted = True
    finally:
        if interrupted:
            try:
                node.stop_everything()
                rclpy.spin_once(node, timeout_sec=0.2)  # let the stop message go out
                log.warn("Ctrl+C: robot stopped")
            except Exception as e:
                print("could not send the stop:", e, "-> stop the robot from the up_stack terminal")
        minutes = (time.monotonic() - t_start) / 60
        print("\n========== demo statistics ==========")
        print(f"running time : {minutes:.1f} min")
        print(f"trips OK     : {ok_trips}")
        print(f"trips failed : {failed_trips}")
        print("=====================================")
        node.destroy_node()
        if rclpy.ok():
            rclpy.shutdown()


if __name__ == "__main__":
    main()