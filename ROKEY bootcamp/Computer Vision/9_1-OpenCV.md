#컴퓨터비전 
[[Ai,컴퓨터 비전]]
last modification: 2024-08-26

오늘 부터 새로운 강사님이 OpenCV 알려 줄 듯

# 영상처리 개료
## 1장
[Site Unreachable](https://colab.research.google.com/drive/1XZgnRUqmY8JC34jTysLAPID_1dQcvKys#scrollTo=r5nJoVUVNv7R)


Colab에서 OpenCV가 정상적으로 실행이 안될 수 있음
cv2.imgshow가 원래 colab이 작동 안됨
그래서 구글이 따로 만든 cv2_imgshow로 써야함.

기본적으로 이미지는 3차원
(Height, Width, Channel)
Channel은 BGR 또는 RGB로 구성 됨.

# OpenCV 실습
## 2장
[Site Unreachable](https://colab.research.google.com/drive/1XcNys-wNnH1I9pvr4OoFwLPlBUi5LgR8#scrollTo=BKuGHNIh42QT) <- 이건 안봐도 됨

참고로 한글 경로 작동이 안되는 듯

명령어 앞에 !와 %는 별 의미가 없음. 그냥 외워라.

FPS: 초당 프레임

영상 실행
```python
import cv2

video_file = "C:/Users/window/Downloads/big_buck.avi" # 동영상 파일 경로

cap = cv2.VideoCapture(video_file) # 동영상 캡쳐 객체 생성  ---①
if cap.isOpened():                 # 캡쳐 객체 초기화 확인
    while True:
        ret, img = cap.read()      # 다음 프레임 읽기      --- ②
        if ret:                     # 프레임 읽기 정상
            cv2.imshow(video_file, img) # 화면에 표시  --- ③
            cv2.waitKey(25)            # 25ms 지연(40fps로 가정)   --- ④
        else:                       # 다음 프레임 읽을 수 없슴,
            break                   # 재생 완료
else:
    print("can't open video.")      # 캡쳐 객체 초기화 실패
cap.release()                       # 캡쳐 자원 반납
cv2.destroyAllWindows()
```
25ms 지연이면 -> 1000/25 = 40 fps

```python
import cv2

# 카메라 0번 장치 연결
cap = cv2.VideoCapture(0)                   

# 현재 프레임 폭 값 구하기
width = cap.get(cv2.CAP_PROP_FRAME_WIDTH)   
# 현재 프레임 높이 값 구하기
height = cap.get(cv2.CAP_PROP_FRAME_HEIGHT) 

# 현재 프레임 크기 출력
print("Original width: %d, height: %d" % (width, height))

# 프레임 폭을 320으로 설정
cap.set(cv2.CAP_PROP_FRAME_WIDTH, 320)      
# 프레임 높이를 240으로 설정
cap.set(cv2.CAP_PROP_FRAME_HEIGHT, 240)     

# 재지정한 프레임 폭 값 구하기
width = cap.get(cv2.CAP_PROP_FRAME_WIDTH)   
# 재지정한 프레임 높이 값 구하기
height = cap.get(cv2.CAP_PROP_FRAME_HEIGHT) 

# 재설정된 프레임 크기 출력
print("Resized width: %d, height: %d" % (width, height))

# 카메라가 정상적으로 열렸는지 확인
if cap.isOpened():
    while True:
        # 한 프레임 읽기, 프레임이 들어올 때까지 대기
        ret, img = cap.read() 
        if ret:
            # 읽은 프레임을 윈도우에 표시
            cv2.imshow('camera', img)
            # 1ms 동안 키 입력 대기, 아무 키나 눌리면 루프 종료
            if cv2.waitKey(1) != -1: 
                break 
        else:
            # 프레임이 없을 경우 메시지 출력 후 루프 종료
            print('No frame!')
            break
else:
    # 카메라를 열 수 없을 때 메시지 출력
    print("Can't open camera!")

# 사용한 자원 해제 및 윈도우 닫기
cap.release()
cv2.destroyAllWindows()

```

## 3장
[Site Unreachable](https://colab.research.google.com/drive/1e3KK3bwVvvjzjGizZaY-DVyZYxdC0Shw)
브로드캐스팅 -> 일반적으로 형태가 곱할 수 없는 행렬을 곱할  수 있게만듬.
## 4장
관심 영역(ROI : Region Of Interest) : 이미지에서 분석의 대상으로 지정한 영역
