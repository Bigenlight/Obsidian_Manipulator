
### 2차원 정방 행렬 회전
이게 인풋 
\[1,2,3\]
\[4,5,6\]
\[7,8,9\] 
결과는 이렇게
\[\[7,4,1],\[8,5,2\],\[9,6,3\]]

def sol(matrix):
	rot = \[list(i\[\:\:-1\] for i in zip(\*matrix))]
	return rot

여기서 \*는 리스트의 겉 껍질을 없앰.
zip은 위아래로 그것들을 다시 묶음.
이제 반대로 집어넣기만 하면 됨.
```python
x = [[1,2,3],[4,5,6],[7,8,9]]
print(x)
print(*x)
print(list(zip(*x)))

def sol(matrix):
  rot = [list(i[::-1] for i in zip(*matrix))]
  return rot
sol(x)
```
![[Pasted image 20240729171706.png|400]]