#컴퓨터비전 
[[Ai,컴퓨터 비전]]
last modification: 2024-09-10

[Site Unreachable](https://colab.research.google.com/drive/1OERTjROxyB5xAvfhxfHTN2IY5VSSs_Ni#scrollTo=f9Xx-jP92OgP) -> 뭐 좀 있음

# Pytorch
페이스북에서 만듬

텐서플로우는 다 덮혀있음, 매립형임. 몇개의 API로만 모델 만들기 가능.
반면에 Pytorch은 오픈형임. 몇개의 함수만 라이브러리로 있고. 대부분의 과정이 다 드러나 있음.

텐서는 fit이 알아서 대 해주지만, 파이토치는 자동 미분이라는 과정이 중요. \_\_.backward이 여기에 해강. 이 부분을 이해하고 봐야 함.

###### 함수 5가지 정도는 이해해야 함.
코드 보면 for문이 다 노출 됨.
```python
for epoch in range(10):
    running_loss =0.0
    
    for i,data in enumerate(train_loader,0):
        inputs, labels = data
        
        optimizer.zero_grad()
  
        outputs = net(inputs)
        loss = criterion(outputs,labels)
        loss.backward()
        optimizer.step()

        running_loss += loss.item()

        if i % 100 == 99:
            print('Epoch : {}, lter: {}, Loss: {}'.format(epoch+1, i+1, running_loss/2000))
            running_loss = 0.0
```
- .zero_grad() = 미분값(그래디언트)를 clear함
- net( - ) = 콜 함수, 인스턴스명이 실행 되면 feed forward 실행. 즉 forward 연산 시작.
- 손실함수( criterion( - ) ) = loss 함수임. 여러 종류 있음.
- .backward() = 역전파, 뒤에서 앞으로 자동 미분하여 gradient를 다 구함.
- .step() = update

위 5가지 함수는 꼭 봐야 모델이 이해가 될거임.

![[Pasted image 20240910121522.png|255]]
자동미분 변수는 forwar 연산 때 쓰는 데이터랑 grad 값, 그리고 함수, 이렇게 3개의 요소로 구성 됨.

![[Pasted image 20240910121941.png|400]]
기본적으로 C로 코딩 돼서 생각보다 빠름.

#### 파이토치의 구성요소

- `torch`: 메인 네임스페이스, 텐서 등의 다양한 수학 함수가 포함
- `torch.autograd`: 자동 미분 기능을 제공하는 라이브러리
- `torch.nn`: 신경망 구축을 위한 데이터 구조나 레이어 등의 라이브러리
- `torch.multiprocessing`: 병럴처리 기능을 제공하는 라이브러리
- `torch.optim`: SGD(Stochastic Gradient Descent)를 중심으로 한 파라미터 최적화 알고리즘 제공
- `torch.utils`: 데이터 조작 등 유틸리티 기능 제공
- `torch.onnx`: ONNX(Open Neural Network Exchange), 서로 다른 프레임워크 간의 모델을 공유할 때 사용