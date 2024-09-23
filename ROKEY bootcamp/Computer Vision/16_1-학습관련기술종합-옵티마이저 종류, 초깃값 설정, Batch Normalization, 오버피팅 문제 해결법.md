#컴퓨터비전 
[[Ai,컴퓨터 비전]]
last modification: 2024-09-04

# 6장
[Site Unreachable](https://colab.research.google.com/drive/1nG5YzTN0EQI6j0pjVO5ATRhxVKWSPd5x#scrollTo=9vvmE1vh4L71)
## 학습 관련 기술들

> [!Affine Layer]
> 참고로 일반적인 레이어는 흔히 Fully Connected Layer(완전 연결층)이나 Affine Layer라고 부른다. 
>  Affine Layer은 또 선형 변환을 수행하는 레이어를 의미하기도 하며, 우리가 흔히 배운 기번레이어인 y = w* x + b가 이에 해당 된다. 
>  FCN은 Affine의 포괄하는 듯. 그냥 연결만 됐으면 FCN.

### 6.1 매개 변수 갱신
#### ==옵티마이저==
###### 이거 시험에 무조건 나옴

옵티마이저로 최적화를 시행

옵티마이저 종류들 요약
[Optimizer 종류 및 정리](https://velog.io/@chang0517/Optimizer-%EC%A2%85%EB%A5%98-%EB%B0%8F-%EC%A0%95%EB%A6%AC)
![[Pasted image 20240904141636.png]]

##### GD
전체 데이터에서 보는 경사하강법
##### SGD - 확률적 경사하강법
$$ W := W - \eta \frac{\partial L}{\partial W}$$
$$ W : 갱신할매개변수 $$
$$\eta \frac{\partial L}{\partial W} : W 에 대한 손실함수의 기울기$$
$$ \eta : 학습률, 미리 정해서 사용 $$
![[Pasted image 20240904141841.png]]

##### Momentum
경사하강법은 일정한 비율로만 내려가는 거지만, 얘는 속도가 변함. 
내려 올 때 가속으로 중간에 있는 함정 구덩이에서 빠져나갈 수 있음.
![[Pasted image 20240904141953.png|400]]
알파는 마찰계수, v는 속도
![[Pasted image 20240904142001.png]]

##### Nesterov
![[Pasted image 20240904142059.png|400]]
![[Pasted image 20240904142109.png]]

##### AdaGrad
learning rate를 시간에 갈수록 감소 시킴.
![[Pasted image 20240904142151.png|500]]
![[Pasted image 20240904142202.png]]

##### RMSProp (Root Mean Square Propagation)
그냥 adagrad는 무조건 스탭이 감소하는 반면에
이거는 위의 보완으로, 매번 반영하는 값이 현재의 상태에 따라 달라짐. 
![[Pasted image 20240904142247.png]]

##### Adam = AdaGrad(RMSProp) + Momentum
매개변수 효율적 탐색 + 하이퍼파라미터 값 편향 보정
위에 모멘텀을 짬봉시킴.
보통 성능이 가장 좋다고함.
![[Pasted image 20240904142329.png]]

비교 샷
![[Pasted image 20240904142347.png]]

MNIST 비교샷
![[Pasted image 20240904142411.png]]

옵티마이저에 대해 도움 되는 글
[Optimizers: The Secret Sauce of Deep Learning | by Neha Purohit | 𝐀𝐈 𝐦𝐨𝐧𝐤𝐬.𝐢𝐨 | Medium](https://medium.com/aimonks/optimizers-the-secret-sauce-of-deep-learning-c0f09cc98bd5)

### 6.2 가중치의 초깃값
[학습 못지않게 타고난 바도 중요하다 - 딥러닝 초기화](https://brunch.co.kr/@hvnpoet/99)
생각보다 학습에 있어 초깃값이 매우 중요. 경우에 따라 학습이 안될 수도 있음.

매개변수의 값이 0~1 사이여야 학습하기 좋긴함.
#### 초기값 설정
신경망에서 **초기화 과정**(initialization process)은 학습을 시작하기 전에 신경망의 가중치(weight)와 편향(bias)을 초기 값으로 설정하는 것을 의미합니다. 이 과정은 매우 중요하며, 신경망의 학습 속도와 성능에 큰 영향을 미칩니다. 잘못된 초기화는 학습이 잘 안되거나, 최적의 성능을 찾지 못하게 할 수 있습니다.

- 0 : 학습이 올바로 이루어지지 않음
- ramdom(정규분포) : 1인 경우 양쪽으로 치우쳐서 분포함, 0.01인 경우 가운데로만 분포함 표현력이 적다.
- Xavier(sigmoid) : 전체 영역에서 골고루 퍼지게 됨
- He(ReLu) : Xavier 방식보다 2배의 계수가 필요함

![[Pasted image 20240904160423.png]]
0과 1 끝단에 지우쳐 있으면 학습하기 안좋음. (표준편차가 1이라는 상태)
기울기 소실 문제가(gradient vanishing) 일어남

![[Pasted image 20240904160619.png]]
가중치 표준편차가 0.01 인 정규분포는 뉴런이 여러개인 의미가 없다는거임.
다수의 뉴런이 다 같은 값을 출력한다는겨
물론 기울기 소실 문제가 일어날 수 없음.

Xavie 초기값
![[Pasted image 20240904160926.png]]
형태가 다소 일그러지지만 넓게 분포 됨.

==시그모이드를 쓰면 Xavier 쓰는게 좋음==
==Relu면 He 쓰는게 좋다고 함==

![[Pasted image 20240904164422.png|400]]
같은 모델인데 값이 다르게 나오누.

### 6.3 배치 정규화 - Batch Normalization
활성화 값의 분포가 적당하게 되게 ==강제로 조종==하는 것
레이어를 통과하게 되면서 활성화 값들의 분포가 이상한 곳으로 이동하거나 퍼질 수도 있는데 필요한 쪽으로 의도적으로 옮김.

배치 정규화를 하면 초깃값도 별로 신경 안써도 ㄱㅊ.

배치 정규화 <u>위치</u>는 Affine과 activation 함수 사이.

Affine에서 나온 값은 그대로 다시 가운데로 옮김.
==시그모이드==나 ==Relu==인 경우 자주 사용.
왜냐하면 그런 함수에서 값이 ==끝단에 정규화 되버리면 학습이 안됨==. -> vanishing gradient 
![[Pasted image 20240904171040.png]]
파랑색이 배치 정규화 사용.
주황색 점선이 배치 정규화 미사용.

압도적으로 좋음. 물론 이 장치가 필수는 아님.

레이어를 거치면 오차가 누적돼서 이를 잡아줘야 함.

[배치 정규화(Batch Normalization) - gaussian37](https://gaussian37.github.io/dl-concept-batchnorm/)
![[Pasted image 20240904173317.png|500]]
위에 처럼 진행하다 보면 값이 이상쪽으로 몰릴 수 있는데
![[Pasted image 20240904173351.png|500]]
이렇게 배치 정규화를 통해 다시 가운데로 정상화 시켜줌.

여기까지가 ==vanishing gradient== 문제를 해결하는 방법. 그레디언트 소실 문제는 아예 학습이 안되는 문제. 다음 부터 오버피팅 문제 해결법.

###### 과제 문제 6번 (과제_03)
학습 시에는 ==배치 평균과 분산==을 사용하고, 추론 시에는 전체 ==데이터셋의 평균과 분산==을 사용한다.

### 6.3 바른 학습을 위한 방법 
오버피팅 문제 해결법
오버피팅, 한 문제만 너무 잘 해결하고 다른 문제는 해결하지 못하는 것.
#### 가중치 감소
하나의 W가 너무 크면 학습이 안될 수도 있음. 이는 오버피팅을 일으킬 수 있으니 진행.

학습과정에서 큰 가중치에 대해서는 그에 상응하는 큰 패널티를 부과하여 오버피팅 억제
- 모든 가중치 각각의 손실함수에 1/2 λ (W\*\*2)를 더함
	- 람다 : 정규화 세기 조정
	- 1/2 : 미분결과 조정 상수

#### 드롭 아웃
![[Pasted image 20240904174229.png]]
레이어와 레이어 사이에 강제로 몇 개의 뉴런을 ==랜덤==하게 끄는 레이어
이를 통해 오버피팅 방지

이거를 보니 최근에 본 뉴마인드 영상이 떠오르네, 대부분의 뉴런들은 대부분의 시간 동안 꺼져있다고. 결국 다양한 문제 해결을 위해서는 그 만큼 뉴런들이 많이 꺼져 있어야겠네.

### 6.5 하이퍼 파라미터 값을
자동으로 찾아주는 기능들이 있음.
우리가 하는 노력을 덜어줌.

짧게 설명.
