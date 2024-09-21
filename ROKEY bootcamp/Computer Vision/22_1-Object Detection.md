#컴퓨터비전 
[[Ai,컴퓨터 비전]]
last modification: 2024-09-12

##### CNN 복습
![[01.CNN_intro.pdf]]
위는 classification, 즉 분류임. <- CNN

localization -> 하나의 사물을 인식하여, 어디에 있는 인식

object detection -> 여러 사물이 어디에 무엇이 있는지. 하지만 같은 사물은 구별 x.
object tracking -> 같은 사물이라도 구별하여 어디에 있는지 추적
segmentation -> 물체가 있는 곳을 마스킹
pose estimation -> 사람이나 사람의 동작을 인식
# Object Detection
![[02.object_detection.pdf]]
여기서도 CNN이 쓰임.

1) Image classification : CNN 이용해서 물체를 인식, 하나의물체대상 
2) localization : 물체인식 후에 위치인식,하나의물체대상, bounding box로위치표시 
3) detection : 여러 물체 대상물체인식후위치인식
![[Pasted image 20240912112447.png|400]]
![[Pasted image 20240912112759.png|500]]
- Clasification(인식) : 입력 이미지가 CNN을거친후softmax 통해서물체인식
- Localization : CNN의 마지막 구조변경위치를알기위한기능추가
- - bounding box와 연관된output 추가:좌표데이터: bx, by, bh, bw

마지막에 CNN 마지막에 softmax와  x, y, h, w 출력도 만듬 (위치와 박스 크기).
그리고 softmax와 x, y, h, w에 대한 loss도 각각 구하고 학습함.

다양한 좌표계가 있음.

![[Pasted image 20240912115944.png|300]]
Pc는 사물이 있다 없다 T/F.
그리고 위치 표시.
어떤 사물인지 표시. 해당 사물 열에 T/F.

##### Loss Function
![[Pasted image 20240912120136.png]]
MSE 이용

#### Sliding Window 방식
매 슬라이드 마다 검사하는 방식이라 보면 됨. 슬라이드를 움직이는 과정은 노가다지 딥러닝이 아님.
![[Pasted image 20240912120352.png]]
연산량 어마어마하게 많이 필요.
![[Pasted image 20240912120419.png]]
점점 칸을 키워서 검사.
- window 크기를키워가며반복함
- - object 있을 때CNN은1이되고, 그위치에서bounding box를그림
단점:
- computational cost 증가
	-  다양한window size를CNN에feed하여많은연산필요
- 연산량 줄이려고 stride 크게 해서 window를 한번에 여러 칸옮길순 있지만 정밀도가 낮아짐

sliding window object detection을 CNN 사용으로 해결
즉, 이것도 딥러닝으로 해결. 그것이 욜로.

#### CNN Implementation of Sliding Windows
모든 곳에 슬라이드 윈도를 하는 것이 아님

![[Pasted image 20240912121255.png]]
위에는 통상적인 Classification의 FCN으로 압축이고. 아래는 결과는 비슷해보지만 엄연히 3차원의 깊이만 큰 레이어.
![[Pasted image 20240912121636.png]]
이 방식으로 접근하면 결국 depth에는 각각의 사물에 대한 정보가 들어가고. 가로세로 장보는 위치 정보임.

#### IOU (손실함수)
그러면 loss은 어떻게 구하냐
![[Pasted image 20240912122230.png|400]]
Intersection(교집합)  of Uninon(합집합)
교집합이랑 합집합이 같으면 일치하는 것. 그 차이를 이용.

빨간 네모가 GT, Ground True
![[Pasted image 20240912135008.png]]
![[Pasted image 20240912135059.png|350]]
![[Pasted image 20240912135120.png|350]]

#### Object detection에서 흔히 발생하는 문제
![[Pasted image 20240912135213.png|300]]
하나의 물체가 여러개로 잡힘

==Non-max Suppression== 알고리즘으로 가장 큰 것만 남김.
![[Pasted image 20240912135254.png|250]]

#### Anchor Box
박스가 서로 겹치는 문제.
![[Pasted image 20240912135433.png]]
자동차 용 anchor와 사람 전용 anchor 박스를 따로 지정.

물체마다 Anchor box를 할당하여 그 anchor 박스에 가장 맞는 물체를 찾아 판별하게 함. 겹치는 물건도 감지 가능. 
물론 두 물체의 anchor box가 완전히 같으면 좀 힘들지도... 근데 같은 형상의 물건이 같은 위치에 겹쳐 있는 일이 일어나기 쉽지 않음. 같이 인식 하는게 당연할지도?

![[Pasted image 20240912140109.png|600]]
각 물체에 맞는 anchor box 정보를 출력하게 만들면 됨

#### YOLO 
![[Pasted image 20240912123112.png|300]]
각각의 영역을 나눠서 봄. 그리고 그 영역 중에서 가장 값이 큰 곳만 남기.

