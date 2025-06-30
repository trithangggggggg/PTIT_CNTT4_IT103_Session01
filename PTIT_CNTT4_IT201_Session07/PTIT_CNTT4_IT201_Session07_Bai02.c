//
// Created by ROG on 6/30/2025.
//
#include<stdio.h>
void selectionSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int min = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[min]) {
                min = j;
            }
        }
        int temp = arr[i];
        arr[i] = arr[min];
        arr[min] = temp;
    }
}
void print(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}


int main() {
    int n;
    int arr[1000];
    printf("nhap so luong phan tu n: ");
    scanf("%d", &n);
    if(n <= 0) {
        printf("So luong phna tu khong hop le!!!");
        return 1;
    }
    printf("Nhap cac phan tu: \n");
    for (int i = 0; i < n; i++) {
        printf("Nhap phan tu thu %d: ", i + 1);
        scanf("%d", &arr[i]);
    }
    printf("Mang ban dau: ");
    print(arr, n);
    selectionSort(arr, n);
    printf("Mang da sap xep: ");
    print(arr, n);
    return 0;
}