---
Title: Python 12강
tags: 
NeedCheck: true
Review: 
비고:
---
[[Python 이론]]
[[12회차 실습]]
[[python_12_class.py]]

![[Python-12 (1).pdf]]
# 객체 지향 프로그래밍
기존 절차지향은 재사용성이 떨어짐

> [! 인스턴스란?]
> 인스턴스란 객체 지향 프로그래밍(Object Oriented Programming)에서 class에 소속된 개별적인 객체를 말한다.
> 예를 들어, user라는 클래스를 정의하고 hong이라는 객체를 생성할 경우, hong이라는 객체는 user라는 클래스의 인스턴스가 된다. 하나의 클래스를 사용하여 유사한 성질을 가진 수많은 인스턴스를 생성할 수 있다.

## 클래스
![[Pasted image 20240723111503.png|500]]

![[Pasted image 20240723111535.png|300]]
각각 설명에 대해 문제로 나옴. 복습해야할 듯.
(1) **추상화 (Abstraction)**: 사물 또는 개념을 컴퓨터에서 처리할 수 있을 수준으로 축약하고 핵심을 추출
(2) **캡슐화 (Encapsulation)**: 필요한 정보와 인터페이스만을 공개하고, 나머지 자세한 구현 내용들을 숨김
(3) **상속 (Inheritance)**: 자식 클래스는 부모 클래스의 모든 속성과 함수들을 물려받음
(4) **다형성 (Polymorphism)**: 상속 관계의 여러 클래스들에서 동일한 명칭으로 구현된 함수들이 각각 다르게 작동

#### 클래스 생성 및 생성자
![[Pasted image 20240723111918.png|400]]
객체 생성
![[Pasted image 20240723111956.png|350]]

###### 사용 요령
![[Pasted image 20240723112147.png|400]]
def\ \_\_init\_\_(==self,== 나머지 매개_변수 ):

생성자 추가 설명
![[Pasted image 20240723112353.png|400]]
변순 앞에 self 잊지 말 것(여기 뿐만 클래스 내부 전역으로 쓸거면 계속 self를 적어야 함.)
사실상 클래스 속 시작 변수들은 다 여기서 생성하고 (그냥 클래스 함수가 아닌 빈 공간에 정의하는 것으로 안됨.(좋은 예시는 아니긴한데 클래스 밖에서 전역 변수를 생성하면 클래스 안에서는 사용 가능))

#### 클래스 속 변수
![[Pasted image 20240723120515.png|400]]
'객체.변수명'으로 기본적으로 클래스 외부에서도 참조가 가능 하지만
==만약 변수 앞에 '\_\_'를, 즉 언더바 두개로 변수를 private으로 변경 가능.==
하지만 엄밀히 얘기하자면 접근이 어려운거지 불가능한 것이 아니다. 파이썬에서 엄격하는 제한은 없다. 
언다바 두개는 변수 뿐만 아니라 ==함수 앞에도 작성하면 접근이 어려워진다.==

클래스 안에서 이렇게 생성했다면.
```python
self.__battery = 55
```
외부에서 참조가 안된다.(원래는 가능)
```python
a.__battery # 오류
```

참고로 self.변수는 꼭 생성자에서만 새로 만들 수 있는 것은 아니다. 다른 함수에서도 가능. 하지만 그냥 클래스 빈 공간에서는 안됨.

### 상속
부모 클래스에 있는 함수를 자녀 클래스에서 다시 정의하는 것을 ==오버라이딩==이라고 함.

![[Pasted image 20240723112657.png|500]]

![[Pasted image 20240723113246.png|400]]
- ==부모와 자식이 모두 생성자가 있고, 자식이 부모의 변수들을 이용하고 싶으면 자식 클래스에서 super().\_\_init__(가져 오는 부모 매개변수 명)으로 부모의 생성자를 호출해야 함.==
- ==그게 아니면 그냥 super 안쓰고 오버라이딩 해도 ㄱㅊ.==
- 부모가 생성자가 없으면 딱히 상관 없음.
- ==자식이 생성자가 없으면 부모 생성자를 그대로 이용. 자동으로 부모 생성자 변수를 가져옴.==


상속 예시
```python
import math 
class Shape: 
	def __init__(self, shapeStr): 
		self.shapeStr = shapeStr 
	def getShapeStr(self): 
		return self.shapeStr 
		
p = Shape("example")
print(p.getShapeStr()) # example 출력

class Circle(Shape): 
	def __init__(self, shapeStr, x, y, r):
		super().__init__(shapeStr) 
		self.x = x 
		self.y = y 
		self.r = r 
	def calcArea(self): 
		return math.pi * self.r * self.r

c = Circle("Circle", 1, 2, 3)
print(c.getShapeStr()) # Circle 출력
print(c.calcArea()) # 넓이 출력
```
super()로 부모의 shapeStr 변수를 가져옴.

###### super().func 사용예시
```python
# 아래와 같은 클래스가 있을 때
class ex_class :
    def __init__(self, i = 1):
        self.n = i
    def ex_func(self, a, b):
        return (a + b) * self.n
# 상속 했을 때
class child_ex_class(ex_class):
    def child_ex_func2(self, a, b):
        base_result = super().ex_func(a, b)  # 부모 함수를 그대로 가져옴
        return base_result + (a * b) * self.n
```
즉 부모의 클래스 결과를 가져오는 용도.
이건 오버라이딩임 아님. 오버라이딩은 함수 이름 부모와 똑같이 써서 덮어 쓰는 것.