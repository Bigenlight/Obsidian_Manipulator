---
Title: Python 16강-람다
tags: 
NeedCheck: 
Review: 
비고:
---
[[Python 이론]]
[[16회차 실습]]

![[Python-16 1.pdf]]

# Lambda
파이썬에서 간단한 함수는 한줄에 짧게 쓸 수 있게 만들어주는 기능

![[Pasted image 20240729120843.png|500]]
lamda 인자(매개변수) : 함수내용

이렇게 사용 가능
```python
add_10 = lambda x : x + 10

add_10(11)
#21
```

매개변수 여럿 사용 가능
```python
add = lambda x, y  : x + y

add(4, 5)
```

앞에 변수 없이도 사용 가능
```python
(lambda x : x + 10)(11)
```

람다 안에 변수 선언 불가능.
무조건 한 줄 요약이 가능한 내용이어야.

밖에 있는 변수는 사용 가능. (근데 일반 함수도 전역 변수는 사용 가능)
```python
y = 10
add = lambda x : x + y

add(4, 5)
```

## map()
단체(배열) 함수 적용
리스트, 튜플 등을 집어 넣을 수 있다. (=iterables)
![[Pasted image 20240729133647.png|600]]
func 자리에 람다를 집어 넣을 수 있다.

map() 여러개의 배열을 매개변수에 집어 넣어서 처리하는 것도 가능.
![[Pasted image 20240729134409.png|500]]
이때 한쪽 배열 원소가 더 적어도 작동은 됨.
![[Pasted image 20240729134701.png|400]]

### 람다에 조건문 if, else
- if이 있다면 무조건 else가 있어야 함.
- elif은 불가, else를 여러번 쓰는 방향으로 쓸 것.

![[Pasted image 20240729135327.png]]
참고로 if가 참이라 반환 되는 값이 if 앞에 옴. 조건은 if 뒤에.
else 같은 경우 조건이 없기에 반환 되는 값이 뒤에.
## filter()
![[Pasted image 20240729140128.png|500]]
func이 참과 거짓 둘중에 하나만 반환 할 때 사용 가능.
(True = 0이 아닌 숫자, 차 있는 문자열/리스트
False = 0, None, 빈 시퀀스 등)
True인 것은 남기고 False는 버림.

![[Pasted image 20240729140516.png|400]]

## reduce()
배열 속에 있는 요소들을 누적으로 이용한 함수

파이썬3 부터 고유 함수가 아니라 따로 임포트 해줘야 함.
==from functools import reduce==

![[Pasted image 20240729141228.png|500]]
배열은 하나만 되며, 배열 값 하나와 그동안 계산한 누적 값을 func에 집어넣는다.
그 결과는 다시 누적 값이 된다.
원한다면 시작 누적 값(초기 값)을 설정 할 수 있다.

![[Pasted image 20240729141424.png||300]]




