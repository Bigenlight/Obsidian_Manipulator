[[ROBOTICS]]
#ROS2 #Robotics 
last modification: 2024-10-04

# ROS2 팁
colcon build --symlink-install
==를 사용하면 굳이 install을 따로 또 안해도 된다!!!==

무작정 토픽으로 string을 보내 받는 쪽에 parsing 하지말고, 애초에 인터페이스를 만들어 보내면 더 간편.

ROS2에 RQT라고 PyQT 같은 GUI 생성 프로그램이 있음.
물론 영상도 출력 가능.