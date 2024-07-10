a = 5
b = a

a += 1

print(b)


print("area: %s" % "Baldur's Gate") 
print("temp: %d" % 10)

print("area: %s, temp: %d, damage: %d" % ("Baldur's Gate", 18, 23 * 2 )) 

print("%10s" % "last")
print("%10d" % 10)
print("%10f" % 2.2)

print("%d%%" % 1)

#input("Calculator \nPlease type an 1~100 number \nInput: ")


print("%d" % 1.1)
print("%.1f" % 1)


print("%.1f" % 1.05)
print("%.1f" % 1.04)
print("%.0f" % 1.6)

x1 = 1.23
x2 = 12.3
x3 = 123.456

# 소수점 기준으로 정렬된 출력
print(f"{x1:8.3f}")
print(f"{x2:8.3f}")
print(f"{x3:8.3f}")

x1 = 1.23; x2 = 12.3; x3 = 123.456
print(f"{x1:10.3f}\n{x2:10.3f}\n{x3:10.3f}")

print(f"\{{}} ")



_100g_coffee = 10000
_200g_coffee = _100g_coffee * 2
_300g_coffee = _100g_coffee * 3
_400g_coffee = _100g_coffee * 4

print(f"커피 원두 200g 가격: {_200g_coffee}원 \
    \n커피 원두 300g 가격: {_300g_coffee}원 \
    \n커피 원두 400g 가격: {_400g_coffee}원")

price = _100g_coffee = 10000
price += _100g_coffee 
print(f"커피 원두 200g 가격: {price}원")
price += _100g_coffee 
print(f"커피 원두 300g 가격: {price}원")
price += _100g_coffee 
print(f"커피 원두 400g 가격: {price}원")



year = [2020, 2021, 2022]
name = ["기생충", "노매드랜드", "코다"]

for i in range(len(year)):
    this_year = year[i]
    academy = name[i]
    print(f'{this_year}년 아카데미 영화제 작품상은 "{academy}"가 받았다')



_100g_coffee = 10000
weight = 200
print("커피 원두 %dg의 가격: %.0f원" % (weight, _100g_coffee * (weight / 100)))
weight = 300
print("커피 원두 %dg의 가격: %.0f원" % (weight, _100g_coffee * (weight / 100)))

# _100g_coffee = int(input("커피 단가를 기입해주세요(정수): "))
# weight = float(input("원두 무게를 기입해주세요(실수): "))
# print(f"커피 원두 {weight}g의 가격: {_100g_coffee * (weight / 100):.0f}원")



hello = 'world'
print(f"{hello:^11}")
print(f"{hello:*^11}")
big_num = 1234567890
print(f"{big_num:,}")
num = 2343552.6516251625
print(f"{num:,.3f}")




big_num_ = 1234567890
print(f"{big_num_:,}")
