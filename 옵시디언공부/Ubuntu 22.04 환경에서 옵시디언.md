[[Ubuntu 22.04]]
https://www.notion.so/07-03-dd676d5bb69b4a92b5d0df79aaa476c7

## 우분투 옵시디언 환경
#rclone

~~이 것으로 우분투에서 rclone으로 구글 드라이브와 직접 연결 된 상태로 편집이 가능하다.
rclone mount gdrive: ~/GoogleDrive --daemon
안 쓸거면 권한을 해제 해주자

~~일단.... 
rclone을 써서 우분투에서 드라이브 마운트를 해보기도 했는데... 이게 상당히 느리다...
오 근데 막상 업로드 속도는 나쁘지 않은 것 같기도하고.

~~아... 근데 사진 업로드가 안되넹.. 까비.. 

~~안되는건 아니고 매우 매우 느리다!!
아마 유료버전을 써야 빨라지는게 아니가 싶다.

그럼 이제 결론은 뭐냐!

음.. 결국 어떻게든 돈을 써야 잘 될 것 같다.
또는 아주 조심히 풀 또는 푸쉬를 하거나..

### 무식한 충돌 해결 코드
이 두 명령어를 적으면 현재 충돌하는 변화가 싹 사라지고 깔끔해지니 이렇게 하자.
git fetch origin
git reset --hard origin/main

## 아쉽게도 우분투에서는 버튼 처럼 실행 할 수 있는 것은 없었다.
 하지만 start파일을 설정하여 시작시 자동 풀 및 끝날 때 자동 푸쉬를 할 수도 있다. 
 ![[우분투 지식]]
![[Pasted image 20240704010527.png]]
```
#!/bin/bash
cd ~/Opsidian_Manipulator/
git pull origin main
cd
cd ~/Downloads/
./Obsidian-1.6.5.AppImage

cd
cd ~/Opsidian_Manipulator/
git add . && git commit -m "new commit" && git push -u origin main
```

권한 허용
chmod +x ~/startup.sh

위 처럼 아래에  프로그램이 종료하면 푸쉬가 되게 만들었다.

obs 단축 명령어도 이걸로 업데이트 했다.
