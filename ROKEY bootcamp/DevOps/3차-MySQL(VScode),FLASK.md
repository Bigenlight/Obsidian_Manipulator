
[[DevOps 강의]]

![[DevOps프로그래밍_3차.pdf]]
## MySQL 외부 접속 (VScode)
#### 외부 접속 계정 생성
sudo su -

nano /etc/mysql/mysql.conf.d/mysqld.cnf

주석해제
주소 0.0.0.0으로 변경

sudo ufw enable
ufw status

systemctl restart mysq
sudo mysql -u root -p

create user 'tester2'@'%' identified by '0000';
Grant all privileges on *.* to 'tester2'@'%';
Flush privileges;
Exit ;
systemctl restart mysql 

sudo mysql -u root -p

##### 예시 테이블 생성
use TEST;
create table test ( id int, name varchar(20) );
insert into test values (0, 'kkk');

##### 라이브러리 설치
sudo pip install pymysql
pip install mysql-connector-python

##### vscode로 실행
[[mysql_devops3.py]]
python3 -u "/home/theo/Opsidian_Manipulator/ROKEY bootcamp/Python 강의/Python 수업 
코드/mysql_devops3.py"

이상하게 python 뒤에 3을 수동으로 붙여야함.

### 파이썬으로 관리하는 MySQL
![[Pasted image 20240812120739.png]]
import pysql
```python
c = mysql.connector.connect(
host="localhost",
user="tester2",
passwd="0000",
database="TEST"
)
```
user = 'root' 도 됨.

##### 커서 생성
cur = c.cursor()
SQL 문을 실행하거나 결과를 돌려받을 때 필요.

###### execute - 테이블 만들기
cur.execute('create table if not exists userTable ( id char(4), userName char(15), birthYear int );')
###### 데이터 저장
파이썬에서 입력한 데이터는 그 즉시 저장되는 것이 아님.
커밋을 해야지 데이터베이스에 저장 됨.
conn.commit()
###### 닫기
conn.close()

python3 -u "/home/theo/Opsidian_Manipulator/ROKEY bootcamp/DevOps/devops3_1.py"

#### GUI는 패스


## 웹 - FLASK
Python으로 작성된 오픈 소스 웹 프레임워크
• 코드도 비교적 단순하며 API 서버 구축에 편리함
• 다른 프레임 워크에 비해 비교적 확장하기 용이하고 유연함
[Welcome to Flask — Flask Documentation (2.2.x)](https://flask.palletsprojects.com/en/2.2.x)
### 가상 환경 설정
sudo apt install python3-venv
python3 -m venv webwork
###### 실행
cd webwork/
source ./bin/activate
![[Pasted image 20240812140614.png|300]]
###### 나가기
deactivate

해당 경로에 작업 가능
![[Pasted image 20240812141152.png]]
터미널도 자동으로 가상 환경으로 감

만약 권한이 안된다면 chmod 777 ./경로 이용할 것

#### FLASK 설치
pip install Flask

html : 웹 사이트 프레임
css : 데코레이션
cgi(common gate inteerface) : 동적인 사이트를 위한 코드
#### 웹 코딩

```python
from flask import Flask, render_template
app = Flask(__name__)

@app.route('/') # 웹 주소

def hello_world():
	return 'Hey'
	
if __name__ == '__main__':
	app.run()
```
사이트 ip 주소 복사하여 인터넷 창에 붙여넣기
![[Pasted image 20240812145408.png|400]]
[127.0.0.1:5000](http://127.0.0.1:5000/)

만약 5000을 이미 누가 쓰고 있다면
app.run(port = 10001)
이런 식으로 뒤에 포트를 바꿀 것

##### 폴더 생성
static: css, js 파일들 
templates: html 파일들
이때 폴더 철자가 틀리면 작동 안함.
![[Pasted image 20240812145949.png|200]]
```python
# Test1.py
from flask import Flask, render_template

app = Flask(__name__)

@app.route('/')
def hello_world():
	return render_template('index.html')

if __name__ == '__main__':
	app.run(debug=True)
```
templates 폴더 안에 index.html 생성
```html
<!DOCTYPE html>
<html lang="en">
<head>
	<meta charset="utf-8">
	<title>hi</title>
</head>
<body>
	<h1>hello world</h1>
</body>
</html>
```

#### 변수 넣기
파이썬 파일에서 name 변수를 지정하고
name_ = '최태오'
return render_template('index.html', name=name_)
html 파일에서 {{name}}포함하면 파이썬 코드 값이 들어감
\<h1>hello world {{name}}</h1>
![[Pasted image 20240812152712.png]]

페이지끼리 옮기는거 못함.

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
cd webwork/
source ./bin/activate
![[Pasted image 20240812161500.png|400]]
도커 파일은 확장자가 없다!
```
flask==3.0.3
```


sudo docker ps -a
