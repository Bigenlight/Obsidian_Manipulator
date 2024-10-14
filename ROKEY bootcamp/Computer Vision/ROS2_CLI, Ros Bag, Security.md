#ROS2 
[[ROBOTICS]]
last modification: 2024-10-14

# CLI
#### ROS2 Doctor or WTF
ros2 doctor hello
ros2 doctor -r
개발환경의 문제 확인용
사용하는 프로그램 버전도 다 출력 됨.
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

## Security
ROS2 DDS는 보안성도 나쁘지 않다

ros2 security create_keystore demo_keystore

ros2 security create_enclave demo_keystore /talker_listener/talker
ros2 security create_enclave demo_keystore /talker_listener/listener

cd demo_keystore/enclaves/
에 키가 생김

환경 임시 변수 설정 (영구적으로 쓰고 싶으면 bashrc에 저장), 첫 명령의 주소는 만들어둔 키 스토어로
export ROS_SECURITY_KEYSTORE=~/demo_keystore
export ROS_SECURITY_ENABLE=true
export ROS_SECURITY_STRATEGY=Enforce
