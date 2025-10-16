# fleetmanager.ps1

# Define variables
$CONTAINER_NAME = "fleetmanager"
$IMAGE_NAME = "fleetmanager:latest"

Write-Host "Stopping old container..."
docker stop $CONTAINER_NAME 2>$null

Write-Host "Removing old container..."
docker rm $CONTAINER_NAME 2>$null

Write-Host "Building image..."
docker build -t $IMAGE_NAME .

Write-Host "Starting new container..."
docker run -d `
  --name $CONTAINER_NAME `
  --device /dev/input `
  --device /dev/uinput `
  --device /dev/hidraw0 `
  --cap-add SYS_ADMIN `
  --cap-add NET_ADMIN `
  --privileged `
  $IMAGE_NAME
