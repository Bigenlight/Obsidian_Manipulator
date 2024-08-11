// 23
//#include <stdio.h>
//#include <stdbool.h>
//
//bool isPrime(int num) {
//    if (num <= 1) {
//        return false; 
//    }
//
//    for (int i = 2; i * i <= num; i++) {
//        if (num % i == 0) {
//            return false;
//        }
//    }
//    return true;
//}
//
//int main() {
//    int n;
//    printf("숫자를 입력하세요: ");
//    scanf_s("%d", &n);
//
//    printf("소수: ");
//    for (int i = 2; i <= n; i++) {
//        if (isPrime(i)) {
//            printf("%d", i);
//            if (i != n) {
//                printf(", ");
//            }
//        }
//    }
//    printf("\n");
//
//    return 0;
//}

//24
//#include <stdio.h>
//
//int main() {
//    int num;
//    int sum = 0;
//
//    printf("정수를 입력하세요: ");
//    scanf_s("%d", &num);
//
//    while (num != 0) {
//        sum += num % 10;
//        num /= 10;
//    }
//
//    printf("각 자리수의 합: %d\n", sum);
//
//    return 0;
//}

//25
//#include <stdio.h>
//
//int Fibo(int n) {
//    if (n == 1) {
//        return 0;
//    }
//    else if (n == 2) {
//        return 1;
//    }
//    else {
//        return Fibo(n - 1) + Fibo(n - 2);
//    }
//}
//
//int main(void) {
//    int n;
//    printf("피보나치 수를 계산할 정수를 입력해주세요: ");
//    scanf_s("%d", &n);
//
//    int result = Fibo(n);
//
//    printf("%d\n", result);
//}
//26
//#include <stdio.h>
//
//unsigned long long factorial(int n) {
//    if (n == 0 || n == 1) {
//        return 1;
//    }
//    else {
//        return n * factorial(n - 1);
//    }
//}
//
//int main() {
//    int n;
//
//    printf("정수를 입력하세요: ");
//    scanf_s("%d", &n);
//
//    printf("팩토리얼: %llu\n", factorial(n));
//
//    return 0;
//}

//27
//#include <stdio.h>
//
//int isOdd(int num) {
//    return num % 2 != 0;
//}
//
//int main() {
//    int num1, num2;
//
//    printf("두 숫자를 입력하세요: ");
//    scanf_s("%d %d", &num1, &num2);
//
//    if (num1 > num2) {
//        int temp = num1;
//        num1 = num2;
//        num2 = temp;
//    }
//
//    printf("홀수: ");
//    for (int i = num1; i <= num2; i++) {
//        if (isOdd(i)) {
//            printf("%d", i);
//            if (i != num2) {
//                printf(", ");
//            }
//        }
//    }
//    printf("\n");
//
//    return 0;
//}

//28
//#include <stdio.h>
//#include <math.h>
//
//int intSqrt(int num) {
//    return (int)sqrt(num);
//}
//
//int main() {
//    int num;
//
//    printf("정수를 입력하세요: ");
//    scanf_s("%d", &num);
//
//    printf("제곱근: %d\n", intSqrt(num));
//
//    return 0;
//}

//29
//#include <stdio.h>
//#include <stdbool.h>
//
//bool isPrime(int num) {
//    if (num <= 1) {
//        return false;
//    }
//    for (int i = 2; i * i <= num; i++) {
//        if (num % i == 0) {
//            return false;
//        }
//    }
//    return true;
//}
//
//int main() {
//    int num;
//
//    printf("정수를 하나 입력해주세요: ");
//    scanf_s("%d", &num);
//
//    if (isPrime(num)) {
//        printf("소수입니다.");
//    }
//    else {
//        printf("소수가 아닙니다.");
//    }
//
//    return 0;
//}

//30
//#include <stdio.h>
//#include <stdbool.h>
//
//bool isPerfectNumber(int num) {
//    int sum = 0;
//
//    for (int i = 1; i <= num / 2; i++) {
//        if (num % i == 0) {
//            sum += i;
//        }
//    }
//
//    return sum == num;
//}
//
//int main() {
//    int num;
//
//    printf("정수를 하나 입력해주세요: ");
//    scanf_s("%d", &num);
//
//    if (isPerfectNumber(num)) {
//        printf("완전수입니다.", num);
//    }
//    else {
//        printf("완전수가 아닙니다.", num);
//    }
//
//    return 0;
//}

