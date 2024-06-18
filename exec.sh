#!/usr/bin/env bash

source /opt/ros/humble/setup.bash

port=$1


PYTHONPATH=./src python3.11 -m run -p "$port" -v -l -d