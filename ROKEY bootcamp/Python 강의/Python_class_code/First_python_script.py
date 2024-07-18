print("hello world!")

print("hello world!2")

print("최태오")

print("2000-04-13")

print("2000","04","13")

# 문자열 사이마다 들어감
print("ㅁ ㅇ","ㅁ","ㅇ","ㅇ", sep="사이에 들어가는 것")

#끝맺힘
print("2000","04","13" ,end=" 끝\n")

name = input("이름 입력: ")
birth_year = input("태어난 연도 입력: ")
birth_month = input("태어난 달 입력: ")
birth_day = input("태어난 일 입력: ")

print(name,birth_year,birth_month,birth_day, sep = "/", end = "\n")

birth_year = input("태어난 연도 입력: ")
birth_month = input("태어난 달 입력: ")
birth_day = input("태어난 일 입력: ")
print(birth_year,birth_month,birth_day, sep = "/", end = "\n")
print(birth_year,birth_month,birth_day, sep = "-", end = "\n")
print(birth_year,birth_month,birth_day, sep = ".", end = "\n")