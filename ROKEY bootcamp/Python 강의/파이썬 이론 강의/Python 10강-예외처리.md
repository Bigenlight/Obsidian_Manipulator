---
Title: Python 10강-예외처리
tags: 
NeedCheck: true
Review: 
비고: 처음 배움
---
[[Python 이론]]
[[10회차 실습]]
![[Python-10 (3).pdf]]

# 예외 처리
### 오류
- 문법 오류
- 논리 오류
- 실행 오류

## try: , except:
오류가 발생해도 프로그램 종류 x -> except로 빠짐.
except는 필수이고, 안에 pass라도 적혀있어야 함.
except 후에 꼭 오류의 종류를 적을 필요는 없음.
```python
try:
  num = int(input("정수를 입력: "))
except: # 얘가 없어도 오류
  pass # 내용이 없어도 오류
```

오류 개별 대응, 그리고 전부 대응도 가능. 
![[Pasted image 20240719020507.png|400]]
참고로 오류가 발생하면 그 즉시 except로 간다.

### 오류 종류
![[Pasted image 20240719020624.png]]

#### sys.exit() 함수
import sys로 sys.exit() 사용 가능.
sys.exit()은 실행 파일을 종료 시킴.
![[Pasted image 20240719020840.png|400]]
참고로 이건 코랩에서는 안됨.

#### raise
오류를 의도적으로 발생 시켜 excpetion으로 감
raise 뒤에 오류 종류 지정.
```python
try:
  num = int(input("정수를 입력: "))
  if num < 0:
    raise ValueError
  print(num)
except:
  print("error")
```

Exception("오류")로 어떤 종류인지 정의 가능
```python
try:
  num = int(input("정수를 입력: "))
  if num < 0:
    raise Exception("의도적으로 발생한 오류")
  print(num)
except:
  print("error")
```

except Exception as e: 라 하면  e로 에러 발생 요인도 출력 가능.
![[Pasted image 20240719024358.png|400]]
물론 꼭 raise Exception()

try 안에 try에러가 발생했을 때 
except 속에서 raise를 하면 그 오류가 밖에서도 재발생.
-> re-raise
![[Pasted image 20240719030054.png|400]]


### finally:
![[Pasted image 20240719030238.png|500]]
정상적이든, 오류가 발생하든 결국 블록 마지막에 실행이 되는 코드

### else:
`else` 블록은 `try` 블록에서 예외가 발생하지 않을 때 실행됩니다. 이렇게 하면 예외가 발생하지 않을 경우에만 실행하고 싶은 코드가 있을 때 유용합니다.
```python
try:
    result = 10 / 0
except ZeroDivisionError as e:
    print("Cannot divide by zero:", e)
#print("hey")
else:
    print("Division successful, result is:", result)

```
else와 except 사이에 아무것도 못 쓴다. 순서도 중요하다. else가 except 보다 먼저 오면 안된다.