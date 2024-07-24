class Triangle:
    def __init__(self, x1 = 0, y1 = 0, x2 = 0, y2 = 0, x3 = 0, y3 = 0):
        self.x1 = x1
        self.y1 = y1
        self.x2 = x2
        self.y2 = y2
        self.x3 = x3
        self.y3 = y3

    def calcArea(self):
        return abs((self.x1 * (self.y2 - self.y3) + self.x2 * (self.y3 - self.y1) + self.x3 * (self.y1 - self.y2)) / 2)

    def getCoordsInfo(self):
        self.x1 = int(input("x1 좌표값을 정수로 입력하세요: "))
        self.y1 = int(input("y1 좌표값을 정수로 입력하세요: "))
        self.x2 = int(input("x2 좌표값을 정수로 입력하세요: "))
        self.y2 = int(input("y2 좌표값을 정수로 입력하세요: "))
        self.x3 = int(input("x3 좌표값을 정수로 입력하세요: "))
        self.y3 = int(input("y3 좌표값을 정수로 입력하세요: "))
        
if __name__ == "__main__":
    print("test")
    t = Triangle(0,0,2,0,0,2)
    print(t.calcArea())
    
