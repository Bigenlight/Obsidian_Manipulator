a = [1, 5, 8, 10, 14]
b = [2, 4, 5, 9]
c = (a + b)
print(c)
c.sort()
print(c)

import random

l = [random.randint(1,99) for _ in range(10)]
print(l)
t = tuple(l)
print(t)
l = sorted(t)

print(sum(l))
print(min(l))
print(max(l))
