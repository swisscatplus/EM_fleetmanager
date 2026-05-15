from glob import glob
import os
from setuptools import find_packages, setup

package_name = 'tracker'

setup(
    name=package_name,
    version='0.0.0',
    packages=find_packages(),
    data_files=[
        ('share/ament_index/resource_index/packages',
            ['resource/' + package_name]),
        ('share/' + package_name, ['package.xml']),
        (os.path.join('share', package_name, 'launch'), glob(os.path.join('launch', '*.launch.py'))),
        (os.path.join('share', package_name, 'config'), glob(os.path.join('config', '*.yaml'))),
    ],
    install_requires=['setuptools'],
    zip_safe=True,
    maintainer='root',
    maintainer_email='root@todo.todo',
    description='TODO: Package description',
    license='TODO: License declaration',
    tests_require=['pytest'],
    entry_points={
        'console_scripts': [
            'planner = tracker.planner:main',
            'tracker = tracker.tracker_mpc:main',
            'planner_demo = tracker.planner_demo:main',
            'tracker_demo = tracker.tracker_mpc_demo:main',
            'publish_path = tracker.publish_path:main',
            'publish_path_loop = tracker.publish_path_loop:main',
            'publish_path_loop_manual = tracker.publish_path_loop_manual:main',
            'planner_v2 = tracker.planner_v2:main',
            'tracker_v2 = tracker.tracker_mpc_v2:main',
            # 'pose2d_publisher = tracker.pose2d_publisher:main',
            # 'pose2d_subscriber = tracker.pose2d_subscriber:main',
        ],
    },
)
