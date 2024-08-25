#컴퓨터비전 
[[Ai,컴퓨터 비전]]
2024-08-20

![[1.Intro_for_AI-0819_-_배포안.pdf]]
p. 103
# Logistic Regression

![[Pasted image 20240820112254.png]]
Linear인 값에 ==Actication function==인 Sigmoid 함수를 적용하여 발동 여부를 판별
이 같은 경우 역전파를 적용하도 뒤로 안감 <- 이게 맞나?

###### 로지스틱에서 사용하는 교차 엔트로피 공식
![[Pasted image 20240820120021.png|350]]
근데 위를 보면 시그마가 식 전부를 포함하지 않아서 헷갈리는데
![[Pasted image 20240823234505.png]]
인터넷에 치면 위에 처럼 나오는거 보니 그냥 ( ) 넣기 까먹은 듯.
![[Pasted image 20240820115749.png]]
궁금하면 나중에 영상 더 찾아봐야 할 듯.
근데 그냥 대입하면 나옴.
[5. 분류알고리즘 선택2 - YouTube](https://www.youtube.com/watch?v=mQZBj-oU1Go)
1:23:20 부근에 계산

CNN이랑 RNN을 배울텐데, 요즘은 LLM이 이를 다 합침.

기호 정리, 아직은 이해가 하나도 안될 것
![[Pasted image 20240820135430.png|500]]

# Wide and Deep
다중 입력, 여러 독립 변수

하나의 입력에 대한 하나의 아웃풋을 이용할 때
![[Pasted image 20240820141818.png|500]]

여러 데이터들이 입력 될 때 계산은 행렬 이용 (위랑 다르게 x 행렬에 열이 추가 됨)
![[Pasted image 20240820141556.png]]
a와 b열이 각각 다른 데이터들, 이를 각 열에 맞는 w로 곱해서 구함,

![[Pasted image 20240820141935.png|400]]
이런 식으로 독립 변수를 늘림.

### Deep
![[Pasted image 20240820143103.png]]
이제는 깊게 레이어 수를 늘리는 것.
l1, l2, l3가 각각 레이어닌데, 매개변수는 다음과 같다: (입력 개수, 출력 개수)
최종 출력은 1개이다.
l1, l2, l3는 선언만 되는거고 실제 계산은 아래 x_data, out1, ou2를 통해 계산함.

![[Pasted image 20240820150010.png|400]]
레이어가 많아지면 gradient이 사라지는 문제가 발생하여 역전파 이용

###### 여러 Actication Function 정리
![[Pasted image 20240820150141.png|500]]
용도에 따라 달라지긴하는데, 일단 아래 4개가 중요.
우리가 씀.

Relu 설명
[Visualising Activation Functions in Neural Networks - dashee87.github.io](https://dashee87.github.io/deep%20learning/visualising-activation-functions-in-neural-networks/)

##### wide하고 딥한 코드 예제
```python
import torch
import torch.nn as nn

class Model(nn.Module): # 모델 만들기, 부모 클래스가 nn.Module
    def __init__(self):
        """
        In the constructor we instantiate three nn.Linear modules
        """
        super(Model, self).__init__() # 상속할 멤버함수 선언
        # 레이어 정의
        self.l1 = nn.Linear(8, 6) # 입력하는 독립변수가 8개
        self.l2 = nn.Linear(6, 4)
        self.l3 = nn.Linear(4, 1) # 출력하는 종속변수는 1개
        self.sigmoid = nn.Sigmoid()

    def forward(self, x):
        """
        In the forward function we accept a Variable of input data and we must return
        a Variable of output data. We can use Modules defined in the constructor as
        well as arbitrary operators on Variables.
        """
        out1 = self.sigmoid(self.l1(x)) # 실제 변수 집어넣기, 시그모이드를 통해 판단.
        out2 = self.sigmoid(self.l2(out1))
        y_pred = self.sigmoid(self.l3(out2))
        return y_pred

```
위는 그냥 모델만 만든거고, 이제 오차에 따른 옵티마이저를 설정하고
마지막으로 트레이닝 사이클을 구성하면 됨. 
![[Pasted image 20240820152210.png|250]]
###### 위 코드가 1단계.

###### 아래가 2단계
```python
# our model 
model = Model() 
# Construct our loss function and an Optimizer. The call to model.parameters() 
# in the SGD constructor will contain the learnable parameters of the two 
# nn.Linear modules which are members of the model. 
criterion = torch.nn.BCELoss(size_average=True) 
optimizer = torch.optim.SGD(model.parameters(), lr=0.1)
```
==BCE== : binary cross entropy, 교차엔트로피 공식
	이를 통해 오차 계산 (선형에서는 MCE(평균제곱오차) 썼음)
옵티마이저는 ==SGD==: Stochastic Gradient Descent (확률적 경사하강법)

###### 아래가 3단계
```python
# Training Loop
for epoch in range(100): # 100번 학습
    # Forward pass: Compute predicted y by passing x to the model
    y_pred = model(x_data)

    # Compute and print loss
    loss = criterion(y_pred, y_data)
    print(epoch, loss.item())  # Use loss.item() to get the scalar value

    # Zero gradients, perform a backward pass, and update the weights
    optimizer.zero_grad() # gradient을 0으로 초기화
    loss.backward() # 역전파해서 w 조절
    optimizer.step()

```

# Data Loader
ai 모델 개발시 데이터 전처리가 70%의 시간을 소비함. 이일은 주로 데이터 애널리스트가 함.
데이터 가져오기
```python
import numpy as np
import torch
from torch.autograd import Variable

# Load the dataset
xy = np.loadtxt('data-diabetes.csv', delimiter=',', dtype=np.float32)

# Split the dataset into inputs and labels
x_data = Variable(torch.from_numpy(xy[:, 0:-1]))
y_data = Variable(torch.from_numpy(xy[:, [-1]]))

# Print the shapes of the input and output tensors
print(x_data.data.shape)  # torch.Size([759, 8])
print(y_data.data.shape)  # torch.Size([759, 1])
```

#### 용어 정리
batch: 작업, 학습을 하는 프로세스
batch size: 그 작업의 사이즈, batch size를 늘리려면 메모리가 커야 됨

real time: 실시간으로 대응, 이런 경우 batch로 하면 안됨

![[Pasted image 20240820160801.png]]
epoch: 모든 트레이닝 샘플을 각각 forward pass 1번과 backward pass(역전파 같은)을 한번씩 함.
batch size : 트레이닝 하는 샘플의 수
트레이닝 샘플이 1000개 있고, batch size가 500이면, 2번의 iteration을 해야 1 epoch이 된다.

![[Pasted image 20240820161223.png]]
데이터 로드시 queue로 이용
	Stack : 마지막에 추가된 요소가 가장 먼저 제거 (후입선출)  
	Queue : 가장 먼저 추가된 요소가 가장 먼저 제거 (선입선출)  
	Deque :  양쪽 끝에서 요소를 추가하거나 제거 (양방향 Queue)

```python
import torch
from torch.utils.data import Dataset, DataLoader
import numpy as np

class DiabetesDataset(Dataset):
    """ Diabetes dataset."""
    def __init__(self):
        # Load your data, e.g., from a CSV file
        xy = np.loadtxt('data-diabetes.csv', delimiter=',', dtype=np.float32)
        self.len = xy.shape[0]
        # 데이터를 독립변수와 종속 변수로 분리
        self.x_data = torch.from_numpy(xy[:, 0:-1])
        self.y_data = torch.from_numpy(xy[:, [-1]])

    def __getitem__(self, index):
	    # 인덱스 가져오기
        return self.x_data[index], self.y_data[index]

    def __len__(self):
	    # 데이터 크기
        return self.len

# Create an instance of the dataset
dataset = DiabetesDataset()

# Create a DataLoader
train_loader = DataLoader(dataset=dataset,
                          batch_size=32,
                          shuffle=True,
                          num_workers=2)
# batch size를 정하고, shuffle을 통해 섞음

# Now you can iterate over the DataLoader
for i, (inputs, labels) in enumerate(train_loader):
    print(f"Batch {i}:")
    print(f"Inputs: {inputs}")
    print(f"Labels: {labels}")
```
모델은 위에 정의한 것을 쓴다고 가정할 때
트레이닝 loop은
```python
# Training loop
for epoch in range(2):
    for i, data in enumerate(train_loader, 0):
        # Get the inputs
        inputs, labels = data

        # Forward pass: Compute predicted y by passing x to the model
        y_pred = model(inputs) # 예측

        # Compute and print loss
        loss = criterion(y_pred, labels) # 오차 연산
        print(epoch, i, loss.item())

        # Zero gradients, perform a backward pass, and update the weights
        optimizer.zero_grad() # gradient(기울기) 초기화 (다음 w에 대한 gradient를 다시 구해야 됨)
        loss.backward() # w 업데이트, 역전파
        optimizer.step()
```

데이터셋 찾는 곳
![[Pasted image 20240820174255.png|500]]
[AI-Hub](https://www.aihub.or.kr/)
이 링크는 국내 데이터

MNIST 데이터 가져오기, 내일 마저 실습함
```python
import torch
from torchvision import datasets, transforms
from torch.utils.data import DataLoader

# MNIST Dataset
train_dataset = datasets.MNIST(root='./data/',
                               train=True,
                               transform=transforms.ToTensor(),
                               download=True)

test_dataset = datasets.MNIST(root='./data/',
                              train=False,
                              transform=transforms.ToTensor())

# Data Loader (Input Pipeline)
train_loader = DataLoader(dataset=train_dataset,
                          batch_size=batch_size,
                          shuffle=True)

test_loader = DataLoader(dataset=test_dataset,
                         batch_size=batch_size,
                         shuffle=False)

# Training loop example
for batch_idx, (data, target) in enumerate(train_loader):
    data, target = Variable(data), Variable(target)
    # Further training steps would follow...

```