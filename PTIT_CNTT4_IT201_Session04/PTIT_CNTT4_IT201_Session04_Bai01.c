//
// Created by ROG on 6/25/2025.
//
#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, value;
    printf("Moi nhap so luong cua mang: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("So luong phan tu khong hop le!!\n");
        return 1;
    }
    int arr[n];

    printf("Moi nhap cac phan tu cua mang: \n");
    for (int i = 0; i < n; i++) {
        printf("Nhap phan tu thu %d: ", i + 1);
        scanf("%d", &arr[i]);
    }
    printf("Mang : [");
    for (int i = 0; i < n; i++) {
        printf("%d", arr[i]);
        if (i < n - 1) {
            printf(", ");
        }
    }
    printf("]\n");

    printf("Nhap gia tri can tim: ");
    scanf("%d", &value);
    int find = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] == value) {
            printf("Chi so cua phan tu %d dau tien la: %d",value, i);
            find = 1;
            break;
        }
    }
    if (!find) {
        printf("Khong tim thay phan tu %d trong mang", value);
    }

    return 0;
}