// 5
//#include <stdio.h>
//
//int main(void) {
//    int n1, n2;
//    int* p1, * p2;
//    int sum, diff;
//    printf("�� ������ �Է��ϼ���: ");
//    scanf_s("%d %d", &n1, &n2);
//
//    p1 = &n1;
//    p2 = &n2;
//    sum = *p1 + *p2;
//    diff = *p1 - *p2;
//
//    printf("��: %d\n", sum);
//    printf("��: %d\n", diff);
//}

//6
//#include <stdio.h>
//
//void swap(int* a, int* b) {
//    int temp = *a;
//    *a = *b;
//    *b = temp;
//}
//
//int main(void) {
//    int num1, num2;
//    int* ptr1, * ptr2;
//    printf("�� ������ �Է��ϼ���: ");
//    scanf_s("%d %d", &num1, &num2);
//
//    ptr1 = &num1;
//    ptr2 = &num2;
//    swap(ptr1, ptr2);
//
//    printf("ù ��° ��: %d, �� ��° ��: %d\n", num1, num2);
//}

//7
//#include <stdio.h>
//#include <stdlib.h>
//
//int main(void) {
//    int num;
//    int* ptr;
//
//    printf("������ �Է��ϼ���: ");
//    scanf_s("%d", &num);
//
//    ptr = &num;
//
//    *ptr = abs(*ptr);
//
//    printf("����: %d\n", num);
//}

//8
//#include <stdio.h>
//
//int main(void) {
//    float num1, num2;
//    float* ptr1, * ptr2;
//    float product;
//
//    printf("�� �Ǽ��� �Է��ϼ���: ");
//    scanf_s("%f %f", &num1, &num2);
//
//    ptr1 = &num1;
//    ptr2 = &num2;
//
//    product = (*ptr1) * (*ptr2);
//
//    printf("��: %.1f\n", product);
//}

//9
//#include <stdio.h>
//#include <string.h>
//
//int main(void) {
//    char str[100]; 
//    char* ptr; 
//    int length;
//
//    printf("���ڿ��� �Է����ּ���: ");
//    fgets(str, sizeof(str), stdin);
//
//    ptr = str;
//
//    length = strlen(ptr);
//
//    printf("���ڿ� ���� ���: %d\n", length - 1);
//}

//10
//#include <stdio.h>
//
//int main(void) {
//    float num1, num2;
//    float* ptr1, * ptr2;
//    float average;
//
//    printf("�� �Ǽ��� �Է��ϼ���: ");
//    scanf_s("%f %f", &num1, &num2);
//
//    ptr1 = &num1;
//    ptr2 = &num2;
//
//    average = (*ptr1 + *ptr2) / 2.0;
//
//    printf("���: %.1f\n", average);
//}

//11
//#include <stdio.h>
//
//int main(void) {
//    int num;
//    int* ptr;
//
//    printf("������ �ϳ� �Է����ּ���: ");
//    scanf_s("%d", &num);
//
//    ptr = &num;
//
//    printf("��� ���: ");
//    for (int i = 1; i <= *ptr; i++) {
//        if (*ptr % i == 0) {
//            printf("%d ", i);
//        }
//    }
//    printf("\n");
//}

//12
//#include <stdio.h>
//
//int main() {
//    int arr[10];
//    int n = 10;
//    int* ptr;
//
//    printf("�迭 �ȿ� ���� ���Ҹ� �ۼ����ּ���: ");
//    for (int i = 0; i < n; i++) {
//        scanf_s("%d", &arr[i]);
//    }
//
//    ptr = &arr[n - 1];
//
//    printf("���� ���: ");
//    for (int i = 0; i < n; i++) {
//        printf("%d ", *(ptr - i));
//    }
//    printf("\n");
//
//    return 0;
//}

// 13
//#include <stdio.h>
//
//int main(void) {
//    int num1, num2;
//    int* ptr1, * ptr2;
//    int difference;
//
//    printf("���� �ΰ� �Է����ּ���: ");
//    scanf_s("%d %d", &num1, &num2);
//
//
//    ptr1 = &num1;
//    ptr2 = &num2;
//    difference = *ptr1 - *ptr2;
//
//    printf("�� ������ ���̴�: %d\n", difference);
//}

