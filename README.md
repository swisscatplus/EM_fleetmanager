<br />
<div align="center">
  <a href="https://github.com/swisscatplus/EM_onrobot">
    <img src="pictures/logo.png" alt="Logo" height="80">
  </a>

  <h1 align="center">EM_fleetmanager</h1>
</div>

- Publishing of SwissCat+ laboratory map and QR Markers localization for mobile robots to localize itself, 
developed in <b>Python</b> and <b>ROS 2 Humble</b>, running inside <b>Docker</b>.
- Integrates with the <a href="https://github.com/swisscatplus/EM_onrobot">EM_onrobot</a> deployed on the mobile robot.

---

## Table of Contents

1. [Overview](#overview)  
2. [System Architecture](#system-architecture)  
3. [Deployment of a New Robot](#deployment-of-a-new-robot)  
4. [Docker Installation (recommended)](#docker-installation-recommended)
5. [How to Run](#how-to-run)  
6. [ROS 2 Interfaces](#ros-2-interfaces)  
7. [Project Structure](#project-structure)  
8. [Improvements & Roadmap](#improvements--roadmap)
9. [License](#license)  

---

## Overview

The `EM_fleetmanager` repository contains the software resources for deploying the laboratory maps, markers and managing the fleet of mobiles robots

### Software
- Published the map of the track where mobile robots are moving in a png format that can be seen in rviz.  
- Publishes the markers position in the map for the mobile robot to localize itsef in the map

### Deployment
- Supports **containerized deployment with Docker** for easy setup and reproducibility.  


---

## Versions & Software

- **OS**: Ubuntu 22.04
- **ROS 2**: Humble

---

## System Architecture

- **Hardware**
  - PC
  - Laboratory Track
  - Aruco Markers

- **Software**
  - ROS 2 packages (all inside Docker):
    - `mob_rob_loca` → publishes the map and markers
    - `mob_rob_loca_msgs` → service definitions

---

## Deployment

### Networking
- Ensure **PC and RPi are on the same network**.  
- For that, configure a **static IP** on the PC which should be the same as the one found in **fastdds.xml** (for example : 192.168.0.14)
- Match the **ROS_DOMAIN_ID** on both PC and RPi (default = `10`):  
  ```bash
  echo "export ROS_DOMAIN_ID=10" >> ~/.bashrc
  ```
  Or in the Dockerfile:  
  ```dockerfile
  ENV ROS_DOMAIN_ID=10
  ```
---

## Docker Installation (recommended)

2. **Install Docker** on the PC:  
   ```bash
   sudo apt-get update
   sudo apt-get install ca-certificates curl gnupg
   sudo install -m 0755 -d /etc/apt/keyrings
   curl -fsSL https://download.docker.com/linux/debian/gpg | sudo gpg --dearmor -o /etc/apt/keyrings/docker.gpg
   sudo chmod a+r /etc/apt/keyrings/docker.gpg

   echo      "deb [arch=$(dpkg --print-architecture) signed-by=/etc/apt/keyrings/docker.gpg] https://download.docker.com/linux/debian      $(. /etc/os-release && echo "$VERSION_CODENAME") stable" |      sudo tee /etc/apt/sources.list.d/docker.list > /dev/null

   sudo apt-get update
   sudo apt-get install -y docker-ce docker-ce-cli containerd.io docker-buildx-plugin docker-compose-plugin
   sudo groupadd docker
   sudo gpasswd -a $USER docker
   newgrp docker
   docker run hello-world
   ```

4. **Run the container**:  
   ```bash
   ./deploy.sh
   ```
---

## How to Run

### Start the container:
   ```bash
   ./deploy.sh
   ```
---

## ROS 2 Interfaces

### Topics
| Topic           | Type                                     | Description                       |
|-----------------|------------------------------------------|-----------------------------------|
| `/map`          | `nav_msgs/OccupancyGrid`                 | Map image of the laboratory track |
| `/marker_<num>` | `geometry_msgs/TransformStamped`         | Aruco Makers in the map           |


### Parameters
| Parameter      | Type   | Description                                                   |
|----------------|--------|---------------------------------------------------------------|
| `namespace`    | string | Namespace prefix for topics/nodes per robot                   |
| `config_file`  | string | Path to camera calibration file (ArUco positions, intrinsics) |

---

## Project Structure

```
EM_fleetmanager/
├── Dockerfile            # Build instructions for fleetmanager image
├── entrypoint.sh         # Container entrypoint script
├── fastdds.xml           # Fast DDS configuration
├── src/
│   ├── mob_rob_loca/         # Main fleetmanager package (map,markers)
│   ├── mob_rob_loca_srv/     # ROS 2 service definitions
├── pictures/logo.png
├── README.md
├── requirements.txt      # Requirements if trying to run locally
├── LICENSE               # MIT License
├── deploy.sh             # Launch the container
```

---

## Improvements & Roadmap

- Expand documentation with troubleshooting and advanced usage examples.

---

## License

This project is licensed under the [MIT License](./LICENSE).

