//1
//#include <stdio.h>
//
//int main() {
//    int length = 10;
//    int array[10];
//    int max;
//    printf("정수를 10개 입력해주세요:\n");
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
//    printf("최대값: %d\n", max);
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
//    printf("역순으로 만들 3개의 배열 요소를 입력해주세요:\n");
//    for (int i = 0; i < length; i++) {
//        scanf_s("%d", &array[i]);
//    }
//
//    printf("역순:\n");
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
//    printf("x 값을 입력하세요: ");
//    scanf_s("%lf", &x);
//
//    for (int i = 0; i <= N; i++) {
//        result += coefficients[i] * pow(x, i);
//    }
//
//    printf("연산 결과는 %.2lf입니다\n", result);
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
//    printf("배열의 길이를 입력하세요: %d\n", LENGTH);
//    printf("배열 요소를 입력하세요: ");
//    for (i = 0; i < LENGTH; i++) {
//        scanf_s("%d", &arr[i]);
//    }
//
//    printf("유니크한 값: ");
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
//    printf("배열의 길이를 입력하세요: %d\n", LENGTH);
//    printf("배열 요소를 입력하세요: ");
//    for (i = 0; i < LENGTH; i++) {
//        scanf_s("%d", &arr[i]);
//    }
//
//    printf("짝수: ");
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
//    printf("배열의 길이를 입력하세요: %d\n", LENGTH);
//    printf("배열 요소를 입력하세요: ");
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
//    printf("최소값: %d, 최대값: %d\n", min, max);
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
//    printf("배열의 길이를 입력하세요: %d\n", LENGTH);
//    printf("배열 요소를 입력하세요: ");
//    for (i = 0; i < LENGTH; i++) {
//        scanf_s("%d", &arr[i]);
//    }
//
//    for (i = 0; i < LENGTH; i++) {
//        sum += arr[i];
//    }
//
//    printf("총합: %d\n", sum);
//}







