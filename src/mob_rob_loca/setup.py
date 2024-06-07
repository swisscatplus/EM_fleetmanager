import os
from glob import glob
from setuptools import setup

package_name = 'mob_rob_loca'

setup(
    name=package_name,
    version='0.0.1',
    packages=[package_name, f'{package_name}.submodules'],
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
        (os.path.join('share', package_name, 'action'), glob('action/*')),
        (os.path.join('share', package_name, 'srv'), glob('srv/*')),
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
        'ticks2odom = mob_rob_loca.tick_to_odom:main',
        'marv2ekf = mob_rob_loca.marv_to_ekf:main',
        'nav_manager = mob_rob_loca.nav_manager:main',
        'vision_loca_pc = mob_rob_loca.vision_loca_pc:main',
        'markers = mob_rob_loca.markers:main',
        'nav_manager2 = mob_rob_loca.nav_manager2:main',
        'imu_pub = mob_rob_loca.imu:main',
        ],
    },
)