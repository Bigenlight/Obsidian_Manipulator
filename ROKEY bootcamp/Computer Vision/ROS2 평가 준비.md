#ROS2 
[[ROBOTICS]]
last modification: 2024-10-14

빠르게 과제 훑기

1.      ROS2에서 ament python 빌드 형태의 rclpy, std_msgs 패키지에 의존성을 가진 my_ros_pkg 패키지를 생성하는 명령어는 무엇인가?
ros2 pkg create 패키지명 --build-type ament_python --dependencies rclpy std_msgs

보언키로 노드 실행:
ros2 run 패키지명 노드 --ros-args --enclave 보안키

`source install/setup.bash`와 `source install/local_setup.bash`의 차이에 대해서 기술하세요:
-          setup./bash의 경우 크게 적용 범위가 다름. 해당 워크 스페이스의 전체 모든 패키지를 활용할 수 있도록 하며, 해당 워크스페이스 내의 모든 의존성 파일들을 포함한 완전한 환경 설정을 로드.
-          반면, local_setup.bash의 경우 현재 워크스페이스의 로컬 설정에만 적용되며, 다른 상위 또는 하위 워크스페이스의 설정을 로드하지 않는다.

![[Pasted image 20241024202520.png]]
1) argument node (Topic Publisher)
: arithmetic_argument 이라는 토픽 이름으로 현재 시간과 변수 a와 b를 퍼블리시한다.
2) calculator node (Topic Subscriber)
: 토픽이 생성된 시간과 변수 a와 b를 서브스크라이브한다.
3) operator node (Service Client)
: arithmetic_operator 이라는 서비스 이름으로 calculator 노드에게 연산자(+, -, *, /)를 서비스 요청 값으로 보낸다.
4) calculator node (Service Server)
: 서브스크라이브하여 저장하고 있는 변수 a와 b를 operator 노드로부터 요청 값으로 받은 연산자를 이용하여 계산(a 연산자 b)하고 operator 노드에게 연산의 결괏값을 서비스 응답값으로 보낸다.
5) checker node (Action)
​:연산값의 합계의 한계치를 액션 목표값으로 전달한 후, calculator 노드는 이를 받은 후 부터의 연산 값을 합하고 액션 피드백으로 각 연산 계산식을 보낸다. 지정한 연산값의 목표 합계를 넘기면 액션 결괏값으로 최종 연산 합계를 보낸다.

###### 1.   역기구학의 해를 구하는 방법에 대해서 서술하시오.
-          기하학적 방법
n  로봇의 조인트 및 링크의 상대적 위치 관계를 기하학으로 계산
n  3축 정도의 로봇 팔은 기하학적 해를 구하는 것이 매우 쉬움
n  4축이 넘어갈 경우 해를 구하는 수식이 복잡해짐
-          대수적 방법
n  수학적 방정식을 사용하여 역기구학 문제를 해결하는 방법
n  목표 위치와 방향에 대한 방정식을 풀어 관절 변수들을 계산
-          수치해석적 방법
n  해석적 방법으로 풀기 어려운 경우 반복적인 근사 계산을 통해 해를 구하는 방법

작업공간 정의