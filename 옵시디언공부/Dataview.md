![데이터뷰 플러그인 사용법 쉬운 설명, 옵시디언 Dataview - YouTube](https://www.youtube.com/watch?v=Iv7wCJArqPI&list=PL-KPFbwFiAWA3bR3QSK3w6r_XM0KRzEFl&index=11)
[Dataview](https://blacksmithgu.github.io/obsidian-dataview/)

옵션 설정
![[Pasted image 20240710153933.png]]

\`\`\`dataview

\`\`\`
형식으로 코딩
#### 데이터를 볼 수 있는 형식 4개
##### Table
테이블 속 다양한 기능
FROM, WHERE, SORT, LIMIT, GROUP BY, FLATTEN
꼭 대문자로 코딩하 필요는 없음
from - and, or 으로 파일/태그 가져오기도 가능
```dataview
table file.cday, file.mday

from "ROKEY bootcamp/Python 강의"


```
```dataview
list
	
from "ROKEY bootcamp/Python 강의"
```
```dataview
table without id
	file.link as 날짜,
	title as "제목",
	important_date as "중요",
	file.mday as "수정일"

from "Daily Notes"
```

where date_daily > date(2023-06-07) 이런 식으로 일정 날짜 가져오기도 가능.
다만 date_daily 프론트메타를 만든 후 부터 가능.
##### List
##### Task
##### Calendar