//14
//#include <stdio.h>
//
//#define SIZE 5
//
//int main(void) {
//    int arr1[SIZE], arr2[SIZE];
//    int* ptr1, * ptr2;
//    int temp;
//
//    printf("ù �迭�� ��Ҹ� �Է����ּ���: ");
//    for (int i = 0; i < SIZE; i++) {
//        scanf_s("%d", &arr1[i]);
//    }
//
//    printf("��° �迭�� ��Ҹ� �Է����ּ���: ");
//    for (int i = 0; i < SIZE; i++) {
//        scanf_s("%d", &arr2[i]);
//    }
//
//    for (int i = 0; i < SIZE; i++) {
//        ptr1 = &arr1[i];
//        ptr2 = &arr2[i];
//
//        temp = *ptr1;
//        *ptr1 = *ptr2;
//        *ptr2 = temp;
//    }
//
//    printf("��ȯ1: ");
//    for (int i = 0; i < SIZE; i++) {
//        printf("%d ", arr1[i]);
//    }
//    printf("\n");
//
//    printf("��ȯ2: ");
//    for (int i = 0; i < SIZE; i++) {
//        printf("%d ", arr2[i]);
//    }
//    printf("\n");
//}

//15
//#include <stdio.h>
//
//int main(void) {
//    int num;
//    int* ptr;
//
//    printf("���� �ϳ��� �Է����ּ���: ");
//    scanf_s("%d", &num);
//
//    ptr = &num;
//    *ptr = (*ptr) * (*ptr);
//
//    printf("����: %d\n", num);
//}

//16
//#include <stdio.h>
//
//int main() {
//    float num1, num2;
//    float* ptr1, * ptr2;
//    float average;
//
//    printf("�� �Ǽ��� �Է����ּ���: ");
//    scanf_s("%f %f", &num1, &num2);
//
//    ptr1 = &num1;
//    ptr2 = &num2;
//
//    average = (*ptr1 + *ptr2) / 2.0;
//
//    printf("���: %.2f\n", average);
//
//    return 0;
//}

//17
//#include <stdio.h>
//
//int main(void) {
//    char str[100];
//    char* ptr;
//    int length = 0;
//
//    printf("���ڿ��� �Է��ϼ���: ");
//    fgets(str, sizeof(str), stdin);
//
//    ptr = str;
//
//    while (*ptr != '\0') {
//        length++;
//        ptr++;
//    }
//
//    if (length > 0 && str[length - 1] == '\n') {
//        length--;
//    }
//
//    printf("����: %d\n", length);
//}

//18
//#include <stdio.h>
//
//#define SIZE 5
//
//int main(void) {
//    int arr[SIZE];
//    int n = SIZE;
//    int* ptr;
//    int min;
//
//    printf("�迭�� ��ҵ鸦 �Է����ּ���: ");
//    for (int i = 0; i < n; i++) {
//        scanf_s("%d", &arr[i]);
//    }
//
//    ptr = arr;
//    min = *ptr;
//
//    for (int i = 1; i < n; i++) {
//        if (*(ptr + i) < min) {
//            min = *(ptr + i);
//        }
//    }
//
//    printf("�ּҰ�: %d\n", min);
//}

//19
//#include <stdio.h>
//
//int main() {
//    int num;
//    int* ptr;
//
//    printf("������ �ϳ� �Է����ּ���: ");
//    scanf_s("%d", &num);
//
//    ptr = &num;
//
//    printf("��� ���: ");
//    for (int i = 1; i <= *ptr; i++) {
//        if (*ptr % i == 0) {
//            printf("%d ", i);
//        }
//    }
//    printf("\n");
//
//    return 0;
//}

//20
// #include <stdio.h>
//
//#define SIZE 5 
//
//int main(void) {
//    int arr[SIZE];
//    int n = SIZE;
//    int* ptr;
//    int sum = 0;
//
//    printf("�迭�� ��Ҹ� �Է����ּ���: ");
//    for (int i = 0; i < n; i++) {
//        scanf_s("%d", &arr[i]);
//    }
//
//    ptr = arr;
//
//    for (int i = 0; i < n; i++) {
//        sum += *ptr;
//        ptr++;
//    }
//
//    printf("�迭 ����� ����: %d\n", sum);
//}

//21
//#include <stdio.h>
//
//int main(void) {
//    int num1, num2;
//    int* ptr1, * ptr2;
//    int sum, difference;
//
//    printf("�ΰ��� ������ �Է��ϼ���: ");
//    scanf_s("%d %d", &num1, &num2);
//
//    ptr1 = &num1;
//    ptr2 = &num2;
//
//    sum = *ptr1 + *ptr2;
//    difference = *ptr1 - *ptr2;
//
//    printf("��: %d\n", sum);
//    printf("��: %d\n", difference);
//}

//22
//#include <stdio.h>
//
//int main() {
//    int num;
//    int* ptr;
//
//    printf("������ �ϳ� �Է����ּ���: ");
//    scanf_s("%d", &num);
//
//    ptr = &num;
//
//    for (int i = 0; i < 5; i++) {
//        (*ptr)++;
//        printf("%d\n", *ptr);
//    }
//
//    return 0;
//}

