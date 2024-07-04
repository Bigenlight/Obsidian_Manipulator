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

![[Obsidian_push_window.bat]]
