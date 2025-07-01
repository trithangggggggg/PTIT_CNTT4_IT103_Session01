//
// Created by ROG on 7/1/2025.
//
#include<stdio.h>

int main() {
    int n;
    int arr[1000];
    printf("Moi nhap so luong phan tu: ");
    scanf("%d", &n);
    if (n <= 0 || n > 1000) {
        printf("So luong phan tu khong hop le. \n");
        return 1;
    }
    printf("Nhap cac phan tu trong mang: \n");
    for (int i = 0; i < n; i++) {
        printf("Phan tu tu %d: ", i + 1);
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
    printf("Mang sau khi sap xep: [");
    for (int i = 0; i < n; i++) {
        printf("%d", arr[i]);
        if (i != n - 1) {
            printf(", ");
        }
    }
    printf("]\n");

    return 0;
}