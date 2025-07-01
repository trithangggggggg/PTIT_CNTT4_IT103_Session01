//
// Created by ROG on 7/1/2025.
//
#include<stdio.h>

int main() {
    int n;
    int arr[1000];
    printf("Nhap so phan tu: ");
    scanf("%d", &n);
    if (n <= 0 || n > 1000) {
        printf("So luong phan tu khong hop le!!");
        return 1;
    }
    printf("Nhap cac phan tu:\n");
    for (int i = 0; i < n; i++) {
        printf("Nhap phan tu %d: ", i + 1);
        scanf("%d", &arr[i]);
    }
    printf("Mang ban dau: [");
    for (int i = 0; i < n; i++) {
        printf("%d", arr[i]);
        if (i != n - 1) {
            printf(", ");
        }
    }
    printf("]\n");
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i -1 ; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
    printf("Mang da sap xep: [");
    for (int i = 0; i < n; i++) {
        printf("%d", arr[i]);
        if (i != n - 1) {
            printf(", ");
        }
    }
    printf("]\n");

    return 0;
}