#컴퓨터비전 
[[Ai,컴퓨터 비전]]
last modification: 2024-08-27

코랩은 터미널 명령도 내릴 수 있음
앞에 !나 %치면 뒤는 명령어 처럼 작동
```
!git clone https://github.com/dltpdn/insightbook.opencv_project_python

%cd /content/insightbook.opencv_project_python/02.interface

%mkdir aaa
```

영상처리에서 보통 왼쪽 위가 시작점 0

![[Pasted image 20240827152912.png]]
NHWC 체계
(N: 프레임, C: 해상도, H: 세로 , W: 가로)
4차원임
![[Pasted image 20240827152936.png]]
[PyTorch training/inference 성능 최적화 (1/2) — da2so](https://da2so.tistory.com/70)

# 4장
[Google Colab](https://colab.research.google.com/drive/1mpVe3iYgjXaMS4k29E4BdjHnJPBNZv9K?usp=sharing#scrollTo=1eZywmkJUVDl) <- 목차 위주로 볼 것

ROI
![[Pasted image 20240827153150.png|500]]

##### 마우스로 ROI 지정하는 프로그램
![[Pasted image 20240827155143.png]]
좌표 나옴
[[rokey_ai_10.py]]
###### 코랩 cv2_imshow()가 오류남
```
cv2_imshow(img_draw)
cv2_imshow(roi)
```
를 아래 처럼 바꿔야한다.
```
cv2.imshow('img', img_draw)
cv2.imshow('cropped', roi)
```
'\_'를 '.'으로 교체하고 윈도우 명칭 넣어야 하는 듯

![[Pasted image 20240827161324.png|300]]
잘 됨


#### RGB
###### OpenCV는 반대의 순서인 BGR로 표시

RGBA도 있음, RGB에 A(알파, alpha)(투명도) 추가

#### HSV 방식
- H(Hue, 색조) : 이미지가 어떤 색상인지를 나타냄
- S(Saturation, 채도) : 이미지의 색상이 얼마나 순수하게 포함되어 있는지 나타냄
- V(Value, 명도) : 색상이 얼마나 밝은지 어두운지를 표현 
![[Pasted image 20240827162043.png|400]]

#### YUV 방식
- YCbCr 방식이라고도 함
- Y는 ==밝기==(Luma),
- U는 밝기와 파란색과의 ==색상 차==(Chroma Blue, Cb),
- V는 밝기와 빨간색과의 색상 차(Chroma Red, Cr)
Y(밝기)에는 많은 비트수를 할당하고 U(Cb)와 V(Cr)에는 적은 비트수를 할당하여 데이터 압축 효과
![[Pasted image 20240827162225.png|300]]

### 이진 변화
==Otzu's method==: 이진화 threshold를 자동으로 정해줌. 명암 분포를 구하는 작업을 반복

==적응형 스레시홀드==: 이미지를 여러 영역으로 나눈 뒤, 그 주변 픽셀 값만 활용하여 임계값을 구해야 하는데, 이를 적응형 스레시홀딩(Adaptive Thresholding)

### 이미지 연산
##### 알파블랜딩
![[Pasted image 20240925181551.png|300]]
img1+img2 : 화소가 고르지 못하고 255를 초과한 영역에 이상한 색이 보임
cv.add : 전체적으로 하얀 픽셀이 많이 보임
각 픽셀의 합이 255가 되지 않게 가각의 영상에 가중치를 줘서 계산
- alpha값을 각 영상에 가중치로 적용해 적절한 비중으로 배분
![[Pasted image 20240925181605.png|300]]

#### 비트와이즈 연산
![[Pasted image 20240828221308.png|400]]
이미지 두개 줘서 대강 아래와 같은 이미지 출력하는 문제 낼 수 있을 듯
![[Pasted image 20240828221432.png|300]]
![[Pasted image 20240828221520.png|300]]
아 근데 프로그래머스로... cv2가 되나?

### 4.4.4 차영상
차영상(image differencing)을 하는 이유
- 영상에서 영상을 빼기 연산하면 두 영상의 변화를 알 수 있음
- 빼기 연산을 하게 되면 음수가 나올 수 있기 때문에 절대값을 구해야 함


오, 크로마키 만드는 것도 있누

### 히스토그램
- 전체 영상에서 픽셀값이 1인 것이 몇개인지, 2인 픽셀이 몇개인지... 255인 픽셀이 몇개인지 세는 것을 말한다.

##### 정규화 - 노멀라이즈
픽셀 값들이 0~255에 골고루 분포하지 않고 특정 영역에 몰려 있는 경우 화질을 개선하고 영상 간의 어려움이 있기 때문에 서로 다른 조건을 같게 만들기 위한 노멀라이즈(정규화) 기능 제공

##### 이퀄라이즈 -> 기존 정규화에서 집중된 영역에서 멀리 떨진 값들이 소외는 것을 방지
![[Pasted image 20240925182336.png]]

##### CLAHE : 똑똑한 이퀄라이즈 -> 기존 이퀄라이즈에서 너무 밝은 부분이 날라가는 것을 방지. 일정 영역 나눠서 이퀄라이즈 진행.
![[Pasted image 20240925182347.png]]

[(한국어) 히스토그램 평활화(HE)와 CLAHE 의 차이 - YouTube](https://www.youtube.com/watch?v=UGUh5B1wSYY)

##### 2D 히스토그램
개대충 넘어감, 뭔지 솔직히 이해 못함
![[Pasted image 20240828223036.png|400]]

###### 역투영과 히스토그램은 안봄
그래도 개념이니 나중에 한번씩 실행 해줄까?

역투영: 2차원 히스토그램과 HSV 컬러 스페이스를 이용하면 색상으로 특정 물체난 사물의 일부분을 배경에서 분리할 수 있다

실습은 넘어감