//
// Created by ROG on 6/30/2025.
//
#include<stdio.h>

void insertionSort(int arr[], int n) {
    for(int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while(j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}
void print(int arr[], int n) {
    for(int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}


int main() {
    int n;
    int arr[1000];
    printf("Nhap so luong phan tu: ");
    scanf("%d", &n);
    if (n <= 0) {
        printf("So luong phan tu khong hop le!!!");
        return 1;
    }
    printf("Nhap phan tu: \n");
    for(int i = 0; i < n; i++) {
        printf("Nhap phan tu thu %d: ", i + 1);
        scanf("%d", &arr[i]);
    }
    printf("Mang ban dau: ");
    print(arr, n);
    insertionSort(arr, n);
    printf("Mang da duoc sap xep: ");
    print(arr, n);

    return 0;
}