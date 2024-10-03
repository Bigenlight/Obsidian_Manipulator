[[ROBOTICS]]
#ROS2 #Robotics 
last modification: 2024-09-30

### 환경 설치 참고자료
[Notion – The all-in-one workspace for your notes, tasks, wikis, and databases.](https://teamsparkx.notion.site/3f83624b737a4fcca96a7fdafcf209f6?v=94fd31fff1244457a85007fdee06a20e)
# ROS2 Humble 설치
[Ubuntu (deb packages) — ROS 2 Documentation: Humble documentation](https://docs.ros.org/en/humble/Installation/Ubuntu-Install-Debs.html)
```
sudo pip install pyqt5==5.15.9
```

#### 환경 설정
[Configuring environment — ROS 2 Documentation: Humble documentation](https://docs.ros.org/en/humble/Tutorials/Beginner-CLI-Tools/Configuring-ROS2-Environment.html#the-ros-domain-id-variable)
export ROS_DOMAIN_ID=<your_domain_id>
로스가 사적인 망을 구축하도록 허용. 같은 팀끼리 통신하기 위해서는 이 도메인 id를 통일해야 됨.
![[Pasted image 20241001121348.png]]
이런 식으로 팀이랑 통일 ㄱㄱ
![[Pasted image 20241001121413.png]]
ID 확인
터미널 간에 ID가 안맞을 수도 있음. 이때 맞춰줘야 터미널 간 통신 가능.

로스1은 TCP, 로스2는 UDP
로스1은 TCP 통신이기에 서버가 필요함. 그래서 roscore가 필요. 그래서 노드가 많아지다면 병목 현상 발생.

##### 터틀심 설치
[Using turtlesim, ros2, and rqt — ROS 2 Documentation: Humble documentation](https://docs.ros.org/en/humble/Tutorials/Beginner-CLI-Tools/Introducing-Turtlesim/Introducing-Turtlesim.html)
#### 리눅스 터미널 명령어 모음
[리눅스 우분투 명령어 간단 정리](https://velog.io/@seoul788/%EB%A6%AC%EB%88%85%EC%8A%A4-%EC%9A%B0%EB%B6%84%ED%88%AC-%EB%AA%85%EB%A0%B9%EC%96%B4-%EA%B0%84%EB%8B%A8-%EC%A0%95%EB%A6%AC)
whoami 치면 현재 유저가 누군지 알려줌 
Vi 배워두면 좋다고 생각

![[Pasted image 20241001115614.png]]
su 치면 이렇게 되누
강사님은 이 상태에서 실행함 (root 상태)

history
이전 명령 다 보기

ll
전체 디렉토리 보기(i 대문자가 아니라 L 소문자임) 

ros2 topic list -t
이렇게 하면 토픽 리스트 + 메시지 형태까지
### 노드의 이해
[Understanding nodes — ROS 2 Documentation: Humble documentation](https://docs.ros.org/en/humble/Tutorials/Beginner-CLI-Tools/Understanding-ROS2-Nodes/Understanding-ROS2-Nodes.html)
![[Pasted image 20240930181455.png]]
노드는 하나의 독립적인 프로그램 단위
Each node in ROS should be responsible for a single, modular purpose, e.g. controlling the wheel motors or publishing the sensor data from a laser range-finder.