#!/bin/bash

CONTAINER_NAME="fleetmanager"
IMAGE_NAME="fleetmanager:latest"

echo "Stopping old container..."
docker stop $CONTAINER_NAME 2>/dev/null || true

echo "Removing old container..."
docker rm $CONTAINER_NAME 2>/dev/null || true

echo "Build image..."
docker build -t $IMAGE_NAME .

echo "Starting new container..."
docker run -d --network host --name $CONTAINER_NAME $IMAGE_NAME
