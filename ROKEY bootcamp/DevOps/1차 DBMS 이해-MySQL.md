![[데브옵스_1차-1.pdf]]

> [!참고]
> 우분투는 exe가 열리고 deb 파일만 열린다.

데이터 베이스 이용
### MySql 설치
p.17 부터
sudo apt update
sudo apt install mysql-server

#### 테스트
실행
sudo systemctl start mysql

재실행
sudo systemctl enable mysql

중단
sudo systemctl stop mysql

##### 비밀번호
sudo mysql -u root

강의자료에서는 대문자인데 소문자로 해야지 작동함
alter user 'root'@'localhost' identified by 'metheo';
flush privileges;
![[Pasted image 20240808102746.png|500]]

CREATE user root@'%' IDENTIFIED BY '1234';
GRANT ALL ON *.* TO root@'%' WITH GRANT OPTION;



![[데브옵스_1차-2.pdf]]