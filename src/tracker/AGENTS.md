# AGENTS.md

This file is for future Codex sessions working in `EM_fleetmanager/src/tracker`.

## Scope

This package contains:

- ROS 2 tracker nodes that convert a `Path2D` path into `cmd_vel`
- A shared MPC helper used by both tracker variants
- Path publishing / path workflow helpers
- Planner code and map/path config used by tracker demos and multi-robot launch

Primary package root:

- `/home/edy/Documents/GitHub/EM_fleetmanager/src/tracker`

Python package root:

- `/home/edy/Documents/GitHub/EM_fleetmanager/src/tracker/tracker`

## Important Entry Points

Defined in `setup.py`:

- `tracker = tracker.tracker_mpc:main`
- `tracker_v2 = tracker.tracker_mpc_v2:main`
- `planner = tracker.planner:main`
- `planner_v2 = tracker.planner_v2:main`
- `publish_path = tracker.publish_path:main`
- `publish_path_loop = tracker.publish_path_loop:main`
- `publish_path_loop_manual = tracker.publish_path_loop_manual:main`

Shared MPC implementation:

- `tracker/helper_classes/mpc_tracker_theta.py`

Path segmentation utilities:

- `tracker/helper_classes/segment.py`

Path registry / YAML loaders:

- `tracker/path_registry.py`

## Which Tracker Variant Is Likely Active

There are two tracker node implementations:

- `tracker/tracker_mpc.py`
- `tracker/tracker_mpc_v2.py`

Current launch behavior:

- `launch/tracker.launch.py` starts `executable='tracker'` which maps to `tracker_mpc.py`
- `launch/tracker_v2.launch.py` starts `executable='tracker_v2'` which maps to `tracker_mpc_v2.py`

When investigating robot behavior, confirm which launch file or executable is actually used in deployment before changing MPC logic.

## Functional Differences Between Variants

`tracker_mpc.py`:

- Runs at 8 Hz
- Supports both topic-driven paths and `ExecutePath` action goals
- Uses the MPC helper goal check directly
- Can stop as soon as goal position is reached unless `require_final_heading` is enabled

`tracker_mpc_v2.py`:

- Runs at 20 Hz
- Uses an explicit node-level mode machine: `TRACK`, `FINAL_SPIN`, `DONE`
- Adds hysteresis, debounce, and output smoothing near the goal
- Subscribes to `path` only; no action server

If the complaint is "bad behavior near the goal", "oscillation", or "keeps turning / not finishing", inspect both the MPC helper and the node wrapper because the wrapper changes completion behavior a lot.

## MPC Implementation Notes

The optimization itself lives in `helper_classes/mpc_tracker_theta.py`.

Key facts:

- Horizon: `N = 5`
- Sample time: `dt = 0.125`
- Linear speed limit: `v_max = 0.15`
- Angular speed limit: `omega_max = 1.0`
- Uses `cvxpy` with `OSQP`
- Tracks a spatial reference path, not a time-parameterized trajectory
- Progress along the path is tracked by a scalar `s`
- Final heading is derived from the last segment direction, not from an explicit final pose heading

Important limitation:

- The model predicts `x` and `y` using the reference heading, not the robot's predicted heading state
- `theta` is modeled as heading error only
- This keeps the problem convex and cheap, but it is a simplified model and can mismatch real robot behavior during strong turns, reversals, or slip

## Path Semantics

Incoming paths are converted into `Segment` objects:

- each segment is a straight line between consecutive `Pose2D` points
- direction is inferred from `Pose2D.direction_flag`
- only forward and backward are used in `segment.py`

Reference generation in the MPC helper:

- finds the nearest point on the remaining path
- updates progress variable `s`
- samples forward along the path using `nominal_dl = dt * nominal_speed`
- builds `N+1` reference points
- derives reference heading from segment geometry and direction

This means tracking quality is very sensitive to:

- waypoint spacing
- path sharpness
- direction changes
- mismatch between control loop timing and `dt`

## Real-Robot Investigation Checklist

Before changing weights, verify:

- which executable is actually running: `tracker` or `tracker_v2`
- actual control loop rate on robot versus assumed MPC `dt`
- TF frame names and latency
- waypoint density from `paths.yaml` or planner output
- whether the robot drivetrain can realize sign changes in `v`
- whether goal completion is intended to be position-only or position-plus-heading

Also inspect:

- `goal_radius`
- `goal_progress_threshold`
- `goal_angle_tol`
- rate limits `delta_v_max` and `delta_omega_max`
- the "kick" fallback when optimized `v` is near zero

## Known Code Risks To Keep In Mind

`tracker_mpc_v2.py` currently reads `self.robot_name` before declaring / assigning the `robot_name` parameter. If `base_link_frame` is left empty, that file may fail or behave unexpectedly during initialization. Read it carefully before relying on it as the production path.

The MPC helper has warm-start fields, but warm-start value updates are commented out. Do not assume it is currently warm-starting between solves.

The MPC helper raises if the solver is not optimal. If you change constraints or weights, preserve graceful handling in the node.

## Editing Guidance

When changing behavior:

- prefer small, isolated edits in the helper or in one tracker variant at a time
- document whether the change affects only `tracker`, only `tracker_v2`, or both
- keep node-level goal logic separate from solver-level tracking logic when possible

If you add parameters:

- declare them in the node, not only in helper code
- make defaults explicit
- keep launch files aligned with new parameters

## Useful Local Commands

From repo root:

```bash
rg -n "MPCTracker|check_goal|is_at_goal_position|FINAL_SPIN|ExecutePath" EM_fleetmanager/src/tracker
```

```bash
sed -n '1,260p' EM_fleetmanager/src/tracker/tracker/helper_classes/mpc_tracker_theta.py
```

```bash
sed -n '1,260p' EM_fleetmanager/src/tracker/tracker/tracker_mpc.py
```

```bash
sed -n '1,260p' EM_fleetmanager/src/tracker/tracker/tracker_mpc_v2.py
```

## When Summarizing Behavior For Users

Explain the tracker in this order:

1. Which node variant is being run
2. How a path becomes line segments
3. How progress `s` and the reference horizon are built
4. What the optimizer minimizes and constrains
5. What node-level goal / stop conditions wrap around the optimizer
6. Which assumptions may break on the physical robot
