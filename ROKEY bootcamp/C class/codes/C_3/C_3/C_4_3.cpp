//14
//#include <stdio.h>
//
//#define length 5
//
//int main(void) {
//    int arr[length];
//    int i, j, temp;
//
//    printf("�迭�� ���̴� 5�Դϴ�.");
//    printf("�迭 ��Ҹ� �Է��ϼ���: ");
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
//    printf("���ĵ� �迭: ");
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
//    printf("�迭�� ���̸� �Է��ϼ���: %d\n", LENGTH);
//    printf("�迭 ��Ҹ� �Է��ϼ���: ");
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
//    printf("�ּҰ� ��ġ: %d\n", min_index);
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
//    printf("�迭�� ���̸� �Է��ϼ���: %d\n", LENGTH);
//    printf("�迭 ��Ҹ� �Է��ϼ���: ");
//    for (i = 0; i < LENGTH; i++) {
//        scanf_s("%d", &arr[i]);
//    }
//
//    for (i = 0; i < LENGTH; i++) {
//        product *= arr[i];
//    }
//
//    printf("��ҵ��� ��: %d\n", product);
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
//    printf("�迭�� ����: 7\n");
//    printf("�迭 ��Ҹ� �Է��ϼ���: ");
//    for (i = 0; i < LENGTH; i++) {
//        scanf_s("%d", &arr[i]);
//    }
//
//    printf("ã���� �ϴ� ���ڸ� �Է��ϼ���: ");
//    scanf_s("%d", &target);
//
//    printf("���� %d ��ġ: ", target);
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
//    printf("�迭�� ���̸� �Է��ϼ���: %d\n", LENGTH);
//    printf("�迭 ��Ҹ� �Է��ϼ���: ");
//    for (i = 0; i < LENGTH; i++) {
//        scanf_s("%d", &arr[i]);
//    }
//
//    printf("�׷� ��: ");
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
//    printf("�迭�� ���̸� �Է��ϼ���: %d\n", LENGTH);
//    printf("�迭 ��Ҹ� �Է��ϼ���: ");
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
//    printf("�̵� �� �迭: ");
//    for (i = 0; i < LENGTH; i++) {
//        printf("%d ", arr[i]);
//    }
//    printf("\n");
//
//    return 0;
//}

