import subprocess
import os

def main():
    source = "source /opt/ros/humble/setup.bash"
    source2 = "source install/setup.bash"
    cmd = "ros2 run mob_rob_loca client 'a' 'b'"
    full_command = f"bash -c '{source} && {source2} && {cmd}'"
    subprocess.run(full_command, shell=True)

if __name__ == "__main__":
    main()