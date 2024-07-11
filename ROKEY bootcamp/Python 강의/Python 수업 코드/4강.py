
if True:
 print("good0")

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
# 10
over_weight = False
weight = int(input("우편물의 무게를 입력해주세요: "))
if weight <= 5: fee = 400
elif weight <= 25: fee = 430
elif weight <= 50: fee = 450
else: over_weight = True

if not over_weight: print(f"우편물 요금은 {fee}원입니다.")
else : print("우체국에 문의하십시오.")

# 11
# 불쾌지수를 계산하는 함수
def calculate_discomfort_index(ta, rh):
    di = 0.81 * ta + 0.01 * rh * (0.99 * ta - 14.3) + 46.3
    return di

# 불쾌지수 수치에 따라 쾌적/불쾌감을 판단하는 함수
def discomfort_level(di):
    if di <= 68:
        return "쾌적"
    elif 68 < di <= 75:
        return "불쾌감을 느끼기 시작함"
    elif 75 < di <= 80:
        return "불쾌함"
    else:
        return "매우 불쾌함"

# 사용자로부터 건구온도(ta)와 상대 습도(RH)를 입력받는다.
ta = float(input("건구온도(섭씨)를 입력하세요: "))
rh = float(input("상대 습도(%)를 입력하세요: "))

# 불쾌지수 계산
di = calculate_discomfort_index(ta, rh)

# 불쾌지수와 그에 따른 쾌적/불쾌감 출력
print(f"불쾌지수: {di:.2f}")
print(f"느끼는 쾌적/불쾌감: {discomfort_level(di)}")

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
import math

# 사용자로부터 이차 방정식의 계수를 입력 받는다.
a = float(input("a의 값을 입력하세요: "))
b = float(input("b의 값을 입력하세요: "))
c = float(input("c의 값을 입력하세요: "))

# 판별식 계산
discriminant = b**2 - 4*a*c

# 판별식의 결과에 따른 해의 형태와 개수 결정
if discriminant > 0:
    print("해는 실수이고 2개의 다른 값이 존재함")
elif discriminant == 0:
    print("해는 실수이고 1개 값만 존재함")
else:
    print("해는 복소수이고 2개의 다른 값이 존재함")
'''
