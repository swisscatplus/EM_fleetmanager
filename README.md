<br />
<div align="center">
  <a href="https://github.com/swisscatplus/EM_fleetmanager">
    <img src="pictures/logo.png" alt="Logo" height="80">
  </a>
  <h1 align="center">EM_fleetmanager</h1>
</div>

ROS 2 laptop-side fleet management stack for EM Robot.

This repository is responsible for:

- publishing the laboratory map
- publishing ArUco marker transforms used by mobile robots
- hosting fleet management services for multi-robot logic
- Dockerized laptop deployment on ROS 2 Humble

This repository is not the place for robot-side hardware control or path tracking. Robot-local behavior lives in `EM_onrobot`; path planning and control lives in `EM_pathplanning`.

## Supported Target

The supported runtime target is an Ubuntu laptop/workstation running ROS 2 Humble in Docker.

The default container command launches the map and marker publishers:

```bash
ros2 launch mob_rob_loca maps.launch.py
ros2 launch mob_rob_loca markers.launch.py
```

## Docker Development

Start the laptop development container:

```bash
./scripts/deploy_dev.sh
```

Run in the foreground instead:

```bash
./scripts/start_dev.sh
```

Useful follow-up commands:

```bash
./scripts/start_dev.sh logs
./scripts/start_dev.sh shell
./scripts/start_dev.sh down
```

The compose workflow bind-mounts this repository into `/ros2_ws`, builds `mob_rob_loca_msgs` and `mob_rob_loca` with `--symlink-install`, sources the workspace, then starts the default launch commands.

## Image Build

Build the laptop image:

```bash
./scripts/deployImage.sh
```

Override the image name or push it:

```bash
IMAGE_NAME=ghcr.io/swisscatplus/em_fleetmanager:latest ./scripts/deployImage.sh
PUSH_IMAGE=1 IMAGE_NAME=ghcr.io/swisscatplus/em_fleetmanager:latest ./scripts/deployImage.sh
```

## Build And Test

Build the ROS workspace locally:

```bash
colcon build --symlink-install --packages-select mob_rob_loca_msgs mob_rob_loca
```

Run tests:

```bash
colcon test --packages-select mob_rob_loca_msgs mob_rob_loca
colcon test-result --verbose
```

Generated `build/`, `install/`, and `log/` directories are ignored by Git.

## Repository Layout

```text
EM_fleetmanager/
├── config/
│   └── fastdds.xml
├── docker/
│   ├── compose.yaml
│   ├── Dockerfile
│   └── entrypoint.sh
├── scripts/
│   ├── deploy_dev.sh
│   ├── deployImage.sh
│   └── start_dev.sh
├── src/
│   ├── mob_rob_loca/
│   └── mob_rob_loca_msgs/
└── pictures/
```

## License

MIT. See [`LICENSE`](./LICENSE).
