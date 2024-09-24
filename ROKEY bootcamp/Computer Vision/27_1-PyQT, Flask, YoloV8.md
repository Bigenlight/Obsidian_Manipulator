#컴퓨터비전 
[[Ai,컴퓨터 비전]]
last modification: 2024-09-24

# PyQT - YoloV8
[Site Unreachable](https://colab.research.google.com/drive/1JOpZY6_yXbXBglRunDzyHFkFru44YTPY)

아나콘다 프롬프트로 접근시
cd Downloads/yolov8

#### Thread를 씀
qt는 무조건 event loop이라 thread를 써야 다른 기능 동시 사용 가능.
```python
import threading

th = threading.Thread(target=run)
```

참고로 파이썬에서는 전역 변수를 함수 안에서 사용하려고  할때 변수 앞에 무조건 global를 붙여야 함.

#### 조이스틱
PyQT에서 조이스틱 쓰는 것이 생각보다 쉬움
나중에 필요한 곳에 적용 ㄱㄱ
![[joystick_step_by_step.pdf]]

###### 점심 식사 전 수업:
PyQT 실습 05를 작업한 폴더 복사
- show_qt_05.py
pyqt tlftmq 04에서 작업한 마지막 파일 복사
- myjoystick_07.py
폴더명은 joystick_yolo에 붙여넣기

show_qt_05.py를 joystick_video.py를 참고해서 완성 
push button 2개
Qlabel 1개 
![[Pasted image 20240924141130.png]]

# 코랩으로 FLASK
플라스크를 코딩하는 것은 백앤드 프로그래밍이라고 볼 수 있음
[Site Unreachable](https://colab.research.google.com/drive/1hSxd6zDJhFu3pWZCDOonWS8L9umTuNFq#scrollTo=F4Zsx1wRynYK)

ngrok 로그인하고
![[Pasted image 20240924142600.png]]
토큰 복사해서 가져와야 함.

토큰 설정
![[Pasted image 20240924142747.png]]

서버 예제 코드를 실행하고 아래 링크를 타고 들어가면
![[Pasted image 20240924142851.png]]
![[Pasted image 20240924142907.png|400]]
visit site 클릭
![[Pasted image 20240924142728.png]]
짠!

```python
# Flask 서버 예시
from flask import Flask
app = Flask(__name__)
- - -
app.run()            # web server 실행
```
QT랑 비슷

지금은 리모트로 사이트를 만들고 있기 때문에
\http://127.0.0.1:5000 이런 식의 주소가 아니라
\https://3bee-35-186-145-38.ngrok-free.app 이런 식으로 나오는겨

Flask는 http 처리 무한 루프를 계속 도는겨
Hyper Text Transfer Protocol

web broser에서 http로 webserver랑 통신하면 그에 맞게 html로 알맞게 출력.
Hyper text make up language

##### HTML
\/\*  \*\/ 은 주석임
\<head>는 브라우저에 표시가 안되지만 필요한 특성들을 정의 (이름, 머릿말)
\<body>는 브라우저에 표시 되는 것들 (바디 안에 헤드가 또 있을 수도 있음)
위 헤드랑 바디 같은 것들을 tag라고 함.
\<nav>는 클릭하여 섹션 이동하는 것을 정의


### FLASK + YOLO
욜로가 바로 되는 사이트 게제
![[Pasted image 20240924163155.png]]

이거는 로컬로 해야 함
[Site Unreachable](https://colab.research.google.com/drive/1x6GsMH-HuQgPdcGOdK4JM8tYJW_ce7AX)