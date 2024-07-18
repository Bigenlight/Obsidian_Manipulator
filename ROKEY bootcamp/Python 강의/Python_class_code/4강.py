
if True:
 print(2**(1/2))

if True:
    print("good1")

if " ":
    print("good2")


if not False:
    print("good3")


if True:
    pass
    print('good')
else:
    pass

if  "3.2" == 3.2:
    print("good2")

'''
num = int(input("정수를 입력해주세요: "))
if num >= 10 : print("정수가 10이상입니다.")
elif num >= 5 : print("정수가 5이상, 10미만입니다.")
else : print("정수가 5미만입니다.")

'''
num = 30
divisor = 0
if divisor != 0 and num / divisor:
    print(f"{num} / {divisor} = { num / divisor }")

'''
working_hour = int(input("일주일 근로시간을 입력해주세요: "))
wage_per_hour = 12000
wage = working_hour * wage_per_hour
if working_hour >= 40:
    wage += ((working_hour - 40) * 0.5) * wage_per_hour
print(f"{working_hour}시간 근무 했을 때 주급은 {wage: .0f}입니다.")
'''
'''
year = int(input("년을 입력하세요: "))
month = int(input("월을 입력하세요: "))
day = int(input("일을 입력하세요: "))

def check_date(year, month, day):
    # 각 달의 일 수
    month_day_count = [31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31]
    # 월이 1에서 12 사이가 아니면 잘못된 날짜
    if month > 12:
        return False
    # 일이 해당 월의 최대 일 수를 넘으면 잘못된 날짜
    if day > month_day_count[month - 1]:
        return False
        
    return True

if check_date(year, month, day):
    print(f"{year}년 {month}월 {day}일은 올바른 날짜입니다.")
else:
    print(f"{year}년 {month}월 {day}일은 잘못된 날짜입니다.")
'''
'''
# 10
over_weight = False
weight = int(input("우편물의 무게를 입력해주세요: "))
if weight <= 5: fee = 400
elif weight <= 25: fee = 430
elif weight <= 50: fee = 450
else: over_weight = True

if not over_weight: print(f"우편물 요금은 {fee}원입니다.")
else : print("우체국에 문의하십시오.")
'''
'''
# 11
T = float(input("건구온도를 기입해주세요: "))
rh = float(input("상대습도를 기입해주세요: "))

def calc_rate(T, rh): return 0.72 * ( T + rh ) + 40.6

def discomfort(x):
    if x <= 68: return "모든사람이 쾌적함을 느낌"
    elif x <= 75: return "불쾌감을 나타내기 시작함"
    elif x <= 80: return "반 정도의 사람이 불쾌감을 느낌"
    else: return "모든 사람이 불쾌감을 느낌"

d = calc_rate(T, rh)

print(f"현재 불쾌지수: {d:.1f}\n사람들이 느끼는 쾌적/불쾌감: {discomfort(d)}")
'''
'''
# 12
import math
print("이차 방적식의 해를 판별하기 위해 계수를 입력해주세요.")
a = float(input("a의 값을 입력하세요: ")) 
b = float(input("b의 값을 입력하세요: ")) 
c = float(input("c의 값을 입력하세요: "))

d = b ** 2 - 4 * a * c

if d > 0:
    print("해는 실수이고 2개의 다른 값이 존재함")
elif d == 0:
    print("해는 실수이고 1개 값만 존재함(중근)")
else:
    print("해는 복소수이고 2개의 다른 값이 존재함")
'''

'''
# 13
p1 = float(input("점의 x 좌표를 입력해주세요:"))
p2 = float(input("점의 y 좌표를 입력해주세요:"))
print("ax + by + c = 0의 값을 차례대로 기입하세요.")
a = float(input("a 값을 입력해주세요:"))
b = float(input("b 값을 입력해주세요:"))
c = float(input("c 값을 입력해주세요:"))

def calc_dis(p1, p2, a, b, c):
    dis = (a * p1 + b * p2 + c) /( (a**2 + b**2)**(1/2) )
    if dis < 0 : dis *= -1
    return dis

print(f"점({p1}, {p2})와 선 {a}x + {b}y + {c} =0 사dl의 거리는 {calc_dis(p1, p2, a, b, c):.3f}이다.")
'''
'''
#14
s1 = float(input("첫 번째 직선의 기울기 입력하세요: "))
s2 = float(input("두 번째 직선의 기울기 입력하세요: "))

if s1 * s2 == -1: print("두 직선은 서로 직교합니다.")
elif s1 == s2: print("두 직선은 서로 평행합니다.")
else: print("두 직선은 서로 평행이나 직교가 아닙니다.")
'''
'''
#15
seat = input("구매하고 싶은 좌석을 입력해주세요: ")
if seat == "VIP" : print("좌석의 가격은 150,000원입니다.")
elif seat == "S" : print("좌석의 가격은 110,000원입니다.")
elif seat == "A" : print("좌석의 가격은 90,000원입니다.")
elif seat == "B" : print("좌석의 가격은 70,000원입니다.")
else : print(f"죄송합니다, '{seat}'는 존재하는 좌석 종류가 아닙니다.")
'''
'''
# 16
import random
n1, n2, n3 = random.randint(1, 99), random.randint(1, 99), random.randint(1, 99)
print(n1, n2 ,n3)
if n3 < n1 > n2 : print(f'가장 큰 정수는 {n1}입니다.')
if n1 < n2 > n3 : print(f'가장 큰 정수는 {n2}입니다.')
if n1 < n3 > n2 : print(f'가장 큰 정수는 {n3}입니다.')
'''
'''
#17
num = int(input('양의 정수를 입력해주세요: '))
i = 0
while i < num:
    i = i + 1
    if num == 1 or num == 2:
        print(f"{num}은 소수입니다.")
        break
    elif i+1 == num:
        print(f"{num}은 소수입니다.")
        break
    elif num % (i+1) == 0:
        print(f"{num}은 소수가 아닙니다.")
        break
'''
'''
# 18
height, weight = 171.0, 72.0
bmi = weight / (height / 100) ** 2
if bmi >= 40: result = "고도 비만"
elif 35 <= bmi : result = "중등도 비만"
elif 30 <= bmi : result = "비만"
elif 25 <= bmi : result = "과체중"
elif 18.5 <= bmi : result = "정상"
else: result = "저체중"

print(f"키: {height:.1f}(cm), 몸무게: {weight:.1f}(kg)")
print(f"BMI: {bmi:.1f} {result}")
'''
'''
# 19
interest = input("관심도(없음, 조금, 보통, 많음, 매우 많음)를 선택하세요): ")
efforts = input("노력도(상, 중, 하)를 선택하세요): ")

if interest in ["보통", "많음", "매우 많음"]:
    if efforts == "상": print("예비 파이썬 고수")
    elif efforts == "중": print("예비 파이썬 중수")
    elif efforts == "하": print("노력 필요")
    else: print(f"죄송합니다, {efforts}(은)는 가능한 노력도 척도가 아닙니다.")

elif interest in ["없음", "조금"]:
    print("파이썬에 대해 관심을 가져 보세요.")
    
else:
    print(f"죄송합니다, {interest}(은)는 가능한 노력도 척도가 아닙니다.")
'''

