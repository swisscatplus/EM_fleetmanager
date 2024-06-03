#!/usr/bin/env bash

port=$1

PYTHONPATH=./src python3.12 -m run -p "$port" -v -l -d