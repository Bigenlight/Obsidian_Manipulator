
[[DevOps 강의]]
![[데브옵스_2차-1.pdf]]
![[데브옵스_1차-2 1.pdf]]
sudo mysql -u root

##### 숫자 데이터 형식
![[Pasted image 20240809095537.png]]
##### 문자 데이터 형식
![[Pasted image 20240809095618.png]]
##### 날짜와 시간
![[Pasted image 20240809095848.png]]

## 이너, 아우터 조인
- **INNER JOIN**: 두 테이블 간에 공통된 값이 있는 행들만 포함.
- **OUTER JOIN**: 모든 행을 포함하지만, 일치하지 않는 경우 `NULL`로 표시.

if
select if (100>200, '오', '안됑');
![[Pasted image 20240809101127.png|300]]

case
![[Pasted image 20240809102134.png|300]]

ascii(), char()
![[Pasted image 20240809102512.png|300]]

테이블 삭제
DROP TABLE IF EXISTS userTBL;

메모장 만들고 확장자를 sql로 하면 코드가 예쁘게 보임 
![[devops_code.sql]]

아래 명령어 터미널에 복붙하면 테이블을 새로 만들 수 있음
```sql
DROP TABLE IF EXISTS usertbl;
CREATE TABLE usertbl
(
    userID CHAR(8) NOT NULL,
    name VARCHAR(10) NOT NULL,
    birthYear INT NOT NULL,
    CONSTRAINT PRIMARY KEY PK_usertbl_userID (userID)
);

```

```sql
CREATE TABLE buytbl
(
    num INT AUTO_INCREMENT NOT NULL PRIMARY KEY,
    userid CHAR(8) NOT NULL,
    prodName CHAR(6) NOT NULL,
    groupName CHAR(4) NULL,
    price INT NOT NULL,
    amount SMALLINT NOT NULL,
    FOREIGN KEY(userid) REFERENCES usertbl(userID)
);

```
show tables; 로 볼 수 있음
```sql
INSERT INTO usertbl VALUES('LSG', '이승기', 1987);
INSERT INTO usertbl VALUES('KBS', '김범수', 1979);
INSERT INTO usertbl VALUES('KKH', '김경호', 1971);

INSERT INTO buytbl VALUES(NULL, 'KBS', '운동화', NULL, 30, 2);
INSERT INTO buytbl VALUES(NULL, 'KBS', '노트북', '전자', 1000, 1);
INSERT INTO buytbl VALUES(NULL, 'KKH', '모니터', '전자', 200, 1);
```
select * from usertbl;
![[Pasted image 20240809145103.png|300]]
select * from buytbl;
![[Pasted image 20240809145037.png|300]]
이때 userid로 서로를 맺었기 때문에 다른 userid로 insert 시도하면 오류남.
![[Pasted image 20240809145226.png]]

### 압축
압축하면 공간은 저축되지만
실행 시간이 확실히 느려짐.

장단점이 있음. 근데 요즘은 압축해도 나른 성능 좋아서 필요하면 쓸 것.

##### 압축 실습
```sql
-- 테이블 생성
CREATE DATABASE IF NOT EXISTS compressDB;
USE compressDB;

CREATE TABLE normalTBL( 
    emp_no int, 
    first_name VARCHAR(14)
);

CREATE TABLE compressTBL( 
    emp_no int, 
    first_name VARCHAR(14)
)
ROW_FORMAT=COMPRESSED;

-- 데이터 입력
INSERT INTO normalTBL
    SELECT emp_no, first_name FROM employees.employees;

INSERT INTO compressTBL
    SELECT emp_no, first_name FROM employees.employees;
```
압축 테이블 생성이 두배 느림.

### 테이블 수정
#### ALTER TABLE = 테이블 변경
ALTER TABLE을 여러 곳에서 활용
###### 열 삭제
```SQL
USE tabledb;
ALTER TABLE usertbl
    ADD homepage VARCHAR(30) -- 열 추가
    DEFAULT 'http://www.hanbit.co.kr' -- 디폴트 값
    NULL; -- Null 허용함
```
###### 열 삭제
ALTER TABLE 테이블
	DROP COLUMN 열;
###### 키 삭제
ALTER TABLE 테이블
	DROP PRIMARY KEY;
### 뷰
![[Pasted image 20240809162519.png]]

간편하게 보여주고 싶은 것만 보여주기 가능.
복잡한 쿼리를 단축키 처럼 사용 가능.
```SQL
USE employees;
CREATE VIEW v_usertbl
AS
    SELECT userid, name FROM usertbl;
```
```SQL
SELECT * FROM v_usertbl; -- 뷰를 테이블이라고 생각해도 무방
```
![[Pasted image 20240809162912.png|200]]
아이디랑 이름만 보이게 만듬.
###### 뷰의 장점
- 보안에 도움 됨
- 사용자 입장에 간단한 쿼리로 이용 가능


# 실습을 통해 알게 된 것
1번 문제
서로 테이블에 맞는 열이 없어 어떻게 조인하나 했는데
그냥 중간다리를 만들면 됨.
이를 통해 서로 연결 되있지 않은 직원과 부서명 테이블이 연결 됨.
```sql
SELECT a.first_name, a.last_name, b.dept_name
FROM employees a
JOIN dept_emp c ON a.emp_no = c.emp_no
JOIN departments b ON c.dept_no = b.dept_no;

```

5번 문제
###### 테이블 복사
CREATE TABLE employees_copy LIKE employees; -- 구조만 복사 됨
CREATE TABLE employees_copy AS SELECT * FROM employees; -- 데이터까지 복사

6번 문제
###### 유일한 값 조사
SELECT DISTINCT first_name, last_name  FROM employees_copy;
이를 이용한 중복값 제거는 나중에

###### 날짜 사용
UPDATE employees_copy
SET salary = salary + 500
WHERE hire_date = '1997-11-30';
날짜는 '  ' 안에 지정해야 함.