---
Title: Python 12강
tags: 
NeedCheck: true
Review: 
비고:
---
[[Python 이론]]
[[12회차 실습]]

![[Python-12 (1).pdf]]
# 객체 지향 프로그래밍
기존 절차지향은 재사용성이 떨어짐

## 클래스
![[Pasted image 20240723111503.png|500]]

![[Pasted image 20240723111535.png|300]]


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