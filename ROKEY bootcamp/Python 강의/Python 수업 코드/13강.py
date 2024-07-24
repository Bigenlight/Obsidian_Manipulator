import sys 
print(sys.argv) # sys.argv를 출력 
print(f"len(sys.argv) = {len(sys.argv)}") 
for argument in sys.argv: 
    print(f"명령행 인자: {argument}")
    
    
import glob, sys 
lst = [] # 파일 목록 
if len(sys.argv) == 1: # 파이썬 코드만 있음 
	lst = glob.glob("*") 
else: 
	lst = glob.glob(sys.argv[1]) 
if len(lst) == 0: # 빈 리스트 
	print("매칭되는 파일이 없습니다") 
else: 
	for name in lst:
		print(name)
  
  
import sys 
print(sys.argv) 