개인적으로 찾음 참고 자료:
[C4W3L09 YOLO Algorithm - YouTube](https://www.youtube.com/watch?v=9s_FpMpdYW8&ab_channel=DeepLearningAI)

###### Anchor
![[Pasted image 20240912140229.png]]
anchor 박스 결과 첫 인덱스가 0뜨면 뒤에는 그냥 무시함.


## 젯슨 TX2를 이용한 사물인식
![[03.Embedded_Object_Detection_with_Jetson_TX2_simple.pdf]]

원래 모델을 학습 시킬 때
![[Pasted image 20240912140750.png]]
큰 모델 같은 경우 메인 학습은 커다란 서버에서 먼저 함.

이제 이거를 우리 환경에 맞추고. nvidia는 이를 위해 TensorRT 지원. Arm사는 NN SDK 제공.

그리고 그 모델을 적용.

##### TensorRT
는 기본적으로 큰 모델을 최적화 하는 작업
![[Pasted image 20240912141142.png|500]]


## Object Detection With Deep Learning
![[Pasted image 20240912141829.png]]
비슷한 지역을 뭉뚱그리게 인식했지만, 그래도 1000개 이상의 슬라이드 및 윈도우를 움직이는 작업을 했어야 했음. 그래서 그냥 RCNN은 매우 느림.

### Yolo V1
 ![[Pasted image 20240912142421.png]]
 논문에 나온 이미지. 이걸 보고 누가 이해하겠냐고.

원래 224인 이미지를 448x448로 바꾸고 convol
![[Pasted image 20240912144928.png|400]]
쓰레쉬홀드 보다 작은 바운딩 박스는 다 제거.

GT를 일일히 지정해줘야 함.
![[Pasted image 20240912145025.png|300]]

IOU 쓰고
![[Pasted image 20240912145114.png]]
![[Pasted image 20240912145125.png|500]]

IOU 공식은 제대로 설명 안함

mAP - 정확도 측정

nms - non max suppression

![[Pasted image 20240912145710.png]]
결과가 7x7x30인데.
먼저 30은 c x y h w, c x y h w (c는 confidence score) => 10개 + 클라스 정보 20개를 합쳐 30개임.
이때 7x7이 바운딩 박스를 나타냄. 7x7에 2를 곱하면 바운딩 박스 개수임 -> 98개
그리고 거기서 가장 알맞는 3개만 남김.

마지막 레이어에서 CNN이 아니라 FCN이 있어도 상관 없음. 중요한건 7x7x30을 얻는 것.

![[Pasted image 20240912152819.png]]
앞에 c x y h w, c x y h w이 두개 있다는 것은 한셀당 두개의 정보를 감지할 수 있다는겨.
그 우측 나머지는 각각 클래스.

#### SSD
![[Pasted image 20240912153310.png]]
기존 욜로는 마지막에 텐서를 만들고.
ssd는 중간 중간에텐서를 만듬 -> 이를 통해 큰 특징, 작은 특징 다 볼 수 있음.
하지만 최근 욜로4 부터 이것도 흡수함.


욜로가 1부터 10까지 있음.
### YOLO V2
욜로는 1~3이 원작자. 다크넷으로 c++로 개발
4랑 7 유사하고. 3, 5하고 8이 유사함 (파이토치를 씀).

욜로 3부터 배치 정규화 기능 추가.
고해상도 이미지 학습

자세한 설명은 생략

###### 참고자료
[YOLO - Google Slides](https://docs.google.com/presentation/d/1aeRvtKG21KHdD5lg6Hgyhx5rPq_ZOsGjG5rJ1HP7BbA/pub?start=false&loop=false&delayms=3000&slide=id.g137784ab86_4_787)

### 욜로와 Jetson TX2 보드
대부분 내용은 간단하게 말하고 넘어감

이거는 시험내기 애매할 듯

## SSD
![[SSD.pdf]]
욜로1의 문제는 작은 문제가 인식이 안됨.

Base Network은 VGG-16
이를 transfer 학습한겨
많은 경우 전이 학습을 함. 처음 부터 다시 시작하면 시간이 너무 오래 걸림.

![[Pasted image 20240912162201.png]]
문제는 좌측이면 보통 성숙도가 낮음. 좌측에서 좋은 것을 못 뽑아냄.
그리고 좌측이 작은 디테일들을, 우측이 전체적인 디테일을 잡음.
아무튼 뽑은 6개의 결과 중에서 가장 성적이 높은 것만 반환.

일을 3개로 분리하여 구성.
![[Pasted image 20240912162750.png|500]]
좌측은 anchor 박스 특징을 찾음.
가운데는 위치.
우측은 점수가 높은 곳을 찾음.

![[Pasted image 20240912163013.png]]
셀 하나당 anchor 박스가 3개.
빨간점이 25개니까 3개씩, 즉 75개의 채널이 필요함.

![[Pasted image 20240912172218.png]]
localization은 4개 변수라 4개의 채널 필요
confidence는 21개의 채널인 이유는 클래스가 20개인데 배경도 1개 필요해서 20 + 1임.
![[Pasted image 20240912172446.png]]
그래서 박스가 엄청 나오는데 좋은 것만 남김.

SSD는 기본적으로 빨라서 리얼타임 가능



![[04.LabelImg_설치_및_실행_.pdf]]

과제
GPU 안쓰면 이렇게 바꿔야함

![[Pasted image 20240912181228.png]]

비전 응용 7차시 과제입니다.  
수업 시간에 강사님이 과제 관련하여 공지한 내용입니다.  
아래와 같이  
1. racing.mp4  
 -> trim 5개  
 -> Google Drive 저장  
 -> picture 추출  
 -> 한 개만 google drive 저장  
  
2. mp4 받아서 google drive data directory  
    colab cp trim하고 저장 picture 생성, 하나만 driver에 저장  