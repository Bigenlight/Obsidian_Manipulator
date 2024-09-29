[[ROS2 공부]]
last modification: 2024-09-28

```
cd ~/ros2_ws/src
ros2 pkg create --build-type ament_python launch_folder
```

```
cd launch_folder
mkdir launch
```

launch 폴더 안에 
new.launch.py 생성
```python
from launch import LaunchDescription
from launch_ros.actions import Node

def generate_launch_description():
    return LaunchDescription([
        Node(
            package='waypoint_converter', # 패키지 이름
            executable='waypoint_converter_executable',  # 각 패키지 setup.py에 있는 = 앞에 오는 명칭
            name='waypoint_converter' 
        ),
        Node(
            package='mqtt_subscriber', # 다른 패키지 이름
            executable='mqtt_subscriber_executable', 
            name='mqtt_subscriber'
        )
    ])
```

이제  launch_file_ 의 setup.py 편집
```python
from setuptools import setup
import os
from glob import glob

package_name = 'launch_folder'

setup(
    name=package_name,
    version='0.0.0',
    packages=[],
    install_requires=['setuptools'],
    zip_safe=True,
    author='Your Name',
    author_email='your.email@example.com',
    description='Launch file for communication packages',
    license='License declaration',
    entry_points={
        'console_scripts': [],
    },
    data_files=[
        (os.path.join('share', package_name), ['package.xml']),
        (os.path.join('share', package_name, 'launch'), glob('launch/*.launch.py')),
    ],
)
```

package.xml에 \<package> 태그 안에 추가
```xml
<buildtool_depend>ament_cmake</buildtool_depend>

<!--이 아래 두개 노드명 편집 -->
<exec_depend>waypoint_converter</exec_depend>
<exec_depend>mqtt_subscriber</exec_depend>

<exec_depend>launch</exec_depend>
<exec_depend>launch_ros</exec_depend>
```

cb
inst

ros2 launch  launch_folder  new.launch.py
