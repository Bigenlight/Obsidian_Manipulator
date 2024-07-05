[Introduction - Templater](https://silentvoid13.github.io/Templater/)
[Templater 플러그인 명령어 사용 방법, 옵시디언 템플릿 - YouTube](https://www.youtube.com/watch?v=17tThWhNNGw&list=PL-KPFbwFiAWA3bR3QSK3w6r_XM0KRzEFl&index=6)

ctrl + p -> templater 검색 -> 관련 명령어 볼 수 있음

아래 처럼 입력하면 template을 입력하기 시작 할 수 있음
\<\% tp.

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