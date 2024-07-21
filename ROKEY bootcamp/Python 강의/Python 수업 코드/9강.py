# import os
# print(f"현재 디렉토리: {os.getcwd()}")


'''
while True:
    base = input("입력할 정수의 진수는(base)는? [2, 8, 10, 16]: ")
    if base in ['2', '8', '10', '16']:
        base = int(base)
        break
    else:
        print("잘못된 값입니다.")

while True:
    number = input(f"정수를 입력하세요 (진수 {base}): ")
    try:
        num_dict = {
            2: lambda x: bin(int(x, base))[2:],
            8: lambda x: oct(int(x, base))[2:],
            10: lambda x: str(int(x, base)),
            16: lambda x: hex(int(x, base))[2:]
        }
        print(f"2진수: {num_dict[2](number)}")
        print(f"8진수: {num_dict[8](number)}")
        print(f"10진수: {num_dict[10](number)}")
        print(f"16진수: {num_dict[16](number)}")
    except Exception as e:
        print(type(e))
        print("올바른 정수를 입력하세요.")
'''
'''
original = input("원본 파일의 이름을 입력해주세요: ")
new_file = input("새 파일의 이름을 입력해주세요: ")

try:
	with open(original) as f1, open(new_file, "w") as f2:
		f2.write(f1.read())
		
except:
	print("파일이 존재하지 않습니다.")
'''
'''
sentence = input("두개의 숫자와 연산자를 입력해주세요: ")
l = sentence.split()

try:
	a = int(l[0])
	b = int(l[2])
	if l[1] == '+':
		print(a + b)
	elif l[1] == '-':
		print(a - b)
	elif l[1] == '/':
		print( f"{ (a / b) : .2f}")
except Exception as e:
	print(type(e))
'''
'''
import sys

name = input("파일명을 입력해주세요: ")
try:
    with open(name) as f:
	    print(f.read())
except FileNotFoundError:
    try:
        name = input("해당 파일이 없습니다. 파일명을 다시 입력해주세요: ")
        with open(name) as f:
            print(f.read())
    except FileNotFoundError:
        print("해당 파일도 없습니다.")
        sys.exit()
   '''     

''' 
name = input("파일명을 입력해주세요: ")
try:
    with open(name) as f:
	    print(f.read())
except:
	print("파일이 존재하지 않습니다")
 '''

'''
try :
	with open("data.txt", encoding = "cp949" ) as f:
		print(f.read())
except UnicodeDecodeError:
	print("오류 발생, 읽는 형식을 바꿉니다.")
	with open("data.txt", encoding = "utf-8" ) as f:
		print(f.read())
except:
	print("해당 파일을 찾지 못 했습니다.")
'''



file = input("파일 이름을 입력하세요: ")

try:
    with open(file) as f:
        s = f.read()
except FileNotFoundError:
    print("해당 파일을 찾을 수 없습니다.")
else:
    print("파일을 성공적으로 찾았습니다.")
    print(s)
finally:
    print("프로그램이 종료되었습니다.")