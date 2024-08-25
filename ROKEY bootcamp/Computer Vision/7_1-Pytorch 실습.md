#컴퓨터비전 
[[Ai,컴퓨터 비전]]
last modification: 2024-08-22
![[자료-2-pytorch선형회귀.pdf]]

# Pytorch 선형회귀 예제

###### 토치에서 변수 선언
![[Pasted image 20240822103132.png]]

###### 가중치(w, b)와 gradients 초기화
![[Pasted image 20240822103214.png]]

###### 경사하강법 예제
```python
optimizer = optim.SGD([W, b], lr=0.01)

epochs = 20000

for epoch in range(epochs + 1):
    
    H = x_train * W + b  # 가설 설정
    cost = torch.mean((H - y_train) ** 2)  # 비용함수 선언

	# 기울기를 0으로 초기화한다. 각 에폭을 반복할 때 마다 기울기를 초기화해야 새로운 가중치화 편향에 대한 기울기를 구할 수 있다. 
    optimizer.zero_grad() # 이거 안하면 이전 값이 계속 남아있음
    # 새로운 W, b에 대한 gradient(기울기)를 계산한다
    cost.backward()  # 비용함수 미분해서 gradient 계산
    # 설정한 옵티마이저에 step함수를 이용해서 새로 계산한 기울기에 learning rate를 곱해서 새로운 값으로 업데이트 한 다.
    optimizer.step()  # W, b 업데이트

    if epoch % 100 == 0:
        print('Epoch {:4d}/{} W: {:.3f}, b: {:.3f} Cost: {:.6f}'.format(
            epoch, epochs, W.item(), b.item(), cost.item()))
```

###### 자동미분
![[Pasted image 20240822105945.png]]
w에 대해서 알아서 편미분하고 계산

###### 행렬곱 - H(x)
![[Pasted image 20240822110122.png|400]]
![[Pasted image 20240822110151.png]]

###### 쭉 코드 복습

최소제곱법이 수치해석 때 배운거고, 지금 배우는 것은 딥러닝으로 직선을 구하는 것

Hypothesis = 가설

Class
대부분의 경우 클래스를 통해 모델을 만듬
![[Pasted image 20240822111244.png|300]]
연구 쪽으로는 토치를 많이 씀

결국 텐서/토치 양쪽을 알면 좋음.

[Google Colab](https://colab.research.google.com/drive/1AdIPp_V4vGgcMrtzP9kpf6mc-A-Qwahb?hl=ko#scrollTo=jxyR_2eP9n8S)

### 과제
```python
x = torch.tensor([1., 2., 3.],requires_grad=True)
y = torch.tensor([4., 5., 6.])
```
참고로 gradient를 계산하려면 행렬 속 숫자들이 float가 아니면 안됨. 뒤에 '.'이라도 붙여야함.