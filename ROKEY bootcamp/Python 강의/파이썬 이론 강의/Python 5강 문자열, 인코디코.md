---
Title: Python 5강 문자열, 인코디코
tags: 
NeedCheck: false
Review: 
비고:
---
[[Python 이론]]
[[5회차 실습]]

![[Python-05.pdf]]
## 문자열 처리

len("Hello")
5

a = 'Hello'
a[0]
H

###### 파이썬 문자열은 수정할 수 없음
문자열의 내부 내용을 변경하려고 해도 오류나서 안됨.
가령 a[0] = 's' 이런 식으로 수정 안됨.
==할 거면 b = 's' + a[1:] 이런 식으로 변수 새로 만들고 해야 함.

a.startswith('H') -> True
a.endswith('o' )  -> True
당연하지만 대소문자 구분해야 됨

'H' in a ->True

위치를 알고 싶으면
a.index('o') -> 4
.index(' ', 시작 인덱스, 끝 인덱스)
```python
a = 'Hello'
a.startswith('h')
'H' in a
a.index('o')
```

근데 index() 문제가 찾는 문자열이 없으면 오류 발생
-> 이때는 find() 이용
a.find('a')
find는 못 찾으면 -1 반환.

일반 index,find는 왼쪽 부터 스캔해서 가장 먼저 찾은 위치만 반환.
반대로 하려면
rindex()
rfind()
이 둘은 찾은 것들 중에 맨 뒤의 위치만 표시

###### 해당 문자열이 몇 번 나오는지 검사
![[Pasted image 20240712020223.png|500]]
#### 문자열 제거
.strip()
일단 디폴트 상태면 양쪽에 공백이 있다면 제거.
'sHellos'.strip('s')
양쪽에 해당 문자가 있다면 제거 가능.

.lstrip() 좌측만 제거
.lstrip() 우측만 제거

==이때, 찾는 문자열은 굳이 순서대로 있을 필요는 없음==
```python
"가나다라hello가나다라".strip("라다나가")
"ABCDhelloABCD".strip("DCBA")
# 둘다 출력이 hello임
```
물론 중간에 막히는 글자가 있으면 해당 되는 문자 중에 있는 것까지만 없앰
```python
"가s나다라hello가나다s라".strip("라다나가")
# s나다라hello가나다s
```
#### 문자열 교체 / 수정
.replace( , )
'cold coffee'.replace( cold, hot)
파이썬에서 수정을 하려면 이런 식으로 해야 함.
다행이도 해당 문자열을 못 찾아도 오류는 안남.

#### 문자열 체크
![[Pasted image 20240712020101.png|500]]
###### 단체 변환
![[Pasted image 20240712020157.png|500]]

## 인코딩과 디코딩
==문자 인코딩 -> 문자가 이진으로
문자 디코딩 -> 이진에서 문자로==
아스키, euc-kr (한글 포함 아스키), cp949(마소에서 만든 한글 코드 표, ANSI라도고 함),
유니코드(전세계 언어 통합, 여러 인코딩법 지원, 파이썬은 그중에서 utf-8 사용)

###### UTF-8 인코딩 방식
아스키 128까지는 동일하고 나머지는 1~3바이트로 표현

"a".encode()
a
"가".encode()
b'\xea\xb0\x80'


