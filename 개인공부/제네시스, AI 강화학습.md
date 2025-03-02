---
title: 제네시스, AI 강화학습
date: 2024-12-26
tags:
  - "#개인공부"
related notes: "[[개인 공부]]"
Review: 
비고:
---


[GitHub - Genesis-Embodied-AI/Genesis: A generative world for general-purpose robotics & embodied AI learning.](https://github.com/Genesis-Embodied-AI/Genesis)

### 설치 가이드
[🛠️ Installation — Genesis 0.2.0 documentation](https://genesis-world.readthedocs.io/en/latest/user_guide/overview/installation.html)

#### 파이토치 설치
[Start Locally | PyTorch](https://pytorch.org/get-started/locally/)

##### CUDA 설치
[CUDA Toolkit 12.6 Update 3 Downloads | NVIDIA Developer](https://developer.nvidia.com/cuda-downloads?target_os=Linux&target_arch=x86_64&Distribution=Debian&target_version=12&target_type=deb_local)
툴킷 설치하며 됨 ㅇㅇ
###### nvidia driver 설치
Secure boot 해제해야 드라이바 올바르게 실행 됨.

그냥 설치는 콘다 가상 환경에서 함

Genesis/genesis/ext/LuisaRender 
여기서 렌더링 관련 리포지토리 다운 받을 수 있음

### 실행
[👋🏻 Hello, Genesis — Genesis 0.2.0 documentation](https://genesis-world.readthedocs.io/en/latest/user_guide/getting_started/hello_genesis.html)

acu

도커 안쓰는게 나은 듯

python 치고 한줄 한줄 실행도 좋은데 파이썬 파일 만들고 한번에 실행하는게 나은 듯.

튜토리얼 하는데 motion planning 페이지는 잘 안됨.
나머지는 다 잘 됨.

다만 유튜브 영상에서 봤던 것 처럼 텍스트 입력하면 그대로 되는건 없음.

이게 gs.generate라는 api를 써야하는데 그게 안보임.
[API Reference — Genesis 0.2.0 documentation](https://genesis-world.readthedocs.io/en/latest/api_reference/index.html)

![[Pasted image 20241228191826.png|300]]
위에 이게 없음

일단 그런 기능들은 전부 coming soon인 것 같다.

그래도 재미있었음. 환경 세팅 경험도 하고.