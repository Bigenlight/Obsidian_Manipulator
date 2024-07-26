'''
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
'''
'''
# 3, 4
import turtle as t

t.shape("turtle")

for i in range(4):
    for _ in range(4):
        t.forward(100)
        t.right(90)
    t.forward(200)
    t.right(90)

t.done()
'''
'''
import turtle as t

t.shape("turtle")


for _ in range(6):
    t.forward(100)
    t.right(60)

t.done()
'''
'''
#6
import turtle as t

t.shape("turtle")
t.pencolor("blue")
t.fillcolor("red")

t.begin_fill()
t.circle(100)
t.end_fill()
t.done()
'''
'''
#7
import turtle as t

t.shape("turtle")

t.circle(120, 90)
for _ in range(2):
    t.left(90)
    t.forward(120)

t.done()
'''
'''
import turtle
turtle.speed(0) #숫자가 클수록 빠르게 그립니다. 0는 가장 빠른 속도입니다.
turtle.bgcolor("black") # 배경색
colors = ["red", "yellow", "blue", "green"]
for i in range(100):
    turtle.color(colors[i % 4]) # colors 인덱스를 만들어 색상을 순환시킵니다.
    turtle.forward(i * 4) # 현재 반복 횟수 i에 4를 곱한 만큼 앞으로 전진합니다.
    turtle.left(91)
turtle.done()
'''
'''
#9
import turtle as t

t.shape("turtle")
s = t.Screen()

def move_forward():
    t.forward(20)

def move_backward():
    t.backward(20)

def turn_right():
    t.right(5)

def turn_left():
    t.left(5)

s.onkeypress(move_forward, "Up")
s.onkeypress(move_backward, "Down")
s.onkeypress(turn_right, "Right")
s.onkeypress(turn_left, "Left")

s.listen()

t.done()
'''

#10
import matplotlib.pyplot as plt

x = [1, 2, 3, 4, 5]
y = [2, 3, 5, 7, 11]

plt.scatter(x, y)
plt.title('Problem 10')
plt.xlabel('x')
plt.ylabel('y')

plt.show()


