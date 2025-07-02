//
// Created by ROG on 7/2/2025.
//
#include<stdio.h>

void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

int linearSearch(int arr[], int n, int searchValue) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == searchValue) {
            // printf("Da tim thay phan tu %d ow vi tri %d\n",searchValue, i+1);
            return i;
        }
    }
    return -1;

}


int binarySearch(int arr[], int n, int searchValue) {
    int left = 0;
    int right = n - 1;
    while (left <= right) {
        int mid = (left + right) / 2;
        if (arr[mid] == searchValue) {
            return mid;
        }else if (arr[mid] < searchValue) {
            left = mid + 1;
        }else {
            right = mid - 1;
        }
    }
    return -1;
}

void printArray(int arr[], int n) {
    printf("[");
    for (int i = 0; i < n; i++) {
        printf("%d", arr[i]);
        if (i != n - 1) {
            printf(", ");
        }
    }
    printf("]\n");
}


int main() {
    int n, searchValue;
    int arr[100];
    printf("Nhap so luong phan tu: ");
    scanf("%d", &n);
    if (n <= 0 || n > 100) {
        printf("So luong phan tu khong hop le");
        return 1;
    }
    printf("Nhap cac phan tu: \n");
    for (int i = 0; i < n; i++) {
        printf("Phan tu thu %d: ", i + 1);
        scanf("%d", &arr[i]);
    }
    printf("Mang ban dau: ");
    printArray(arr, n);
    printf("\n");

    printf("Mang da duoc sap xep insertionSort: ");
    insertionSort(arr, n);
    printArray(arr, n);
    printf("\n");

    printf("Nhap gia tri can tim (linearSearch): ");
    scanf("%d", &searchValue);
    int resultL = linearSearch(arr, n, searchValue);
    if (resultL == -1) {
        printf("khong tim thay phan tu %d trong mang.\n", searchValue);
    }else {
        printf("Tim thay %d tai vi tri %d trong mang.\n", searchValue, resultL );
    }

    printf("Nhap gia tri can tim (binarySearch): ");
    scanf("%d", &searchValue);
    int resultB = binarySearch(arr, n, searchValue);
    if (resultB == -1) {
        printf("khong tim thay phan tu %d trong mang.\n", searchValue);
    }else {
        printf("Tim thay %d tai vi tri %d trong mang\n", searchValue, resultB );
    }


    return 0;
}