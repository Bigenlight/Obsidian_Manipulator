#DevOps
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

#### 실습
[[devops3_1.py]]
데이터베이스에 반영 잘 됨
sql
use TEST;
select * from userTable;
![[Pasted image 20240813004844.png|300]]
#### GUI는 패스




