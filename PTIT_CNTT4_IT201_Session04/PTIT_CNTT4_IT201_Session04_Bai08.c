//
// Created by ROG on 6/25/2025.
//
#include <stdio.h>
int main() {
    int n, x;
    printf("Nhap so luong phan tu cua mang: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("So luong phan tu khong hop le!!\n");
        return 1;
    }
    int arr[n];
    printf("Nhaap cac phn tu cua mang: \n");
    for (int i = 0; i < n; i++) {
        printf("Nhap phan tu thu %d: ", i+ 1);
        scanf("%d", &arr[i]);
    }
    printf("Nhaap gia tri can tim: ");
    scanf("%d", &x);

    int find = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] == x) {
            if (find == 0) {
                printf("Vi tri xuat hien: ");
            }
            printf("%d ", i + 1);
            find = 1;
        }
    }
    if (!find) {
        printf("phan tu khong cos trong mang !");
    }

    return 0;
}