//1
//#include <stdio.h>
//
//int main() {
//    int length = 10;
//    int array[10];
//    int max;
//    printf("������ 10�� �Է����ּ���:\n");
//    for (int i = 0; i < length; i++) {
//        scanf_s("%d", &array[i]);
//    }
//
//    max = array[0];
//    for (int i = 1; i < length; i++) {
//        if (array[i] > max) {
//            max = array[i];
//        }
//    }
//
//    printf("�ִ밪: %d\n", max);
//
//    return 0;
//}
//2
//#include <stdio.h>
//
//int main() {
//    int length = 3;
//    int array[3];
//
//    printf("�������� ���� 3���� �迭 ��Ҹ� �Է����ּ���:\n");
//    for (int i = 0; i < length; i++) {
//        scanf_s("%d", &array[i]);
//    }
//
//    printf("����:\n");
//    for (int i = length - 1; i >= 0; i--) {
//        printf("%d ", array[i]);
//    }
//    printf("\n");
//
//    return 0;
//}
//3
//#include <stdio.h>
//int main(void) {
//	int arr[2];
//	arr[0] = 1, arr[1] = 2;
//}

//6

//#define _CRT_SECURE_NO_WARNINGS
//
//#include <stdio.h>
//#include <math.h>
//
//#define N 10
//
//int main(void) {
//    int coefficients[N + 1] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11 };
//    double x, result = 0.0;
//
//    printf("x ���� �Է��ϼ���: ");
//    scanf_s("%lf", &x);
//
//    for (int i = 0; i <= N; i++) {
//        result += coefficients[i] * pow(x, i);
//    }
//
//    printf("���� ����� %.2lf�Դϴ�\n", result);
//
//    return 0;
//}

//7
//#include <stdio.h>
//
//#define LENGTH 10
//
//int main(void) {
//    int arr[LENGTH];
//    int i, j;
//    int isUnique;
//
//    printf("�迭�� ���̸� �Է��ϼ���: %d\n", LENGTH);
//    printf("�迭 ��Ҹ� �Է��ϼ���: ");
//    for (i = 0; i < LENGTH; i++) {
//        scanf_s("%d", &arr[i]);
//    }
//
//    printf("����ũ�� ��: ");
//    for (i = 0; i < LENGTH; i++) {
//        isUnique = 1;
//        for (j = 0; j < i; j++) {
//            if (arr[i] == arr[j]) {
//                isUnique = 0;
//                break;
//            }
//        }
//        if (isUnique) {
//            printf("%d ", arr[i]);
//        }
//    }
//    printf("\n");
//}

//8
//#include <stdio.h>
//
//#define LENGTH 5
//
//int main() {
//    int arr[LENGTH];
//    int i;
//
//    printf("�迭�� ���̸� �Է��ϼ���: %d\n", LENGTH);
//    printf("�迭 ��Ҹ� �Է��ϼ���: ");
//    for (i = 0; i < LENGTH; i++) {
//        scanf_s("%d", &arr[i]);
//    }
//
//    printf("¦��: ");
//    for (i = 0; i < LENGTH; i++) {
//        if (~arr[i]&1) {
//            printf("%d ", arr[i]);
//        }
//    }
//    printf("\n");
//
//    return 0;
//}
//9
//#include <stdio.h>
//
//#define LENGTH 5
//
//int main() {
//    int arr[LENGTH];
//    int i;
//    int min, max;
//
//    printf("�迭�� ���̸� �Է��ϼ���: %d\n", LENGTH);
//    printf("�迭 ��Ҹ� �Է��ϼ���: ");
//    for (i = 0; i < LENGTH; i++) {
//        scanf_s("%d", &arr[i]);
//    }
//
//    min = arr[0];
//    max = arr[0];
//
//    for (i = 1; i < LENGTH; i++) {
//        if (arr[i] < min) {
//            min = arr[i];
//        }
//        if (arr[i] > max) {
//            max = arr[i];
//        }
//    }
//
//    printf("�ּҰ�: %d, �ִ밪: %d\n", min, max);
//
//    return 0;
//}

////10
//#include <stdio.h>
//
//#define LENGTH 5
//
//int main(void) {
//    int arr[LENGTH];
//    int i, sum = 0;
//
//    printf("�迭�� ���̸� �Է��ϼ���: %d\n", LENGTH);
//    printf("�迭 ��Ҹ� �Է��ϼ���: ");
//    for (i = 0; i < LENGTH; i++) {
//        scanf_s("%d", &arr[i]);
//    }
//
//    for (i = 0; i < LENGTH; i++) {
//        sum += arr[i];
//    }
//
//    printf("����: %d\n", sum);
//}







