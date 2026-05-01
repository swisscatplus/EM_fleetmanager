<br />
<div align="center">
  <a href="https://github.com/swisscatplus/EM_fleetmanager">
    <img src="pictures/logo.png" alt="Logo" height="80">
  </a>
  <h1 align="center">EM_fleetmanager</h1>
</div>

ROS 2 laptop-side workspace for publishing the laboratory map and ArUco marker transforms.

This repository is responsible for:

- publishing the laboratory map through `nav2_map_server`
- publishing static `map -> track_* -> aruco_*` transforms
- Dockerized laptop deployment on ROS 2 Humble

The current ROS package is `fleet_manager`.

## Supported Target

The supported runtime target is an Ubuntu laptop/workstation running ROS 2 Humble in Docker.

The default entrypoint launches both publishers:

```bash
ros2 launch fleet_manager bringup.launch.py
```

That launch also starts RViz with a preconfigured map display. To skip RViz:

```bash
ros2 launch fleet_manager bringup.launch.py use_rviz:=false
```

Optional convenience launches:

```bash
ros2 launch fleet_manager maps.launch.py
ros2 launch fleet_manager markers.launch.py
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

The compose workflow bind-mounts this repository into `/ros2_ws`, builds `fleet_manager` with `--symlink-install`, sources the workspace, then starts the combined launch.

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
colcon build --symlink-install --packages-select fleet_manager
```

Run tests:

```bash
colcon test --packages-select fleet_manager
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
│   └── fleet_manager/
└── pictures/
```

## License

MIT. See [`LICENSE`](./LICENSE).
