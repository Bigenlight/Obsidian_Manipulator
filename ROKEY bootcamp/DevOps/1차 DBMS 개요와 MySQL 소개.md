[[DevOps 강의]]
![[데브옵스_1차-2.pdf]]

![[Pasted image 20240808143417.png|400]]
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
select * from employees where emp_no between 495498 and 495599;
![[Pasted image 20240808151613.png]]


select * from employees where emp_no between 495498 and 495599 order by birth_rate;

select * from salaries  where salary between 60000 and 61000 order by salary desk;

###### in()
###### like

###### 서브쿼ㅇ

###### group by

