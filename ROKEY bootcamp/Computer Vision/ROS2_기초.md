[[ROBOTICS]]
#ROS2 #Robotics 
last modification: 2024-10-04

# ROS2 팁
colcon build --symlink-install
==를 사용하면 굳이 install을 따로 또 안해도 된다!!!==

무작정 토픽으로 string을 보내 받는 쪽에 parsing 하지말고, 애초에 인터페이스를 만들어 보내면 더 간편.

ROS2에 RQT라고 PyQT 같은 GUI 생성 프로그램이 있음.
물론 영상도 출력 가능.

# ROS2 연습
mkdir -p urdf_ws/src
cd urdf_ws/
cbs

cd src/
ros2 pkg create --build-type ament_python urdf_tutorial

cd urdf_tutorial/
mkdir urdf

urdf에
robot_1.xacro 생성
![[Pasted image 20241004161240.png|100]]
```
<?xml version="1.0"?>
<robot xmlns:xacro="http://ros.org/wiki/xacro" name="urdf_test">

  <!-- BASE -->
  <link name="base_link">
  </link>

  <!-- BODY LINK -->
  <joint name="body_joint" type="fixed">
    <parent link="base_link"/>
    <child link="body"/>
  </joint>

  <link name="body">
    <visual>
      <geometry>
        <box size="1 1 1"/>
      </geometry>
    </visual>
  </link>

</robot>
```

Launch 파일도 생성
![[Pasted image 20241004161830.png|100]]
여기에 **robot_1.launch.py** 생성
```python
import os
from ament_index_python.packages import get_package_share_directory
from launch import LaunchDescription
from launch.substitutions import LaunchConfiguration
from launch.actions import DeclareLaunchArgument
from launch_ros.actions import Node
import xacro

def generate_launch_description():
    use_sim_time = LaunchConfiguration("use_sim_time")

    pkg_path = os.path.join(get_package_share_directory("urdf_tutorial"))
    xacro_file = os.path.join(pkg_path, "urdf", "robot_1.xacro")
    robot_description = xacro.process_file(xacro_file)
    params = {"robot_description": robot_description.toxml(), "use_sim_time": use_sim_time}

    return LaunchDescription(
        [
            DeclareLaunchArgument(
                "use_sim_time", default_value="false", description="Use sim time"
            ),
            Node(
                package="robot_state_publisher",
                executable="robot_state_publisher",
                output="screen",
                parameters=[params],
            ),
        ]
    )
```

rviz2
add -> Robot Model 추가
