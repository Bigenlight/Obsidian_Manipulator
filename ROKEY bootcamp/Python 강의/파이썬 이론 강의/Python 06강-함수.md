---
Title: Python 6강-함수
tags: 
NeedCheck: true
Review: 
비고:
---
[[Python 이론]]
[[6회차 실습]]

![[Python-06.pdf]]

## 함수
함수 내부에서 선언한 변수는 내부에서만 사용 됨
##### 만약 외부 변수를 함수 안에 쓰고 싶으면
global var로 가져오면 됨
![[Pasted image 20240715100109.png]]
==global은 안에 써야함!!==
또는 참조자를 쓰면 됨.

#### 기본값 지정
![[Pasted image 20240715095908.png|400]]

### 재귀호출
함수가 자기 자신을 부르는 것
반드시 탈출 가능하게 만들 것
![[Pasted image 20240715100311.png|400]]
==이를 이용해 어느 정도 복잡한 알고리즘 간단하게 구현가능. 복습할 것.==

### 인자 = argument