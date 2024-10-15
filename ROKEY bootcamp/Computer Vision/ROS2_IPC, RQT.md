#ROS2 
[[ROBOTICS]]
last modification: 2024-10-15

## Intra-process communication
복수개의 노드를 사용하면 통신 성능 저하가 발생.
이를 최적화 하는 것이 IPC.
노드끼리 통신할 때 공유 된 메모리, shared memory를 사용하게 끔 만듬.