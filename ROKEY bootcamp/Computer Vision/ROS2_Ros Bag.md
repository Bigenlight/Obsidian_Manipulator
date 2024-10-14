#ROS2 
[[ROBOTICS]]
last modification: 2024-10-14

## ROS Bag
ros bag은 영상도 담을 수 있음

###### Rviz: Add -> By topic
![[Pasted image 20241014141535.png]]
경우에 따라 Rviz에서 Add를 할 때 타입벼로 찾는게 아니라, 발행 되는 토픽 기준으로 시각화할 것을 찾는게 쉬움

이때 영상을 볼때 Camera 보다 Image 형식으로 시각화를 많이 함. 보이는건 같음. 그렇게하는이유는 모름.

##### ROS Bag 반복
뒤에 --loop 붙이면 계속 반복함
###### 속도 조절
--rate=2.0 붙이면 2배속 됨.
###### 정지 기능 추가
--start-paused 
엔터로 정지 시작 가능.