#컴퓨터비전 
[[Ai,컴퓨터 비전]]
last modification: 2024-08-21

![[1.Intro_for_AI-0819_-_배포안.pdf]]
p.155
[6. 데이터 전처리 - YouTube](https://www.youtube.com/watch?v=UrtxT79RVo8)
# Softmax
 이종분류(0,1) -> 시그모이드 함수
 ==다중분류==(0,1, ... , 9) -> softmax 함수
숫자 분류 처럼 여러안에 대한 확률을 출력함.

![[Pasted image 20240821121938.png]]
독립변수가 여러개(여기서는 열이 두개니 두개인 듯), 최종 종속변수도 여러개(여기서는 0~9, 즉 종속변수가 10개임( 중간에 y는 꼭 10개는 아닌 듯)).
![[Pasted image 20240821121954.png|150]]
이런 표시는 행렬 표시임.
R이 랭크인데 N by (뒤 숫자)라는 뜻임.

![[Pasted image 20240821121121.png|300]]
예를 들어 들어 숫자를 추측하는 모델에서 각 숫자일 확률이 각각 모두 출력 됨.
![[Pasted image 20240821121022.png]]
원래 2.0 같은 값들도 ==Softmax==를 통과하면 0~1 사이의 값이 됨. 근데 로지스틱이랑 다른 것이 ==모든 경우의 합이 1==임. 0.7 + 0.2 + 0.1 = 1
Softmax 함수를 표시하는 기호는 시그모이드랑 똑같이 시그마임. 뒤에 무언가 더 붙긴하지만.

![[Pasted image 20240821140524.png]]
소프트맥스 값을 토대로 교차 엔트로피를 한번 더 돌려 마지막에 1-hot encoding된 라벨과(그니까 결과를 원핫 인코딩한겨) 비교함.
마지막으로 소프트맥스와 원핫 인코딩 된 결과를 크로스 엔트로피로 오차 도출.
아래에 더 볼 수 있는데

> [!Cost function이랑 loss function]
> ==Cost function이랑 loss function은 같은 것 
> 근데 보통 loss은 단일의 오차, cost는 데이터셋 전체에 대한 평균적인 오차를 의미하는 경우가 많음==

![[Pasted image 20240821142000.png]]
아무튼 이를 통해 cost(loss 또는 오차)를 구함(그냥 선형이면 평균제곱오차(MSE)). 그리고 이를 통해 경사하강법 같은 것으로 또 학습을 하면 됨.


###### 단순 코딩으로 Cross Entropy 예제
![[Pasted image 20240821145631.png|200]]
0.7, 0.2, 0.1이 여기까치 예측한 값, 이제 이거에 대한 cost(loss, 오차)를 측정함.
```python
# Cross entropy example
import numpy as np

# One hot encoding
# 0: 1 0 0
# 1: 0 1 0
# 2: 0 0 1

# 실제 값
Y = np.array([1, 0, 0])

# 예측 값
Y_pred1 = np.array([0.7, 0.2, 0.1])
Y_pred2 = np.array([0.1, 0.3, 0.6])

print("loss1 = ", np.sum(-Y * np.log(Y_pred1)))
print("loss2 = ", np.sum(-Y * np.log(Y_pred2)))
```
![[Pasted image 20240821145757.png|200]]
위 공식을 이용한 것.
![[Pasted image 20240821145816.png|200]]
이게 결과인데 당연하게도 0.7, 0.2, 0.1 예측 값들에 대한 loss가 훨씬 적음.

근데 이 코드는 이해 못함.
```python
import torch
import torch.nn as nn
from torch.autograd import Variable

# Softmax + CrossEntropy (LogSoftmax + NLLLoss)
loss = nn.CrossEntropyLoss()

# target is of size nBatch
# each element in target has to have 0 <= value < nClasses (0-2)
# Input is class, not one-hot
Y = Variable(torch.LongTensor([0]), requires_grad=False)

# input is of size nBatch x nClasses = 1 x 4
# Y_pred are logits (not softmax)
Y_pred1 = Variable(torch.Tensor([[2.0, 1.0, 0.1]]))
Y_pred2 = Variable(torch.Tensor([[0.5, 2.0, 0.3]]))

l1 = loss(Y_pred1, Y)
l2 = loss(Y_pred2, Y)

print("PyTorch Loss1 = ", l1.data, "\nPyTorch Loss2=", l2.data)
```

이제 실습 들어감
마저보기 [6. 데이터 전처리 - YouTube](https://www.youtube.com/watch?v=UrtxT79RVo8&t=5s)
하다가 잘 안됐다고함
지금 보니까 별거 안했누
[Site Unreachable](https://colab.research.google.com/drive/1TZZVFWFddhoJF7f7vR1KTmOaUsOxytPn?hl=ko#scrollTo=8iW0V1MtnOcE)
ZOO는 다음번 했으니 안봐도 ㄱㅊ을 듯. 그리고 강의 보는 것보다 GPT에 함수 용도 물어보는게 효율적으로 보임.
