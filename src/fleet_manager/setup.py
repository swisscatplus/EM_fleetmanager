import os
from glob import glob

from setuptools import setup


package_name = 'fleet_manager'


setup(
    name=package_name,
    version='0.1.0',
    packages=[package_name],
    data_files=[
        (
            'share/ament_index/resource_index/packages',
            [f'resource/{package_name}'],
        ),
        (os.path.join('share', package_name), ['package.xml']),
        (
            os.path.join('share', package_name, 'launch'),
            glob(os.path.join('launch', '*.launch.py')),
        ),
        (
            os.path.join('share', package_name, 'maps'),
            glob(os.path.join('maps', '*')),
        ),
        (
            os.path.join('share', package_name, 'config'),
            glob(os.path.join('config', '*')),
        ),
        (
            os.path.join('share', package_name, 'rviz'),
            glob(os.path.join('rviz', '*')),
        ),
    ],
    install_requires=['setuptools'],
    zip_safe=True,
    maintainer='coderey',
    maintainer_email='yannis.coderey@epfl.ch',
    description='Publish the laboratory map and ArUco marker transforms.',
    license='Apache 2.0',
    tests_require=['pytest'],
    entry_points={
        'console_scripts': [
            'generate_hardcoded_paths = fleet_manager.generate_hardcoded_paths:main',
            'markers = fleet_manager.markers:main',
            'rest_api = fleet_manager.rest_api:main',
        ],
    },
)
