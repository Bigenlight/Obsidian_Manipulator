[[Python 이론]]
[[4회차 실습]]
![[Python-04.pdf]]
## 조건문
문자열을 비교할 때 영문이 한글보다 작음.
"abcd" < "가나다라"
또 영어에서 대문자가 소문자보다 작음.
"A" < "a"
특수 기호가 영어 알파벳보다 작음
"!" < "A"

boolean도 서로 비교 가능. 
True가 1이니 False 보다 큼.

물론 서로 다른 자료형은 비교가 불가능.
But
1 < 1.1
같이 정수형과 실수형 정도는 섞어서 사용 가능.

## IF
들여쓰기는 tab 뿐만 아니라 일반 스페이스바도 가능.
한 블록 안에서 같은 것을 쓰기만하면 괜찮다.
```python
if True:
 print("good")
if True:
    print("good")
```

Boolean이 아니어도 다른 자료형도 참/거짓 판별 가능.
숫자는 0이면 False, 다른 것들은 비어있으면 False임.
예를 들어 ""는 False, " "는 True이다.

## 논리 연산자
And, or ,not
생각해보니 그동안 not을 쓴적이 없네.
```python
if not False:
    print("good")
```

### 단락 평가
and나 or에서 좌측이 참/거짓이 판별 돼서 우측을 굳이 계산 필요 없으면 굳이 계산 안함.
그래서 우측에 오류 코드가 있어도 그냥 실행 됨.

### 우선순위
![[Pasted image 20240711101000.png|600]]

#### pass 문
아무것도 하지 않아도 괜찮게 하는 명령.
```python
if True:
    pass
else:
    pass
```
if와 else 모두 안에 아무것도 없으면 오류가 뜸, 뭐라도 적어야 함.
그때 pass를 적어 놓는다. 
pass가 있어도 안에 뭐가 있으면 그게 실행됨.
```python
if True:
    pass
    print('good') # 여전히 출력됨
```