//23
//#include <stdio.h>
//
//#define SIZE 5
//
//int main(void) {
//    int arr[SIZE];
//    int* ptr;
//    int n = SIZE;
//
//    ptr = arr;
//    printf("�迭�� �ȿ� ���� ���� �Է����ּ���: ");
//    for (int i = 0; i < n; i++) {
//        scanf_s("%d", ptr + i);
//    }
//
//    for (int i = 0; i < n; i++) {
//        *(ptr + i) *= 2;
//    }
//
//    printf("�� ��: ");
//    for (int i = 0; i < n; i++) {
//        printf("%d ", *(ptr + i));
//    }
//    printf("\n");
//}

//24
//#include <stdio.h>
//
//int main(void) {
//    int num1, num2;
//    int* ptr1, * ptr2;
//
//    printf("�ΰ��� ������ �Է����ּ���: ");
//    scanf_s("%d %d", &num1, &num2);
//
//    ptr1 = &num1;
//    ptr2 = &num2;
//
//    if (*ptr1 > *ptr2) {
//        printf("�� ū ����: %d\n", *ptr1);
//    }
//    else if (*ptr1 < *ptr2) {
//        printf("�� ū ����: %d\n", *ptr2);
//    }
//    else {
//        printf("�� ���ڴ� �����ϴ�: %d\n", *ptr1);
//    }
//}

//25
//#include <stdio.h>
//
//int add(int* a, int* b) {
//    return *a + *b;
//}
//
//int main(void) {
//    int num1, num2;
//    int sum;
//
//    printf("�ΰ��� ������ �Է����ּ���: ");
//    scanf_s("%d %d", &num1, &num2);
//
//    sum = add(&num1, &num2);
//
//    printf("��: %d\n", sum);
//}

//26
//#include <stdio.h>
//
//#define SIZE 5
//
//void doubleArrayElements(int* arr, int length) {
//    for (int i = 0; i < length; i++) {
//        *(arr + i) *= 2;
//    }
//}
//
//int main(void) {
//    int arr[SIZE];
//    int n;
//
//    printf("�迭�� ���̸� �Է����ּ���: ");
//    scanf_s("%d", &n);
//
//    printf("�迭�� ��ҵ��� �Է��ϼ���: ");
//    for (int i = 0; i < n; i++) {
//        scanf_s("%d", &arr[i]);
//    }
//
//    doubleArrayElements(arr, n);
//
//    printf("�� ��: ");
//    for (int i = 0; i < n; i++) {
//        printf("%d ", arr[i]);
//    }
//    printf("\n");
//}

//27
//#include <stdio.h>
//
//float calculateAverage(float* a, float* b) {
//    return (*a + *b) / 2.0;
//}
//
//int main() {
//    float num1, num2;
//    float average;
//
//    printf("�ΰ��� �Ǽ��� �Է����ּ���: ");
//    scanf_s("%f %f", &num1, &num2);
//
//    average = calculateAverage(&num1, &num2);
//
//    printf("���: %.2f\n", average);
//}

//28
//#include <stdio.h>
//#include <string.h>
//
//int stringLength(char* str) {
//    return strlen(str);
//}
//
//int main(void) {
//    char str[100];
//    int length;
//
//    printf("���ڿ��� �Է����ּ���: ");
//    fgets(str, sizeof(str), stdin);
//    str[strcspn(str, "\n")] = '\0';
//
//    length = stringLength(str);
//
//    printf("���ڿ� ����: %d\n", length);
//}

//29
//#include <stdio.h>
//#define SIZE 5
//
//int findMax(int* arr, int length) {
//    int max = *arr;
//    for (int i = 1; i < length; i++) {
//        if (*(arr + i) > max) {
//            max = *(arr + i);
//        }
//    }
//    return max;
//}
//
//int main(void) {
//    int arr[SIZE];
//    int n, max;
//
//    printf("�迭�� ���̸� �Է����ּ���: ");
//    scanf_s("%d", &n);
//
//    printf("�迭�� ��Ҹ� �Է����ּ���: ");
//    for (int i = 0; i < n; i++) {
//        scanf_s("%d", &arr[i]);
//    }
//
//    max = findMax(arr, n);
//
//    printf("�迭�� �ִ밪: %d\n", max);
//}

//30
//#include <stdio.h>
//#include <math.h>
//
//float calculateSquareRoot(int* num) {
//    return sqrt((float)(*num));
//}
//
//int main(void) {
//    int num;
//    float squareRoot;
//
//    printf("������ �ϳ� �Է����ּ���: ");
//    scanf_s("%d", &num);
//
//    squareRoot = calculateSquareRoot(&num);
//    printf("����: %.2f\n", squareRoot);
//}


