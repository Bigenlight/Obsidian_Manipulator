// 10
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

//11
//#include <stdio.h>
//
//#define LENGTH 5
//
//int main() {
//    int arr[LENGTH];
//    int i, odd_count = 0, even_count = 0;
//
//    printf("배열의 길이를 입력하세요: %d\n", LENGTH);
//    printf("배열 요소를 입력하세요: ");
//    for (i = 0; i < LENGTH; i++) {
//        scanf_s("%d", &arr[i]);
//    }
//
//    for (i = 0; i < LENGTH; i++) {
//        if (arr[i] % 2 == 0) {
//            even_count++;
//        }
//        else {
//            odd_count++;
//        }
//    }
//
//    printf("홀수 개수: %d, 짝수 개수: %d\n", odd_count, even_count);
//
//    return 0;
//}

//12
//#include <stdio.h>
//
//#define LENGTH 5
//
//int main(void) {
//    int arr[LENGTH];
//    int frequency[LENGTH] = { 0 };
//    int i, j;
//
//    printf("배열의 길이를 입력하세요: %d\n", LENGTH);
//    printf("배열 요소를 입력하세요: ");
//    for (i = 0; i < LENGTH; i++) {
//        scanf_s("%d", &arr[i]);
//    }
//
//    for (i = 0; i < LENGTH; i++) {
//        frequency[i] = 1;
//        for (j = i + 1; j < LENGTH; j++) {
//            if (arr[i] == arr[j]) {
//                frequency[i]++;
//                arr[j] = -1;
//            }
//        }
//    }
//
//    printf("각 요소의 출현 빈도:\n");
//    for (i = 0; i < LENGTH; i++) {
//        if (arr[i] != -1) {
//            printf("%d : %d회\n", arr[i], frequency[i]);
//        }
//    }
//}

//13
//#include <stdio.h>
//
//#define LENGTH 5
//
//int main(void) {
//    int arr[LENGTH];
//    int i;
//    int first_max, second_max;
//    printf("배열의 길이를 입력하세요: %d\n", LENGTH);
//    printf("배열 요소를 입력하세요: ");
//    for (i = 0; i < LENGTH; i++) {
//        scanf_s("%d", &arr[i]);
//    }
//
//    if (arr[0] > arr[1]) {
//        first_max = arr[0];
//        second_max = arr[1];
//    }
//    else {
//        first_max = arr[1];
//        second_max = arr[0];
//    }
//    for (i = 2; i < LENGTH; i++) {
//        if (arr[i] > first_max) {
//            second_max = first_max;
//            first_max = arr[i];
//        }
//        else if (arr[i] > second_max && arr[i] < first_max) {
//            second_max = arr[i];
//        }
//    }
//    printf("두 번째로 큰 수: %d\n", second_max);
//}

// 14
//#include <stdio.h>
//
//#define length 5
//
//int main(void) {
//    int arr[length];
//    int i, j, temp;
//
//    printf("배열의 길이는 5입니다.");
//    printf("배열 요소를 입력하세요: ");
//    for (i = 0; i < length; i++) {
//        scanf_s("%d", &arr[i]);
//    }
//
//    for (i = 0; i < length - 1; i++) {
//        for (j = 0; j < length - 1 - i; j++) {
//            if (arr[j] > arr[j + 1]) {
//                temp = arr[j];
//                arr[j] = arr[j + 1];
//                arr[j + 1] = temp;
//            }
//        }
//    }
//
//    printf("정렬된 배열: ");
//    for (i = 0; i < length; i++) {
//        printf("%d ", arr[i]);
//    }
//    printf("\n");






