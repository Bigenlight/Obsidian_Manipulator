#컴퓨터비전 
[[Ai,컴퓨터 비전]]
last modification: 2024-09-20

# 라벨링
![[labelImg_setting.ipynb]]
여기에 과정이 친절하게 정리 됨.
### Ubuntu 22.04
![[Ubuntu 아나콘다 가상환경에서 labelImg 설치 및 실행 과정.pdf]]
labeling -> data -> predefined 파일
들어가서 클래스(라벨명) 삭제 가능. 여기서 수정도 가능.

labelImg 폴더 들가고
거기 언에서 
python3 labelImg.py
을 실행해야 함.

그리고 같은 폴더에 있는 data 속 predefined도 지워주고.
### Window - Anaconda3
아나콘다 프롬프트 열고
pip install labelImg

cd anaconda3\Lib\site-packages\libs
위 디렉토리로 가서 파일 수정


Change Dir가 아니라 Open Dir로 하는 것을 명심할 것.






다시 8로 갔을 때 부터 안봄

!./darknet detector test cfg/obj_tank.data cfg/yolov4-obj_tank.cfg yolov4-obj_tank_last.weights /content/darknet/data/obj/90_Edit0000.jpg

흐름을 잃지 말아라.
