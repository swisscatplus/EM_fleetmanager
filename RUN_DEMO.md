# Demo: loop OmniFire <-> LC MS (robot1)

Copy-paste each block in its own terminal, in order.

## 0. Update the code (once, after changes)

```bash
cd ~/Documents/GitHub/EM_fleetmanager
git pull
```

## 1. Terminal 1: fleet manager + tracker (leave running)

```bash
cd ~/Documents/GitHub/EM_fleetmanager
./scripts/up_stack.sh
```

Wait until the tracker prints that it is running and the map -> robot1/base_link TF exists.

## 2. Terminal 2: start the loop

```bash
cd ~/Documents/GitHub/EM_fleetmanager
./scripts/shell.sh
```

Then, inside the container:

```bash
cd /ros2_ws/src/fleet_manager/fleet_manager
python3 demo_loop.py --ros-args -p robot:=robot1 -p stations:="OmniFire,LC MS"
```

- **Ctrl+C** stops the robot and ends the loop.
- The robot goes to the first station in the list first. For the opposite order use `-p stations:="LC MS,OmniFire"`.

Optional parameters (add after `-p robot:=robot1`):

| Parameter | Meaning | Default |
|---|---|---|
| `-p pause:=10` | seconds waited at each station | 5 |
| `-p laps:=5` | number of laps, 0 = until Ctrl+C | 0 |
| `-p max_failures:=3` | stop after N failed trips in a row | 2 |

## One-off trip to a single station (no loop)

Inside the container (Terminal 2):

```bash
cd /ros2_ws/src/fleet_manager/fleet_manager
python3 path_sender.py --ros-args -p goal:="OmniFire" -p robot:=robot1
```

## Stop everything

Ctrl+C in Terminal 2 (robot stops), then Ctrl+C in Terminal 1, then:

```bash
cd ~/Documents/GitHub/EM_fleetmanager
./scripts/down.sh
```

## If something goes wrong

Check the robot pose in the container:

```bash
ros2 run tf2_ros tf2_echo map robot1/base_link
```

- "waiting for TF" repeating: the robot is not localized (check markers / EKF).
- "waiting for the tracker on /robot1/path": the tracker container is not up.
- Station names must match [stations.yaml](src/fleet_manager/config/stations.yaml) exactly (e.g. `LC MS`, `OmniFire`).
