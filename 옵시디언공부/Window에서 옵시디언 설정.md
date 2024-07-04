## 윈도우에서도 시작하자마자 pull하기
메조장에서
@echo off
cd C:\MSI\Obsidian\Manipulator\
git pull origin main
이렇게 작성하고

그리고 이를 bat 형식으로 바꾼 뒤

![[update_git.bat]]

shell:startup에 들가서 이 파일을 넣으면 된다.

## 이거는 윈도우에서 자동으로 푸쉬 해주는 코드
cd C:\MSI\Obsidian\Manipulator\
git add . && git commit -m "window commit" && git push -u origin main
그냥 이걸 bat 프로그램으로 작성하고 여기에 두면 버튼 처럼 실행 된다 ㅋㅋㅋ.

![[Obsidian_push_window.bat]]
