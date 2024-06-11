#!/usr/bin/env bash

source /opt/ros/humble/setup.bash
source install/setup.bash

port=$1

echo $PYTHONPATH

PYTHONPATH=./src python3.10 -m trial
