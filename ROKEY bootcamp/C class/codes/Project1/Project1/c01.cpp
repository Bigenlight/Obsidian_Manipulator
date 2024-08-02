//#include <stdio.h>
//
//int main(void)
//{
//	printf("Hello!");
//	printf(" ");
//	
//}
//
//#include <stdio.h>
// 
//int main(void)
//{
//	for (int first = 1, second = 9; first < 10 ; first++, second--) {
//		printf("%d%d ", first, second);
//	}
//	printf("Hello!");
//	printf(" ");
//}

//#include <stdio.h>
//typedef int ant;
//
//int main(void)
//{
//	ant a = 2;
//	printf("Hello! %d", a);

//#define _CRT_SECURE_NO_WARNINGS
//#include <stdio.h>
//
//int main(void)
//{
//	int n1;
//	int n2;
//	char c;
//	printf("입력: ");
//	scanf("%d %c", &n1, &c);
//	printf("n1 = %d, c = %c \n", n1, c);
//}
// 
// 
//#include <stdio.h>
//
//int main(void)
//{
//	int n1 = 2;
//	int n2 = 1;
//
//	printf("n1 = %04d, n2 = %d \n", n1, n2);
//}

//#define _CRT_SECURE_NO_WARNINGS
//#include <stdio.h>
//
//int main(void)
//{
//    printf("입력: ");
//    int c = getchar();
//    printf("c = %c\n", c);
//
//    // Consume the newline character left in the buffer
//    while ((getchar()) != '\n' && getchar() != EOF);
//
//    printf("입력: "); // Prompt again for clarity
//    c = getchar();
//    printf("c = %c\n", c);
//
//    return 0;
//}
//#define _CRT_SECURE_NO_WARNINGS
//#include <stdio.h>
//
//int main(void)
//{
//    printf("입력: ");
//    int c = getc(stdin);
//    printf("c = %c\n", c);
//    c = getc(stdin);
//    printf("c = %c\n", c);
//
//    return 0;
//}

//#define _CRT_SECURE_NO_WARNINGS
//#include <stdio.h>
//
//int main(void)
//{
//    putchar('a');
//
//    return 0;
//}

//#include <stdio.h>
//
//int main(void) {
//
//    printf("I said, "hello".");
//
//    return 0;
//}

//#include <stdio.h>
//
//int main() {
//    printf("%zu\n", sizeof('A'));
//    printf("%zu\n", sizeof(120));
//    printf("%zu\n", sizeof(2011351000));
//    printf("%zu\n", sizeof(3011351000u));
//    printf("%zu\n", sizeof(3011351000LL));
//    printf("%zu\n", sizeof(232322011351000.));
//
//    return 0;
//}

//#include <stdio.h>
//
//int main() {
//    printf("double: %zu\n", sizeof(double));
//    printf("long double: %zu\n", sizeof(long double));
//
//    return 0;
//}

//#include <stdio.h>
//
//int main() {
//    printf("int: %zu \n", sizeof(int));
//    printf("long: %zu \n", sizeof(long));
//
//    return 0;
//}

//#include <stdio.h>
//
//int main() {
//    int a;
//    int b = 5;
//    int c = a + b; // 'a'는 초기화되지 않았음
//    printf("Result: %d\n", c);
//    return 0;
//}

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {
    int a = 0;
    printf("address of a = %d\n", &a);
    return 0;
}



