//
// Created by ROG on 6/30/2025.
//
#include<stdio.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}
int phanHoach(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;
    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i], &arr[high]);
    return i + 1;
}
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = phanHoach(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}
void print(int arr[], int n) {
    printf("[");
    for (int i = 0; i < n; i++) {
        printf(" %d", arr[i]);
        if (i != n - 1) {
            printf(", ");
        }
    }
    printf("]");
}
int main() {
    int n;
    int arr[1000];
    printf("Nhap so luong phan tu: ");
    scanf("%d", &n);
    if (n <=0) {
        printf("So luong phan tu khong hop le!!");
        return 1;
    }
    printf("Nhap cac phan tu: \n");
    for (int i = 0; i < n; i++) {
        printf("Nhap phan tu thu %d", i + 1);
        scanf("%d", &arr[i]);
    }
    printf("Mang ban dau: ");
    print(arr, n);
    quickSort(arr, 0, n - 1);
    printf("Mang da duocc sap xep: ");
    print(arr, n);


    return 0;
}