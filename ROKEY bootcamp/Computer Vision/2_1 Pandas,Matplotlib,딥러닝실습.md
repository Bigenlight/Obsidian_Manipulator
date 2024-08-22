2024-08-14
#컴퓨터비전 
[[Ai,컴퓨터 비전]]


![[1차시_05-06교시.pdf]]
# Pandas
[Google Colab](https://colab.research.google.com/drive/1PNSZjfaPD-0T2Vc_LBpHVR4qEcR60dPt?hl=ko#scrollTo=CTMJ8CAgv9Mm&uniqifier=1)

import pandas as pd

df = pd.read_csv('파일경로")

##### df.loc\[] 함수로 슬라이싱

주의!
![[Pasted image 20240814025023.png|400]]
슬라이싱을 하는데 인덱스 3도 포함!!

열도 열 이름으로 슬라이싱 할 수 있음.
![[Pasted image 20240814025250.png|600]]

##### df.iloc\[]
integer location
행렬을 정수를 이용해 가져오는 방법. 위에 그냥 loc은 라벨을 이용하지만 여기서는 번호만.
==주의! iloc은 일반 인덱싱 처럼 뒤에 수는 포함 x!== loc만 다른 것!
![[Pasted image 20240814152742.png|200]]

[[Pandas_Cheat_Sheet.pdf]]

## Matplotlib
짧게 한번 실습하고 넘어감.


## 타이타닉 전처리 실습
###### seaborn
그냥 seaborn으로 데이터를 온라인에서 가져올 수 있음.
import seaborn as sb
titanic = sb.load_dataset('titanic')

## 아이리스 품종 실습
### 원-핫 인코딩
여러개의 값으로 된 문자열을 0과 1로만 이루어진 형태로 만드는 듯

이렇게 문자열로 된 열을
![[Pasted image 20240814154702.png|200]]
pd.get_dummies()를 통해 원핫 인코딩을 함
![[Pasted image 20240814154737.png|400]]
이제 문자열 별로 01로 분류돼서 들어감.

## 아이리스 딥러닝 실습
```python
from tensorflow.keras.models import Sequential
from tensorflow.keras.layers import Dense

model = Sequential()
model.add(Dense(12, input_dim=4, activation='relu'))
model.add(Dense(8, activation='relu'))
model.add(Dense(3, activation='softmax'))
model.summary()

model.compile(loss='categorical_crossentropy', optimizer='adam', metrics=['accuracy'])
```
가운데 Denserk 각 딥러닝 레이어 층을 정의
![[Pasted image 20240814160355.png|500]]

소프트맥스 이용
[소프트맥스(Softmax) 함수](https://syj9700.tistory.com/38)

교재 11장 보고 있었음





![[2차시_05.pdf]]

![[2차시_06.pdf]]

![[2차시_01-02.pdf]]