#ROS2 
[[ROBOTICS]]
last modification: 2024-10-15
![[ROS2_심화프로그래밍_241025_112428.pdf]]
## Intra-process communication
복수개의 노드를 사용하면 통신 성능 저하가 발생.
이를 최적화 하는 것이 IPC.
노드끼리 통신할 때 공유 된 메모리, shared memory를 사용하게 끔 만듬.

## RQT

토픽 내용 같은거 보려고 할 때 토픽 선택하고 우측의 + 버튼을 눌러야 나옴
![[Pasted image 20241018150721.png]]
#### Service call
서비스 콜러로 서비스도 실행 가능
![[Pasted image 20241018150434.png]]
원하는 서비스 선택 -> 보내야 하는 값 선택 -> Call 버튼 클릭
![[Pasted image 20241018150516.png]]
서비스 발동