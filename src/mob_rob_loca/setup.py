import os
from glob import glob
from setuptools import setup
from distutils import sysconfig
from distutils.extension import Extension

package_name = 'mob_rob_loca'

setup(
    name=package_name,
    version='0.0.0',
    packages=[package_name],
    data_files=[
        ('share/ament_index/resource_index/packages',
            ['resource/' + package_name]),
        ('share/' + package_name, ['package.xml']),
        (os.path.join('share', package_name, 'launch'), glob(os.path.join('launch', '*.launch.py'))),
        (os.path.join('share', package_name, 'urdf'), glob('urdf/*')),
        (os.path.join('share', package_name, 'rviz'), glob('rviz/*')),
        (os.path.join('share', package_name, 'maps'), glob('maps/*')),
        (os.path.join('share', package_name, 'params'), glob('params/*')),
        (os.path.join('share', package_name, 'config'), glob('config/*')),
    ],
    install_requires=['setuptools'],
    zip_safe=True,
    maintainer='coderey',
    maintainer_email='yannis.coderey@epfl.ch',
    description='TODO: Package description',
    license='Apache 2.0',
    tests_require=['pytest'],
    entry_points={
        'console_scripts': [
        'transforms = mob_rob_loca.transforms:main',
        'rpi_com_motors = mob_rob_loca.rpi_communication:main',
        'ticks2odom = mob_rob_loca.tick_to_odom:main',
        'marv2ekf = mob_rob_loca.marv_to_ekf:main',
        'imu_serv = mob_rob_loca.imu_serv:main',
        'nav2pose = mob_rob_loca.nav_to_pose:main',
        'navthruposes = mob_rob_loca.nav_through_poses:main',
        'navwaypoints = mob_rob_loca.nav_waypoints:main',
        'calib_odom = mob_rob_loca.calib_odom:main',
        'trial = mob_rob_loca.extract_and_plot:main'
        ],
    },
)