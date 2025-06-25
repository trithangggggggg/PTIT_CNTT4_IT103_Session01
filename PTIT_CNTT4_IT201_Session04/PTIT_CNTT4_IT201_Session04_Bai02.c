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

    int max = arr[0];
    int index = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
            index = i;
        }
    }
    printf("Chi so cua phan tu lon nhat dau tien: %d (%d)", index, max);

    return 0;
}
