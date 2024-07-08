[Introduction - Templater](https://silentvoid13.github.io/Templater/) - Doc

Templater 설치, 기본 사용
![Templater 플러그인 명령어 사용 방법, 옵시디언 템플릿 - YouTube](https://www.youtube.com/watch?v=17tThWhNNGw&list=PL-KPFbwFiAWA3bR3QSK3w6r_XM0KRzEFl&index=6) -
실제 사용 예제
![옵시디언 템플릿 직접 만들어보기, 콜아웃 기능, 영화 리뷰 예시 - YouTube](https://www.youtube.com/watch?v=Q2-aHQKEOHs&list=PL-KPFbwFiAWA3bR3QSK3w6r_XM0KRzEFl&index=7) 

ctrl + p -> templater 검색 -> 관련 명령어 볼 수 있음

아래 처럼 입력하면 template을 입력하기 시작 할 수 있음
\<\% tp.
alt + r 로 문장 적용

# tp.file
## 노트 생성 날짜
\<\% tp.file.creation_date("YYYY-MM-DD") %>
이 상태로 alt + r을 하면
2024-07-05
오늘 날짜는 볼 수 있다!

2024년 07월 05일 15시 13분

## 노트 제목
제목 가져오기
<\% tp.file.title %>
Templater

잘라서 가져오기
<\% tp.file.title.slice(3) %>
plater
<\% tp.file.title.slice(0,3) %>
Tem

## 노트 저장 폴더
현재 폴더
<\% tp.file.folder() %>
옵시디언공부

PC 기준 폴더
<\% tp.file.path() %>
C:\MSI\Obsidian\Manipulator/옵시디언공부/Templater.md

# tp.dater
<\% tp.date.now("YYYY-MM-DD") %>
2024-07-05
<\% tp.date.tomorrow("YYYY-MM-DD") %>
2024-07-06
<\% tp.date.yesterday("YYYY-MM-DD") %>
2024-07-04

지금 내가 있는 주에서 일요일 부터 토요일까지가 0 부터 6으로 할당하여 지정.
<\% tp.date.weekday("YYYY-MM-DD", 0) %>
2024-06-30
2024-07-06

참고로 \[[\ ]] 안에 tp.date 써서 그날 데일리 노트로 가는 링크도 만드는 것이 가능하다.

# tp.system
## 클립보드
<\% tp.system.clipboard() %> 현재 클립보드에 복사한 것을 가져온다.
복사

## 드롭다운 메뉴
<\% tp.system.suggester( ["별5개", "별4개", "별3개", "별2개", "별1개"], ["★★★★★", "★★★★☆", "★★★☆☆", "★★☆☆☆", "★☆☆☆☆"] ) %>
이제 alt + r을 누르면 어떤 별을 택할지 고를 수 있다.
★★★★☆

## 텍스트 필드
<\% tp.system.prompt("지금의 기분은?", "") %>
기분이 좋음


# Template 적용
Templates 폴더 안에 템플릿을 만들어서 넣으면.
이제부터 alt + e로 적용 가능.
Templater로 특정 템플릿에 대한 단축키도 설정 가능.

[[Movie_Template(test)]]
[[Daily notes template]]