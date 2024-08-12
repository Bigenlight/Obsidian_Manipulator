
[[DevOps 강의]]

![[DevOps프로그래밍_3차.pdf]]

# DOCKER
(도커 설치는 오티 전에 했음)
venv와 다르게 메모리 접근 가능.
그래서 완전 가상 환경은 아님.
그렇기에 보안성 문제 존재

도커 이미지를 통해 쉽게 공유 가능.

독립성을 보장받아 다른 컨테이너와도 독립 환경 보장.

![[Pasted image 20240812160633.png]]
도커 이미지에는 컨테이너 설계도가 있음.
변경 불가능.
컨테이너는 쓰기 가능.
이미지가 없으면 안됨.

Dockerizing : 컨테이너를 사용하여 프로그램을 패킹, 배포, 실행하는 과정.

### 도커 명령어
###### 컨테이너 만들기 docker run \[옵션] 이미지명\[:태그명] \[인수]
• docker run --name \[만들 컨테이너 이름] -it \[pull 시킬 이미지]
• 
###### 컨테이너 port 번호로 실행
• docker run -p 8080:80 nginx:latest
###### 컨테이너 이름 바꾸기
• docker rename \[현재 이름] [바꿀 이름]
###### 실행(Up) 중인 컨테이너들의 목록을 확인
• docker ps -a
###### 컨테이너 시작 : docker start
-ai 옵션 : 해당 컨테이너 내부로 접근
docker start -ai [컨테이너명]
###### 실행 중인 컨테이너를 종료 : docker stop
docker stop [컨테이너명]
###### 컨테이너 접속
docker exec -it [컨테이너명] /bin/bash

도커 상태:
docker stats
###### 도커 실행 예시
docker run -dit --name test --cpus=0.3 stress
###### 삭제
칸테이너 삭제
docker rm
이미지 삭제
docker rmi

네트워크 확인
ip addr

##### 우리가 만든 FLASK를 도커라이징하기
[[3차_2-FLASK]]
cd webwork/
source ./bin/activate
![[Pasted image 20240812161500.png|400]]
도커 파일은 확장자가 없다!
```
flask==3.0.3
```


sudo docker ps -a