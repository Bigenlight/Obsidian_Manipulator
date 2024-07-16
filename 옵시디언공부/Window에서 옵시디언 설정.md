## 윈도우에서도 시작하자마자 pull하기
메모장에
```
@echo off
cd C:\MSI\Obsidian\Manipulator\
git pull origin main
```

이렇게 작성하고

그리고 이를 .bat 형식으로 바꾼 뒤

![[update_git.bat]]
(재미있는 것은 이 파일을 여기에 놔둬도 클릭하면 버튼처럼 실행된다.)

Win + R
shell:startup에 들어가서 이 파일을 넣으면 된다.
![[Pasted image 20240704053433.png]]

## 이거는 윈도우에서 자동으로 푸쉬 해주는 코드
cd C:\MSI\Obsidian\Manipulator\
git add . && git commit -m "window commit" && git push -u origin main
그냥 이걸 bat 프로그램으로 작성하고 여기에 둬서 버튼처럼 쓰자.
![[Templates/attachments/Obsidian_push_window.bat]]
```
cd C:\MSI\Obsidian\Manipulator\
git add . && git commit -m "window commit" && git push -u origin main
```

### 무식한 충돌 해결 코드
![[Force_pull.bat]]
이 두 명령어를 적으면 현재 충돌하는 변화가 싹 사라지고 깔끔해지니 이렇게 하자.
git fetch origin
git reset --hard origin/main


### 윈도우 접속 후 분명 pull은 했는데 변화가 안보인다면
새로고침 or 껐다 켜라
반응이 느릴 때가 있는 것 같음