#plugin
https://www.youtube.com/watch?v=Qok3EljgmbA&list=PL-KPFbwFiAWA3bR3QSK3w6r_XM0KRzEFl&index=5&t=51s

이제 체크박스를 했을 때 새로운 창이 아래에 뜬다.
\ - [ ] 

- [x] ㅇㅇ 🔽 ➕ 2024-07-04 🛫 2024-07-04 ⏳ 2024-07-04 📅 2024-07-04 ✅ 2024-07-04
- [x] 옵시디언 1강 보기 📅 2024-07-04 ✅ 2024-07-04
- [ ] 날짜는 적어도 됨 📅 2024-06-04
- [x] 반복일은 rec 검색 🔁 every day 📅 2024-07-07 계속 반복 됨 ✅ 2024-07-04
- [x] 반복일은 rec 검색 🔁 every day 📅 2024-07-06 ✅ 2024-07-04
- [x] 반복일은 rec 검색 🔁 every day 📅 2024-07-05 ✅ 2024-07-04
- [x] 반복일은 rec 검색 🔁 every day 📅 2024-07-04 ✅ 2024-07-04
- [x] r ✅ 2024-07-04


![[Pasted image 20240704234024.png]]
중요도 순서

여기서 \``` 쓰고 tasks 작성하면 전체 tasks 목록이 뜸
전체 tasks 목록
```tasks

```

칸안에 not done을 적음, 웹페이지를 보면 다양한 기능들이 있음
```tasks
not done

```

각 폴더에 있는 일만 추가하는 방법도 있음.


### Tasks 플러그인 명령어
```
### 완료되지 않은 일
not done
### 완료된 일
- has done date
- no done date
- done (on|befor|after) \<date>|\<data range>
### 정렬
- sort by priority
- sort by due
- sort by start
- sort by scheduled
- sort by done
- sort by description
- sort by path
- sort by recurring
- sort by tag
### 숨김
- hide start date
- hide due date
- hide edit button
- hide backlink
### 마감 기한
- due 2023-12-25
- due before yesterday
- due today
- due after 3 days ago
- due in this week
- due after this month
- due or or before next year
- due in 2023-Www(ww에는 주, 2자리 숫자)
- due in 2023-10 (10월)
- due (before|after|in) \<data range>
### priority
- priority is (above|below|not) (lowest|low|none|medium|high|highest)
## Custom filter
### 비어있는 필드
#### 비어있는 작업 찾기
description regex matches /^$/
#### 비어있는 작업 제외하기
description regex does not match /^$/
### 폴더 필터링
#### 현재의 폴더에 들어있는 할 일
folder includes {{query.file.folder}}
#### 폴더를 포함
filter by function task.file.folder.includes("폴더 이름")
```

Tags: [GTD](https://booktracing.com/tag/gtd/)[Tasks](https://booktracing.com/tag/tasks/)[투두리스트](https://booktracing.com/tag/%ed%88%ac%eb%91%90%eb%a6%ac%ec%8a%a4%ed%8a%b8/)[플러그인](https://booktracing.com/tag/%ed%94%8c%eb%9f%ac%ea%b7%b8%ec%9d%b8/)[할일관리](https://booktracing.com/tag/%ed%95%a0%ec%9d%bc%ea%b4%80%eb%a6%ac/)