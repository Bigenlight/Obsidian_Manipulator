```
<?xml version="1.0"?> <!--이건 xml 모델이라는 정의, 그리고 버전 정보도-->

  

<robot xmlns:xacro="http://www.ros.org/wiki.xacro" name="arduinobot"><!--XML 익스텐션으로 자동완성!! -->

<!-- xacro 연결, 로봇 이름 정의 -->

  

<!--옆에 파일 가져오기-->

<xacro:include filename="$(find arduinobot_description)/urdf/arduinobot_gazebo.xacro"/>

<xacro:include filename="$(find arduinobot_description)/urdf/arduinobot_ros2_control.xacro"/>

  

<!--inertial makro-->

<xacro:macro name="default_inertial" params="mass">

<inertial>

<mass value="${mass}"/>

<inertia ixx="1.0" ixy="0.0" ixz="0.0"

iyy="1.0" iyz="0.0"

izz="1.0"/>

</inertial>

</xacro:macro>

  

<!--모터와 링크를 연결시키는 태그, number는 조인트 번호가 들어갈 예정-->

<xacro:macro name="default_transmission" params="number">

<transmission name="transmissiom_${number}">

<!--트랜스미션 라이브러리 플러그인-->

<plugin>transmission_interface/SimpleTransmission</plugin>

  

<!--엑추에이터와 조인트의 명과 역할 이름 붙이기-->

<actuator name="motor_${number}" role="actuactor1"/>

<joint name="joint_${number}" role="joint1">

<!--모터의 1도가 링크에서 1도임-->

<mechanical_reduction>1.0</mechanical_reduction>

</joint>

</transmission>

</xacro:macro>

  
  

<!-- 끝나기 전에 / 가 들어가 있으면 이는 한줄로 끝난다는겨 -->

<link name="world"/>

<!-- 위 링크는 이름만 있으면 됨, 모든 링크의 부모, 로봇이 월드에 붙어있게 도와줌 -->

  

<link name="base_link"> <!-- 베이스 링크 -->

<xacro:default_inertial mass="1000.0"/>

  

<visual> <!-- 시각적 -->

<!-- 오리진으로 위치와 방향, 각도rpy, 위치-->

<origin rpy="0 0 0" xyz="0 0 0"/> <!--좌표 수정-->

<geometry> <!-- 도형 -->

<!-- mesh 지정 -->

<box size="0.1 0.1 0.2"/> <!-- 그리고 스케일 지정, 아니면 너무 큼-->

</geometry>

</visual>

  

<!--가제보할 때 추가!-->

<!-- 기본적으로 비주얼과 같은 것을 가져옴-->

<collision>

<origin rpy="0 0 0" xyz="0 0 0"/> <!--좌표 수정-->

<geometry> <!-- 도형 -->

<!-- mesh 지정 -->

<box size="0.1 0.1 0.2"/> <!-- 그리고 스케일 지정, 아니면 너무 큼-->

</geometry>

</collision>

</link>

  

<joint name="virtual_joint" type="fixed"><!-- 월드랑 베이스 링크 연결, 종류는 고정-->

<parent link="world"/>

<child link="base_link"/>

<origin xyz="0 0 0" rpy="0 0 0"/>

</joint>

<!-- 위에 쓰고 CMake로-->

  
  
  

<!--여기부터 다음 단계 -->

  

<!-- xacro를 쓰는 이유, 변수 지정 가능. 지금은 PI라는 변수를 만든 것-->

<xacro:property name="PI" value= "3.14159"/>

<xacro:property name="effort" value= "30.0"/>

<xacro:property name="velocity" value= "10.0"/>

  

<!--베이스 플레이트 생성-->

<link name="base_plate">

<xacro:default_inertial mass="0.1"/>

  

<visual>

<origin rpy="0 0 0" xyz="0 0 0.2"/>

<geometry>

<box size="0.1 0.1 0.2"/> <!--이번에도 스케일을 똑같이 줄이자-->

</geometry>

</visual>

  

<collision>

<origin rpy="0 0 0" xyz="0 0 0.2"/>

<geometry>

<box size="0.1 0.1 0.2"/> <!--이번에도 스케일을 똑같이 줄이자-->

</geometry>

</collision>

</link>

  

<!--첫 움직이는 조인트! 그래서 type이 revolute-->

<joint name="joint_1" type="revolute">

<parent link="base_link"/>

<child link="base_plate"/>

<axis xyz="0 0 1"/><!-- z 축이 회전하는 것이다.-->

<origin rpy="0 0 0" xyz="0 0 0.307"/><!-- T matrix, 즉 z축으로 0.307 만큼 올라가는 뜻! -->

<!--조인트 움직임 한계 조절, effort는 토크 -->

<limit lower="${-PI}" upper="${PI}" effort="${effort}" velocity="${velocity}"/>

<!--xacro로 지정한 변수를 집어넣어서 유지보수를 쉽게!! ${변수}로 사용가능. 이때 연산은 안이든 밖이든 상관 없는 듯-->

<!-- 90 이동 제한이라 PI/2-->

</joint>

  
  
  

<!--그다음 강의-->

<!--urdf 치면 link 자동완성 양식이 나옴-->

<link name="link_j23">

<xacro:default_inertial mass="0.1"/>

  

<visual>

<origin rpy="0 -${PI/2} ${PI/2}" xyz="0.19 0.06 -0.08"/> <!-- 회전시켜 배치-->

<geometry>

<box size="0.1 0.1 0.2"/>

</geometry>

<material name="LightGrey">

<color rgba="0.7 0.7 0.7 1.0"/>

</material>

</visual>

  

<collision>

<origin rpy="0 -${PI/2} ${PI/2}" xyz="0.19 0.06 -0.08"/> <!-- 회전시켜 배치-->

<geometry>

<box size="0.1 0.1 0.2"/>

</geometry>

</collision>

</link>

  

<joint name="joint_2" type="revolute">

<parent link="base_plate"/>

<child link="link_j23"/>

<axis xyz="1 0 0"/><!-- x축 회전-->

<origin rpy="0 0 0" xyz="-0.02 0 0.35"/><!--회전은 안하지만 평행이동은 했음-->

<limit lower="${-PI}" upper="${PI}" effort="${effort}" velocity="${velocity}"/>

</joint>

  

<link name="link_j34">

<xacro:default_inertial mass="0.1"/>

  

<visual>

<origin rpy="0 0 0" xyz="0 0 0.9"/> <!-- 회전시켜 배치-->

<geometry>

<box size="0.1 0.1 0.2"/>

</geometry>

<material name="LightGrey">

<color rgba="0.7 0.7 0.7 1.0"/>

</material>

</visual>

  

<collision>

<origin rpy="0 0 0" xyz="0 0 0.9"/> <!-- 회전시켜 배치-->

<geometry>

<box size="0.1 0.1 0.2"/>

</geometry>

</collision>

</link>

  

<joint name="joint_3" type="revolute">

<parent link="link_j23"/>

<child link="link_j34"/>

<axis xyz="1 0 0"/><!-- x축 회전-->

<origin rpy="0 0 0" xyz="0 0 0.8"/><!--회전은 안하지만 평행이동은 했음-->

<limit lower="${-PI}" upper="${PI}" effort="${effort}" velocity="${velocity}"/>

</joint>

  

<link name="link_j45">

<xacro:default_inertial mass="0.05"/>

  

<visual>

<origin rpy="0 0 0" xyz="0 0 0.3"/>

<geometry>

<box size="0.1 0.1 0.4"/>

</geometry>

</visual>

  

<collision>

<origin rpy="0 0 0" xyz="0 0 0.3"/>

<geometry>

<box size="0.1 0.1 0.4"/>

</geometry>

</collision>

</link>

  

<!-- <joint name="joint_4" type="fixed">

<parent link="link_j34"/>

<child link="link_j45"/>

<origin rpy="0 0 0" xyz="0 0 1.6"/>

</joint> -->

<joint name="joint_4" type="revolute">

<parent link="link_j34"/>

<child link="link_j45"/>

<axis xyz="1 0 0"/><!-- x축 회전-->

<origin rpy="0 0 0" xyz="0 0 1.6"/><!--회전은 안하지만 평행이동은 했음-->

<limit lower="${-PI}" upper="${PI}" effort="${effort}" velocity="${velocity}"/>

</joint>

  

<link name="link_j56">

<xacro:default_inertial mass="0.05"/>

  

<visual>

<origin rpy="0 0 0" xyz="0 0 0.37"/>

<geometry>

<box size="0.1 0.1 0.4"/>

</geometry>

</visual>

  

<collision>

<origin rpy="0 0 0" xyz="0 0 0.37"/>

<geometry>

<box size="0.1 0.1 0.4"/>

</geometry>

</collision>

</link>

  

<joint name="joint_5" type="revolute">

<parent link="link_j45"/>

<child link="link_j56"/>

<axis xyz="1 0 0"/><!-- x축 회전-->

<origin rpy="0 0 0" xyz="0 0 2.0"/><!--회전은 안하지만 평행이동은 했음-->

<limit lower="${-PI}" upper="${PI}" effort="${effort}" velocity="${velocity}"/>

</joint>

  
  

<link name="link_j6e">

<xacro:default_inertial mass="0.05"/>

  

<visual>

<origin rpy="0 0 0" xyz="0 0 0.40"/>

<geometry>

<box size="0.1 0.05 0.2"/>

</geometry>

</visual>

  

<collision>

<origin rpy="0 0 0" xyz="0 0 0.40"/>

<geometry>

<box size="0.1 0.05 0.2"/>

</geometry>

</collision>

</link>

  

<joint name="joint_6" type="revolute">

<parent link="link_j56"/>

<child link="link_j6e"/>

<axis xyz="0 1 0"/><!-- x축 회전-->

<origin rpy="0 0 0" xyz="0 0 2.2"/><!--회전은 안하지만 평행이동은 했음-->

<limit lower="${-PI}" upper="${PI}" effort="${effort}" velocity="${velocity}"/>

</joint>

  
  
  

<!--트랜스미션 발동, 각 모터와 조인트 연결-->

<xacro:default_transmission number="1"/>

<xacro:default_transmission number="2"/>

<xacro:default_transmission number="3"/>

<xacro:default_transmission number="4"/>

<xacro:default_transmission number="5"/>

<xacro:default_transmission number="6"/>

  
  

</robot>
```