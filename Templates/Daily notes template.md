---
title: 
date_daily: <% tp.file.title.slice(0,10) %>
important_date: 
tags:
  - 할일
  - "#daily"
  - 2025년
related notes: "[[Daily Notes Dataview]]"
---
##### 오늘 노트 및 할 일 
- [ ] 메일 확인
- [ ] 명상
- [ ] 로봇 뉴스
<%* 
let yesterday = "Daily Notes/" + tp.date.now("YYYY-MM-DD", -1, tp.file.title, "YYYY-MM-DD"); 
let section = "###### 내일 노트 및 할 일"; 
let should_include = false; 
let sectionContent = ""; 
let yfile = tp.file.find_tfile(yesterday); 
if(yfile) { 
	const content = await app.vault.read(yfile); 
	if(content.includes(section)) { 
		let startIndex = content.indexOf(section) + section.length; 
		let endIndex = content.indexOf('\n##', startIndex); 
		endIndex = endIndex === -1 ? content.length : endIndex; 
		sectionContent = content.substring(startIndex, endIndex).trim(); should_include = sectionContent.length > 0; 
	}
} 
tR += should_include ? sectionContent : "- [ ]   "; %>
  




###### 내일 노트 및 할 일
- [ ]  없습니다


######  Window 스위치
![[Git_pull_window.bat]]
![[Obsidian_push_window 1.bat]]



###### 강제 풀
![[Force_pull.bat]]