#컴퓨터비전 
[[Ai,컴퓨터 비전]]
last modification: 2024-09-23

# PyQT

###### PyQT 위키 튜토리얼
[01) 창 띄우기 - PyQt5 Tutorial - 파이썬으로 만드는 나만의 GUI 프로그램](https://wikidocs.net/21920)

이거는 코랩 강의자료
[Site Unreachable](https://colab.research.google.com/drive/1i9n1qsOhVKoPD2GfUzMFw5OH44lqq_mx#scrollTo=K3mapsSHknhQ)    

소스 코드 파일 모음
[Fetching Title#37uu](https://drive.google.com/uc?id=1nYC8lE8htkmeJ7GKT4iqoi5BZ2prefRW)
이거 다운 받고 압축해제

강의자료 기준은 우분투 22.04임

#### 윈도우로 진행해봄
cd .\Downloads\PyQt5\

#### QT 동작 과정
![[Pasted image 20240923095651.png]]

![[Pasted image 20240923095707.png|300]]
인스턴스를 만들고(app)
.exec_()로 무한 루프 돌림.

이런 방식을 event driven라고 함.

 ```python
import sys
from PyQt5.QtWidgets import QApplication, QMainWindow, QWidget, QLabel

app = QApplication(sys.argv)

window = QMainWindow()
window.setWindowTitle('Hello, World! - mainwindow')
window.show()
  
sys.exit(app.exec_())
```
가장 기본적인 창 띄우기
![[Pasted image 20240923101353.png|200]]
QApplication(sys.argv)로 인스턴스 생성하고 .exec_()로 실행.

sys.arg 인자는 코드를 실행 할 때
python code.py <입력하는 값>
이런 식으로 입력 되는 값을 의미.

[Site Unreachable](https://colab.research.google.com/drive/1i9n1qsOhVKoPD2GfUzMFw5OH44lqq_mx#scrollTo=hqHYXOVqyrrF)
코랩에 코드 목록 있음

- main window
- Layout
	-절대 좌표 배치
	-box
	-grid
- widget - 21개

[Site Unreachable](https://colab.research.google.com/drive/1Hggshd7QXgbnvjqmZxQ5srfpNYf43BuW)
[Site Unreachable](https://colab.research.google.com/drive/1S5YxZQZnK8y-c3TvpGyfWzJScVyjaKnU)
[Site Unreachable](https://colab.research.google.com/drive/1NYjIE0dNgfhFXPi3QTp9vTITzGeXLZND#scrollTo=WN1S0IxrCSAp)

Qapplication
- signal -> event
- slot -> call back function

![[Drawing 2024-09-23 17.32.42.excalidraw|600]]


### YoloV8 Ubuntu 22.04 디버그
만약 위에 있던 코드들이 우분투에서 안되면
sudo apt-get update  
sudo apt-get upgrade  
sudo apt-get install --reinstall libxcb-xinerama0  
  
시도후 불가하면
sudo apt-get install qtwayland5  
sudo apt-get install libqt5waylandclient5 libqt5waylandcompositor5

그래도 안되면
pip install --upgrade pyqt5 opencv-python-headless
# 과제
pyqt5 폴더에 있는 모든 파일 실행해보고 캡쳐하기

