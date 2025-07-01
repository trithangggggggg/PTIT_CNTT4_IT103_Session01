//
// Created by ROG on 7/1/2025.
//
#include <stdio.h>


int main() {
    int n, search;
    int arr[1000];

    printf("Nhap so luong phan tu cua mang: ");
    scanf("%d", &n);
    if (n <= 0 || n > 1000) {
        printf("So luong khong hop le!!");
        return 1;
    }
    printf("Nhap cac phan tu: \n");
    for (int i = 0; i < n; i++) {
        printf("Nhap phan tu thu %d: ", i + 1);
        scanf("%d", &arr[i]);
    }
    printf("Mang ban dau: \n[");
    for (int i = 0; i < n; i++) {
        printf("%d", arr[i]);
        if (i != n - 1) {
            printf(", ");
        }
    }
    printf("]\n");
    printf("Nhap gia tri can tim: ");
    scanf("%d", &search);
    int find = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] == search) {
            find = 1;
            printf("Gia tri %d nam o vi tri %d", search, i+1);
            break;
        }
    }
    if (!find) {
        printf("Gia tri %d khong co trong mang", search);
    }
    return 0;
}