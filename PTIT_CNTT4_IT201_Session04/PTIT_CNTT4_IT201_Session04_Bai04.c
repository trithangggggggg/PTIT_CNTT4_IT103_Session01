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
    printf("Moi nhap gia tri can tim: ");
    scanf("%d", &value);
    int index = -1;
    for (int i = 0; i < n; i++) {
        if (arr[i] == value) {
            index = i;
        }
    }
    if (index == -1) {
        printf("Khong tim thay phan tu %d",value);
    }else {
        printf("Chi so cua phan tu cuoi cung bang %d la: %d",value, index);
    }


    return 0;
}
