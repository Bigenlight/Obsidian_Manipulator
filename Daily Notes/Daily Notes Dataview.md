```dataview
table without id
	file.link as 날짜,
	title as "제목",
	important_date as "중요",
	file.mday as "수정일"

from "Daily Notes" and #할일
sort file.name desc

```


```dataview
list
	tags
from "Daily Notes" and #할일

```
