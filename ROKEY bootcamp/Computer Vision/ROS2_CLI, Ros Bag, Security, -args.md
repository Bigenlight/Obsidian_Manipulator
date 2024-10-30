#ROS2 
[[ROBOTICS]]
last modification: 2024-10-14
![[ROS2_프로그래밍입문_강의자료_v115-211-282_241025_121522.pdf]]
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

## --ros-args
이걸 붙이면 뒤에 arguments 추가 가능
```
ros2 run turtlesim turtlesim_node --ros-args -r __ns:=/tutorial -r __node:=my_turtle -r turtle1/cmd_vel:=cmd_vel -p background_b:=0
```
원 터틀심 실행 노드에서 여러 커스텀 파라미터 추가  

###### 터틀심 배경색 바꾸기
vim turtlesim.yaml
먼저 파라미터 파일을 만들고
```
turtlesim:
  ros__parameters:
    background_b: 0
    background_g: 250
    background_r: 250
    use_sim_time: false
```
이를 ros-args를 통해 일회성으로 적용 가능
ros2 run turtlesim turtlesim_node --ros-args --params-file turtlesim.yaml
그러면 파라미터가 커스텀으로 바뀌어있음. 배경이 노란색 됨.