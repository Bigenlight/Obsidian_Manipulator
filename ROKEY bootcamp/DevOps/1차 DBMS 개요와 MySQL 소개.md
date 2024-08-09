[[DevOps 강의]]
![[데브옵스_1차-2.pdf]]

![[Pasted image 20240808143417.png|400]]
# DBMS 개요
데이터베이스 : 데이터의 집합
여러명의 사용자나 응용프로그램을 공유하는 데이터들.
동시에 접근이 가능해야 함.
데이터의 저장 공간 자체의 의미로도 쓰임

**DBMS: Database Management System**
데이터베이스를 관리 운용하는 역할.
![[Pasted image 20240809161548.png|400]]
대령의 데이터를 관리하는데 필요함.
보안, 안전, 유지보수 측면에서 좋음.

SQL: Structured Query Language
dbms에 데이터를 구축, 관리, 활용하는데 사용하는 언어.

동일한 데이터가 여러 개 중복 저장하는 것을 방지
대부분의 dbms 시스템들이 백업과 복원 기능을 제공.
## SQL 사용
[[1차 MySQL 설치 및 실행]]
#### 실행
정상적으로 설치 및 환경을 세팅했다면

sudo mysql -u root

use employees

select * from employees.titles;
select * from titles;

\*는 모든 인자를 가져오는 것

select first_name, last_name, gender from employees;
전 직원의 이름과 성별을 가져옴.
![[Pasted image 20240808142937.png]]
열이 6개 (열 상태를 열거하기 위해 위 테입을에서는 행 위치로 배치)

select birth_date from employees; -- 생일 열만 가져 옴

\-- 이거 이후는 주석이라는 뜻!

###### where
특정 조건에 맞는 것만 가져옴
from 테이블명 where 조건식;

select first_name, last_name, gender from employees where first_name='Jiyoung'; -- 이름이 지영인 사람만 찾기

or/and, < = != 등도 사용 가능.

select first_name, last_name, gender from employees where first_name='Jiyoung' and last_name='Peir'; -- 
![[Pasted image 20240808150759.png]]

select * from employees where first_name='Jiyoung' and last_name='Peir'; 
![[Pasted image 20240808150811.png]]

###### between - and - 
값의 범위로 검색, < 랑 같은 듯. 데이터가 숫자일 때만 사용 가능.
select * from employees where emp_no between 495498 and 495599;
![[Pasted image 20240808151613.png]]

select * from employees where emp_no between 495498 and 495599 order by birth_rate;

select * from salaries  where salary between 60000 and 61000 order by salary desk;

###### in()
데이터가 숫자가 아닐 때 여러개 검색.
![[Pasted image 20240808162242.png]]
select * from employees where first_name in ('Jiyoung', 'Zito');
###### like
저번에 파이썬에서 배운 정규표현식과 비슷
![[Pasted image 20240808162517.png]]
![[Pasted image 20240808162439.png]]
select * from employees where first_name like ('Z%');
![[Pasted image 20240808162544.png|400]]


###### 서브쿼리
###### order by - 정렬

###### group by

select max(emp_no), avg(salary) from salaries group by salary;

###### 집계용 함수
![[Pasted image 20240808161204.png|500]]

### 데이터 수정
###### insert
###### update
###### delete


MySQL 데이터 형식 종류 정리
![[Pasted image 20240808162737.png]]


499999 직원들 월급 10퍼 인상 시키기
UPDATE salaries SET salary = salary * 1.10 WHERE emp_no =499999;