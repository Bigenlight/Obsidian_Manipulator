---
Title: Python 15강
tags: 
NeedCheck: 
Review: 
비고: 여기는 안 나올 것 같긴 함
---
[[Python 이론]]
[[15회차 실습.py]]


![[Python-15.pdf]]

## 터틀
터틀봇으로 그림 그리기


## PyQt

![[Pasted image 20240726122125.png]]
이게 PyQt5 API 실사용
```python
import sys
from PyQt5.QtCore import *
from PyQt5.QtGui import *
from PyQt5.QtWidgets import *

def window():
    app = QApplication(sys.argv)
    w = QWidget()
    b = QLabel(w)
    b.setText("Hello World!")
    w.setGeometry(100,100,200,50)
    b.move(50,20)
    w.setWindowTitle("PyQt5")
    w.show()
    sys.exit(app.exec_())

if __name__ == '__main__':
    window()
```

클래스로 쓰면
```python
import sys
from PyQt5.QtCore import *
from PyQt5.QtGui import *
from PyQt5.QtWidgets import *

class window(QWidget):
    def __init__(self, parent = None):
        super(window, self).__init__(parent)
        self.resize(200,50)
        self.setWindowTitle("PyQt5")
        self.label = QLabel(self)
        self.label.setText("Hello World")
        font = QFont()
        font.setFamily("Arial")
        font.setPointSize(16)
        self.label.setFont(font)
        self.label.move(50,20)

def main():
    app = QApplication(sys.argv)
    ex = window()
    ex.show()
    sys.exit(app.exec_())

if __name__ == '__main__':
    main()
```
>>>>>>> e2deeb9d33184862460dc0ea2e3c9e7ed59a66a7
