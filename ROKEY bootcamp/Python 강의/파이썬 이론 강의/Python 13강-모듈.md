---
Title: Python 13강
tags: 
NeedCheck: 
Review: 
비고:
---
[[Python 이론]]
[[13회차 실습]]
![[Python-13 (1).pdf]]

## 모듈
관련된 상수, 함수 또는 클래스 등을 모아놓은 파일

import 모듈
from 모듈 import 특정함수/클래스

모듈로 부른 변수들도 수정 가능
모듈.변수

from 모듈 import 특정함수/클래스
로 특정 함수나 클래스를 가져오면 모듈. 을 굳이 안써도 ㄱㅊ
![[Pasted image 20240724095745.png|400]]

## \_\_name__
![[Pasted image 20240724095857.png|500]]
import시 \_\_name__ 값이 \_\_main__이 아니게 됨

현재 파일에서 실행하고 있으면 이렇게 나옴.
![[Pasted image 20240724100128.png|200]]

if \_\_name__ == '\_\_main__' : 은 국룰로 자주 쓰임
![[Pasted image 20240724100239.png|400]]
이를 통해 테스트 코드를 여기에 작성하고
다른데에 이를 불렀을 때 실행되지 않게 만들 수 있음

## 패키지
![[Pasted image 20240724100434.png|500]]
모듈 < 패키지 < 라이브러리

### 날짜 모듈
datetime 모듈
```python
from datetime import date
d = date.today()
print(d)
# 오늘 날짜 출력
```
datetime의 time으로 현재 시간 입력 가능
```python
from datetime import time
t = time(12, 35, 25)
print(t)
```
time 모듈과 다름, 현재 시간 체크는 못하는 듯

time 모듈로 현재 시간 체크
```python
import time
print(time.localtime())
```

### 경로와 파일
현재 디렉토라
```python
import os
print(os.getcwd())
```

디렉토리 변경
![[Pasted image 20240724103046.png|400]]

mkdir() - 경로 생성
rmdir() - 경로 삭제
![[Pasted image 20240724103218.png|400]]

os.path.exists() - 경로 또는 파일 존재 확인
os.path.getsize()

os.remove() - 파일 삭제

os.listdir() - 파일과 폴더 목록
glob로도 가능
![[Pasted image 20240724112417.png|300]]

glob을 이용해 특정 파일 가져오기
![[Pasted image 20240724112530.png|400]]
```python
import glob

# "bc.txt"로 끝나는 3글자 파일명
files1 = glob.glob("?bc.txt")
print(files1)

# 확장자가 ".txt"인 모든 파일
files2 = glob.glob("*.txt")
print(files2)

# 모든 파일
files3 = glob.glob("*")
print(files3)

```

## 명령행 인자
명령행 인자(command line arguments)란 파이썬 프로그램을 실행시키면서 사용자가 추가로 입력하 는 값들

파이썬에서 명령행 인자(command-line arguments)는 스크립트를 실행할 때 명령줄에서 제공되는 입력 값입니다. 이를 통해 스크립트를 동적으로 실행하고 다양한 입력을 처리할 수 있습니다.

파이썬에서는 `sys` 모듈의 `argv` 리스트를 사용하여 명령행 인자를 처리할 수 있습니다. `sys.argv`는 ==명령행 인자를 포함하는 리스트로==, 첫 번째 요소(`sys.argv[0]`)는 스크립트의 이름을 포함하고, 그 이후 요소들은 스크립트에 전달된 인자들을 포함합니다.

```python
import glob, sys 
lst = [] # 파일 목록 
if len(sys.argv) == 1: # 파이썬 코드만 있음 
	lst = glob.glob("*") 
else: 
	lst = glob.glob(sys.argv[1]) 
if len(lst) == 0: # 빈 리스트 
	print("매칭되는 파일이 없습니다") 
else: 
	for name in lst:
		print(name)
# 디렉토리 내 파일 열거
```