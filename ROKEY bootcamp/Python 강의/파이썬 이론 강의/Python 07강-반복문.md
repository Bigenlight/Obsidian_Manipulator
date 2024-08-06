---
Title: Python 7강
tags: 
NeedCheck: 
Review: 
비고:
---
[[Python 이론]]
[[7회차 실습]]

![[Python-07.pdf]]

## 반복문

### While
### For
이런 식으로 문자열로도 반복 가능
for i in "hello" : print(i)

###### range()
![[Pasted image 20240716104952.png|400]]
for i in range(3) # i -> 0,1,2

#### break, continue
for/while 둘다 사용 가능

==for 변수에 관심 없고 반복 횟수에만 관심이 있을 때 변수로 '\_'를 쓴다==
for _ in range(5)