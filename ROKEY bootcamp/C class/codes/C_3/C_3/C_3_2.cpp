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
//    printf("���ڸ� �Է��ϼ���: ");
//    scanf_s("%d", &n);
//
//    printf("�Ҽ�: ");
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
//    printf("������ �Է��ϼ���: ");
//    scanf_s("%d", &num);
//
//    while (num != 0) {
//        sum += num % 10;
//        num /= 10;
//    }
//
//    printf("�� �ڸ����� ��: %d\n", sum);
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
//    printf("�Ǻ���ġ ���� ����� ������ �Է����ּ���: ");
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
//    printf("������ �Է��ϼ���: ");
//    scanf_s("%d", &n);
//
//    printf("���丮��: %llu\n", factorial(n));
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
//    printf("�� ���ڸ� �Է��ϼ���: ");
//    scanf_s("%d %d", &num1, &num2);
//
//    if (num1 > num2) {
//        int temp = num1;
//        num1 = num2;
//        num2 = temp;
//    }
//
//    printf("Ȧ��: ");
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
//    printf("������ �Է��ϼ���: ");
//    scanf_s("%d", &num);
//
//    printf("������: %d\n", intSqrt(num));
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
//    printf("������ �ϳ� �Է����ּ���: ");
//    scanf_s("%d", &num);
//
//    if (isPrime(num)) {
//        printf("�Ҽ��Դϴ�.");
//    }
//    else {
//        printf("�Ҽ��� �ƴմϴ�.");
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
//    printf("������ �ϳ� �Է����ּ���: ");
//    scanf_s("%d", &num);
//
//    if (isPerfectNumber(num)) {
//        printf("�������Դϴ�.", num);
//    }
//    else {
//        printf("�������� �ƴմϴ�.", num);
//    }
//
//    return 0;
//}

