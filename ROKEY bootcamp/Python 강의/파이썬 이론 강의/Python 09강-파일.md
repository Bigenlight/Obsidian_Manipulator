---
Title: Python 09강-파일
tags: 
NeedCheck: 
Review: 
비고: 실습 보다는 이론 문제로 나올 듯
---
[[Python 이론]]
[[9회차 실습]]

![[Python-09.pdf]]

pwd -> 현재 위치 출력
![[Pasted image 20240718120745.png]]

import os
os.getcwd()
-> 현재 디렉토리 출력
```python
import os
cwd = os.getcwd()
print(f"Current working directory: {cwd}")
```
![[Pasted image 20240718120908.png]]

## File
파일의 기본 속성
![[Pasted image 20240718121132.png]]
- 텍스트 파일 및 소스코드 파일은 기본 텍스트 편집기로 편짐 가능
- 바이너리 파일(이진화된 파일)은 기본저긍로 다른 프로그램으로 열어야 제대로 볼 수 있음.
둘이 확장자로 구별 가능

#### 읽기 Read
파일_변수 = open(파일_이름) <- 디폴트가 r임
f = open("t.txt", 'r')
#### 쓰기 Write/Append
지우고 새로 쓰기(파일이 없다면 생성)
파일_변수 = open("파일 이름", 'w')
내용 추가하기(파일이 없다면 생성)
파일_변수 = open("파일 이름", 'a')

참고로 w, a 모드일때 read가 안됨. read는 r 모드 일 때만

![[Pasted image 20240718120145.png|500]]
![[Pasted image 20240718120207.png|500]]
```python
with open("t.txt", "r") as f:
	line = f.readline()
	while line:
		print(line, end = "") # 문서에 이미 \n이 포함 됐다면 이걸 해야 두칸씩 안뜀
		line = f.readline()
```
list_ = f.readlines()를 쓰면 각 줄이 리스트의 원소로 들어감

### ==With 문==
원래 f = open() 후 f.close()는 필수지만
이렇게 하면 뭔가 불편할 수도 있고, 까먹을 수도 있음

```python
with open() as f:
	s= f.read()
```

이런 식으로 with 오픈 as 방식으로 작성하면 블록이 끝나고 close를 자동으로 해줌!

## 인코딩
현재 pc 디폴트 인코딩 방법 체크
\>>> import locale 
\>>> locale.getpreferredencoding()

우분투 22.04 기준
![[Pasted image 20240718111705.png]]

이 형식과 다른 파일을 읽으면 오류가 남 

파일을 읽을 때 특정 인코/디코딩 방식을 지정할 수 있음.
![[Pasted image 20240718114453.png]]

### 바이너리 읽기/쓰기
비슷한데 w가 아니라 wb고, r이 아니라 rb로 쓰면 됨
바이너리로 이미지 복사하기
```python
with open("1143377-3840x2160-desktop-4k-robot-wallpaper.jpg", "rb") as f:
	s = f.read()
with open("copy.jpg", "wb") as f:
	f.write(s)
```
이런식으로 복사도 가능