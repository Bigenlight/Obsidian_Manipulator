---
Title: C 02장
tags: 
NeedCheck: 
Review: 
비고:
---
[[C 이론]]
[[C 장 실습]]

![[C_1-2차.pdf]]



long은 아주 긴 정수임
unsigned -- 면 음수가 아님.

float은 소수 - 4바이트
double은 좀 긴 소수 - 8바이트

#### 안되는 변수명
![[Pasted image 20240802144950.png|400]]

이미 사용되는 디폴트 키워드
![[Pasted image 20240802145020.png|500]]

## 출력
```c++
#include <stdio.h>
int main(void)
{
	printf("Hello!");
	printf(" ");	
}
```

![[Pasted image 20240802145242.png|400]]

서식 지정자 표
![[Pasted image 20240802145334.png|600]]

참고로 출력할 때
printf("==%04d==", n )
를 하면 04로 4자리가 생겨 비어 있는 만큼 0을 채워 줌

## 자료형 재정의 - typedef
typedef 기존자료형이름 새로운자료형이름

typedef int ant;
이제 부터 int는 ant라 부르는거다.

## 상수 지정 - (심볼릭 상수)
const a = 1;

다중 상수 지정
enum num { a= 1, b =2}