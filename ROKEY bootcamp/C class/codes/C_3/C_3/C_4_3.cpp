//14
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
//}

//15
//#include <stdio.h>
//
//#define LENGTH 5
//
//int main() {
//    int arr[LENGTH];
//    int i, min_index;
//
//    printf("배열의 길이를 입력하세요: %d\n", LENGTH);
//    printf("배열 요소를 입력하세요: ");
//    for (i = 0; i < LENGTH; i++) {
//        scanf_s("%d", &arr[i]);
//    }
//
//    min_index = 0;
//    for (i = 1; i < LENGTH; i++) {
//        if (arr[i] < arr[min_index]) {
//            min_index = i;
//        }
//    }
//
//    printf("최소값 위치: %d\n", min_index);
//
//    return 0;
//}

//16
//#include <stdio.h>
//
//#define LENGTH 4
//
//int main() {
//    int arr[LENGTH];
//    int i;
//    int product = 1;
//
//    printf("배열의 길이를 입력하세요: %d\n", LENGTH);
//    printf("배열 요소를 입력하세요: ");
//    for (i = 0; i < LENGTH; i++) {
//        scanf_s("%d", &arr[i]);
//    }
//
//    for (i = 0; i < LENGTH; i++) {
//        product *= arr[i];
//    }
//
//    printf("요소들의 곱: %d\n", product);
//
//    return 0;
//}

//17
//#include <stdio.h>
//
//#define LENGTH 7
//
//int main() {
//    int arr[LENGTH];
//    int i, target;
//
//    printf("배열의 길이: 7\n");
//    printf("배열 요소를 입력하세요: ");
//    for (i = 0; i < LENGTH; i++) {
//        scanf_s("%d", &arr[i]);
//    }
//
//    printf("찾고자 하는 숫자를 입력하세요: ");
//    scanf_s("%d", &target);
//
//    printf("숫자 %d 위치: ", target);
//    for (i = 0; i < LENGTH; i++) {
//        if (arr[i] == target) {
//            printf("%d ", i+1);
//        }
//    }
//    printf("\n");
//
//    return 0;
//}

//18
//#include <stdio.h>
//
//#define LENGTH 6
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
//    printf("그룹 합: ");
//    for (i = 0; i < LENGTH; i += 2) {
//        int group_sum = arr[i] + arr[i + 1];
//        printf("%d ", group_sum);
//    }
//    printf("\n");
//
//    return 0;
//}

////19
//#include <stdio.h>
//#define LENGTH 5
//
//int main() {
//    int arr[LENGTH];
//    int i, first_element;
//
//    printf("배열의 길이를 입력하세요: %d\n", LENGTH);
//    printf("배열 요소를 입력하세요: ");
//    for (i = 0; i < LENGTH; i++) {
//        scanf_s("%d", &arr[i]);
//    }
//
//    first_element = arr[0];
//
//    for (i = 0; i < LENGTH - 1; i++) {
//        arr[i] = arr[i + 1];
//    }
//
//    arr[LENGTH - 1] = first_element;
//
//    printf("이동 후 배열: ");
//    for (i = 0; i < LENGTH; i++) {
//        printf("%d ", arr[i]);
//    }
//    printf("\n");
//
//    return 0;
//}

