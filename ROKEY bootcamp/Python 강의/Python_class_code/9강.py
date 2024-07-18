'''
import os

cwd = os.getcwd()
print(f"Current working directory: {cwd}")

# Corrected file path (removing the ~ and adding absolute path)
file_path = "t.txt"

# Open the file in write mode
with open(file_path, "a", encoding = "utf-8") as f:
    f.write("hello world2 \n")
    # File is automatically closed after this block
# with open(file_path, "r", encoding = "utf-8") as f:
#     s = f.read()
#     print(s)
    
    
with open("t.txt", "r") as f:
	line = f.readline()
	while line:
		print(line, end = "")
		line = f.readline()


with open("1143377-3840x2160-desktop-4k-robot-wallpaper.jpg", "rb") as f:
	s = f.read()
with open("copy.jpg", "wb") as f:
	f.write(s)
 
 
with open("data.txt", "w") as f:
    f.write("Hello\nThis is data.txt\n이 파일은 utf-8 형식으로 저장했습니다\n")
with open("data.txt", "r") as f:
    l = f.readline()
    print(l)

with open("data.txt", "a") as f:
    f.write("Here comes to the end.")
with open("data.txt", "r") as f:
    s = f.read()
    print(s)


with open("python.utf8.txt", "w") as f:
	  f.write("Here comes to the end.")
with open("python.utf8.txt", encoding = "utf-8") as f:
    s = f.read()
    print(s)

'''


import math
    
def rectangle_area(coords):
    x1, y1, x2, y2  = coords # 굳이 split 안해도 ㄱㅊ, 오히려 하면 오류
    width = abs(x1 - x2)
    height = abs(y1 - y2)
    return width * height

def triangle_area(coords):
    x1, y1, x2, y2, x3, y3  = coords
    a = math.sqrt((x2 - x1) ** 2 + (y2 - y1) ** 2)
    b = math.sqrt((x3 - x2) ** 2 + (y3 - y2) ** 2)
    c = math.sqrt((x3 - x1) ** 2 + (y3 - y1) ** 2)
    s = (a + b + c) / 2
    area = math.sqrt(s * (s - a) * (s - b) * (s - c))
    return area

def circle_area(radius):
    return math.pi * (radius ** 2)

with open("shapes.txt", "r") as f:
    l = f.readline()
    list = []
    while l :
        list.append(l.strip())
        l = f.readline()
    
for i in range(len(list)):
    l = list
    coords = []
    if l[i] == "사각형":
        for j in range(1,5):
            coords.append(int(l[i+j]))
        area = rectangle_area(coords)
        print(f"시긱향 넓이는: {area: .1f}")
    elif l[i] == "삼각형":
        for j in range(1,7):
            coords.append(int(l[i+j]))
        area = triangle_area(coords)
        print(f"삼각형 넓이는: {area:.1f}")
    elif l[i] == "원":
        area = circle_area(int(l[i+1]))
        print(f"원 넓이: {area:.1f}")
