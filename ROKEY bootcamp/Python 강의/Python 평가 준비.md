[[Python 이론]]
# 파이썬 추가 문제 복습 및 풀이 목록
## 추가 문제, 여기 없으면 추가 문제가 없음
2차 패스
3차 str.format() 
4차 답지 없음, str() 
5차 ㅇ
6차 답지보고, 재귀함수 연습할 것 ㅇ
7차 1 ㅇ
7-2  ㅇ
11차 얘는 답지가 친절해서 답지보고 공부하는게 나음, 쓸데 없이 긴 문제가 많누
12차 이거는 과제 문제로 연습하면 좋음 ㅇ
13차 여기는 실습 보다는 이론 위주로 나올 듯　ㅇ
16차 - 얘도 답지 없음, sorted 잘 써야 , ㅇ
17차 ㅇ - async는 안나오겠지??, 답지 없어서 이건 잘 모르겠음

파일 읽는 문법 간단 복습하기 - 
코루틴 async
date 사용법 복습

## 주간 과제 재풀이
일단 행렬 쪽으로 문제 나올 가능성 높음

#### 2-1 하노이 
-  [ ] 다시 
```python
def solution(n):
    def hanoi(n, source, target, auxiliary, moves):
        if n == 1:
            moves.append([source, target])
            return
        hanoi(n - 1, source, auxiliary, target, moves)
        moves.append([source, target])
        hanoi(n - 1, auxiliary, target, source, moves)

    moves = []
    hanoi(n, 1, 3, 2, moves)
    return moves

# 테스트
print(solution(2))  # [[1, 2], [1, 3], [2, 3]]
print(solution(3))  # [[1, 3], [1, 2], [3, 2], [1, 3], [2, 1], [2, 3], [1, 3]]


```
(n , 시작, 목표, 중간다리, 동작기록)
if n == 1:
	시작 목표
n-1 시작 중간다리 목표
시작 목표
n-1 중간다리 목표  시작

#### 2-3 행렬 
- [x] 다시 ✅ 2024-08-06

```python
def solution(matrix):
    # 원래 행렬의 크기
    rows = len(matrix)
    cols = len(matrix[0])
    
    # 새로운 행렬 생성 (90도 회전된 결과를 저장할 행렬)
    rotated_matrix = [[0] * rows for _ in range(cols)]
    
    # 행렬 회전
    for i in range(rows):
        for j in range(cols):
            rotated_matrix[j][rows - 1 - i] = matrix[i][j]
    
    return rotated_matrix

# 테스트 (정방 행렬이 아닌 경우)
matrix_rect = [
    [1, 2, 3, 4],
    [5, 6, 7, 8]
]

print(solution(matrix_rect))

```
행렬이 움직일 때 한 열의 원소들은 열의 인덱스가 1씩 증가하고, 행의 인덱스 1씩 감소하는 규칙이 있어.
이는 그 규칙을 단순히 이용한 것 뿐이야.
일단 외우자.

정방 행렬이 아닐때도 해야하니 len( )로 행열 모두 구하기
#### 3-6
super().\_\_init__() 안에 self 넣으면 안됨\

## 실습 복습
1 7분
2 13분
3 8분
4 3분
5
6  최대공약수
7 8분 공약수
9
10 5분 try except else finally
11 함수 복습
12 이론 문제 많음
13 time, datetime,, if \_\_name__ = '\_\_main__'

16 소수
17 이론
18 \\b

## 옵시디언 복습

