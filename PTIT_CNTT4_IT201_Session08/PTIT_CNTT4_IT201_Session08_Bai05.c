//
// Created by ROG on 7/1/2025.
//
#include <stdio.h>


int main() {
    int n;
    int arr[1000];
    printf("Nhap so luong phan tu terong mang: ");
    scanf("%d", &n);
    if (n <= 0 || n > 1000) {
        printf("So luong phan tu khong hop le!!");
        return 1;
    }
    printf("Nhap cac phan tu cua mang: \n");
    for (int i = 0; i < n; i++) {
        printf("Phan tu thu %d: ", i + 1);
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

    for (int i = 1; i < n; i++) {
        int num = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > num) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = num;
    }
    printf("Mang da saap xep: [");
    for (int i = 0; i < n; i++) {
        printf("%d", arr[i]);
        if (i != n - 1) {
            printf(", ");
        }
    }
    printf("]\n");

    return 0;
}