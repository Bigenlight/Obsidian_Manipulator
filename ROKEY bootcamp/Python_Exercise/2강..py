import sys
import io

sys.stdout = io.TextIOWrapper(sys.stdout.detach(), encoding='utf-8')


print(" \\ ")
print(" \" ")
print(" ' ' ")
print(" \\ ")
print("\the")
print("n d ")

print(3.1 % 2.1 )

print(2 + 3 * 4 ** 2)
print(((2 + 3) * 4) ** 2)

print(int(111-222-3333))

print("She said, \"It's a beautiful day.\"\nHe replied, \"Yes, it is!\"")

print("\u03A9")
print("\U0001F642")

a = "add"
b= "this"
print( a, b, sep = " ")

a = 123
b = 456
print( str(a) + str(b) )

a= "a"
print( ( a*5 + "\n") * 5  )

a = "Hello"
b = "World"
print(a*2 + b*2 , end = "")
print(a*2)

print( (a * 3 + b * 3 + "\n") * 3)

n = 3
print( (a * n + b * n + "\n") * n)

a = '1234'
print(a[:-1])

n = 3
print( ((a * n + b * n + "\n") * n )[:-3] )