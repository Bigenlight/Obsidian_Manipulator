#컴퓨터비전 
[[Ai,컴퓨터 비전]]
last modification: 2024-08-22
# 머신러닝
추론보다 분석을 많이 해줌
![[1.Intro_for_AI-0819_-_배포안.pdf]]
p.205

휴대폰 속 AP 구조는 ARM으로 되있음. (저전력이라)

학습할 때 전류가 많이 필요해서 요즘은 arm 씀

###### 머신 러닝을 생각보다 많은 분야를 내포
![[Pasted image 20240822150748.png]]
NLP: Natural Language Processing - 자연어 처리 = 언어를 기계가 이해 할 수 있도록 통역하는 영역. 이 분야가 LLM이랑 요즘 핫함.

지금까지의 딥러닝은 여기저기 들어가는 방법들임.

![[Pasted image 20240823105422.png|500]]


## 비지도 학습
![[Pasted image 20240822152424.png|400]]

### K-means
(여기는 데분입 참고해도 될 듯)
![[Pasted image 20240822160504.png|300]]
- 군집 중심점(centroid)이라는 특정한 임의의 지점을 선택해 해당 중심에 가장 가까운 포인트들을 선택하는 군집화 기법 
- 선택된 포인트의 평균지점으로 이동하고 이동된 중심점에서 다시 가까운 포인트를 선택, 다시 중심점을 평균 지점으로 이동하는 프로세스를 반복적으로 수행
- 널림 쓰임
단점:
- 반복 작업이 많아지면 매우 느려짐
- 몇개의 군집을 택할지 고르기가 어려움

### Means Shift
![[Pasted image 20240822160441.png|400]]
위랑 다르게 거리가 아닌 밀도로 군집화 계산
영상 처리 쪽에 많이 쓰임
사전에 군집의 개수를 정할 필요 없음.
단점:
- 느림

### DBSCAN
![[Pasted image 20240822160600.png|300]]
컨셉만 알고 있으셈
복잡한 기하학적 모양을 가진 곳에 적용 가능

### K-Nearest Neighbor
![[Pasted image 20240822160823.png]]
맨 왼쪽이 k가 1일 때, 우측은 k가 5일 때
![[Pasted image 20240822160854.png]]
정규화가 필요한 방법임. 
###### 중요 정규화 방법:
![[Pasted image 20240822162056.png]]
###### k 개수에 따른 현상
![[Pasted image 20240822162133.png|200]]

### SVM(Support Vector Machine)
분류와 회귀 문제에서 가장 빠른 지도학습 모델
![[Pasted image 20240822162313.png|400]]
이상적인 경계를 찾음
![[Pasted image 20240822163648.png|400]]
잘 모르겠지만 F(우측 아래)가 좋은 듯

마진(margin): 결정 경계와 서포트 벡터 사이의 거리를 의미한다.
![[Pasted image 20240822162630.png|400]]
위에서 검은 테두리가 있는 데이터들이 서포트 벡터
- 최적의 결정 경계는 마진을 최대화한다.
- n개의 속성을 가진 데이터에는 최소 n+1개의 서포트 벡터가 존재한다
- 서포트 벡터를 제외한 데이터는 무시하기 때문에 계산이 빠름.

SVC: Support Vector Classifier라고도 함
사용 예시
![[Pasted image 20240822164318.png]]
빨간 점 하나와 파란 점 두 개를 서포트 벡터로 이용

last modification: 2024-08-23

###### SVM에서는 이상치(Outlier)를 제거하는 것이 중요함
![[Pasted image 20240823115356.png|500]]
서포트 벡터 몇개로 계산하기 때문에 이상치에 따른 오류가 크게 나옴.

#####  SVM 반대 적용
![[Pasted image 20240823112905.png|500]]
SVM을 회귀에 적용 는 방법은, SVC와 목표를 반대로 하는 것이다.
• 즉, 마진 내부에 데이터가 최대한 많이 들어가도록 학습하는 것이다.
• 마진의 폭은 epilson이라는 하이퍼 파라미터를 사용하여 조절한다.


## 머신러닝 표
![[Pasted image 20240823120630.png|500]]

