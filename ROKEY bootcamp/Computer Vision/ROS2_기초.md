[[ROBOTICS]]
#ROS2 #Robotics 
last modification: 2024-10-04

# ROS2 팁
### Symlink-install
colcon build --symlink-install
![[Drawing 2024-10-18 16.35.29.excalidraw]]
이걸 쓰면 콜콘 빌드 후 파일을 조금 ==수정해도 빌드를 안해도 그대로 실제 반영 됨==. 왜냐하면 파일 자체가 복사 된 것이 아니라 링크가 갔기 때문에.
하지만 이 기능은 ==파이썬 코드만== 됨. C는 애초에 개념이 다름, 무조건 빌드가 필요함.
이걸 쓰면 빌드도 짧아지고 전체 용량도 줄어듬.

무작정 토픽으로 string을 보내 받는 쪽에 parsing 하지말고, 애초에 인터페이스를 만들어 보내면 더 간편.

ROS2에 RQT라고 PyQT 같은 GUI 생성 프로그램이 있음.
물론 영상도 출력 가능.

# ROS2 연습, URDF 패키지 생성
강의자료pdf 86p 부타

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

pip install xacro

rviz2
add -> Robot Model 추가

==.xacro 파일에 실수로 띄워쓰기를 포함해서 실행이 안됨;;;;==

Description Topic -> /robot_description으로 변경