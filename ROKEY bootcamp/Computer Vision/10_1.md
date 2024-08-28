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
[Google Colab](https://colab.research.google.com/drive/1mpVe3iYgjXaMS4k29E4BdjHnJPBNZv9K?usp=sharing#scrollTo=1eZywmkJUVDl)

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
- Y는 밝기(Luma),
- U는 밝기와 파란색과의 색상 차(Chroma Blue, Cb),
- V는 밝기와 빨간색과의 색상 차(Chroma Red, Cr)
Y(밝기)에는 많은 비트수를 할당하고 U(Cb)와 V(Cr)에는 적은 비트수를 할당하여 데이터 압축 효과
![[Pasted image 20240827162225.png|300]]

### 이진 변화
Otzu's method: 이진화 threshold를 자동으로 정해줌

### 이미지 연산
![[Pasted image 20240828221308.png|400]]
이미지 두개 줘서 대강 아래와 같은 이미지 출력하는 문제 낼 수 있을 듯
![[Pasted image 20240828221432.png|300]]
![[Pasted image 20240828221520.png|300]]
아 근데 프로그래머스로... cv2가 되나?

오, 크로마키 만드는 것도 있누

### 히스토그램
정규화 - 노멀라이즈

이퀄라이즈

CLAHE : 똑똑한 이퀄라이즈

[(한국어) 히스토그램 평활화(HE)와 CLAHE 의 차이 - YouTube](https://www.youtube.com/watch?v=UGUh5B1wSYY)

##### 2D 히스토그램
개대충 넘어감, 뭔지 솔직히 이해 못함
![[Pasted image 20240828223036.png|400]]

###### 역투영과 히스토그램은 안봄
그래도 개념이니 나중에 한번씩 실행 해줄까?

실습은 넘어감