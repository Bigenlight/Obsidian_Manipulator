#DevOps
[[DevOps 강의]]
![[데브옵스_1차-1.pdf]]

> [!참고]
> 우분투는 exe가 열리고 deb 파일만 열린다.

데이터 베이스 이용
### MySql 설치
p.17 부터
sudo apt update
sudo apt install mysql-server

#### 실행
실행
sudo systemctl start mysql
아무것도 안 뜨면 정상

재실행
sudo systemctl enable mysql

중단
sudo systemctl stop mysql

##### 비밀번호 설정
sudo mysql -u root

강의자료에서는 대문자인데 소문자로 해야지 작동함
alter user 'root'@'localhost' identified by 'metheo';
flush privileges;
![[Pasted image 20240808102746.png|500]]
여기서 나가기:
exit

다시 들가서 모든 유저 허용
sudo mysql -u root
create user root@'%' identified by 'metheo';
grant all on *.* to root@'%' with grant option;

sudo mysql -u root -p

### 데이터 가져와보기
![[employees.zip]]
압축해제
터미널에서 푸는 방법 있긴한데 귀찮누
![[Pasted image 20240808105303.png]]
/home/theo/Downloads
cd Downloads/employees/
/home/theo/Downloads/employees

==이 위치에서==
###### 파일 가져오기
sudo mysql -u root

이거는 테스트 생성, 꼭 할 필요 없음
create database test;
show databases;
![[Pasted image 20240808111134.png|200]]

source employees.sql;
좀 김
show databases;
![[Pasted image 20240808111708.png|200]]
employees가 생김!!

show tables;
![[Pasted image 20240808115428.png|200]]

잘 안되면 아래 명령러 실행
use employees

desc employees;
![[Pasted image 20240808115452.png|400]]
desc salaries;
![[Pasted image 20240808120208.png|400]]
