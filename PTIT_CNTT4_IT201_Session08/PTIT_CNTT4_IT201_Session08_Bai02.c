//
// Created by ROG on 7/1/2025.
//
#include <stdio.h>

int main() {
    int n, search;
    int arr[1000];
    printf("Nhap so luong phan tu cua mang: ");
    scanf("%d", &n);
    if(n <= 0 || n > 1000) {
        printf("So luong phan tu khong hop le!!");
        return 1;
    }
    printf("Nhap cac phan tu: \n");
    for (int i = 0; i < n; i++) {
        printf("Nhap phan tu %d: ", i + 1);
        scanf("%d", &arr[i]);
    }
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
    printf("Mang sau khi duoc sap xep tang dan:\n [");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
        if (i < n - 1) {
            printf(", ");
        }
    }
    printf("]\n");
    printf("Nhap so can tim: ");
    scanf("%d", &search);
    int left = 0, right = n - 1;
    int find = 0;
    while (left <= right) {
        int mid = (left + right) / 2;
        if (arr[mid] == search) {
            printf("Gia tri %d nam o vi tri thu %d trong mang da sap xep.", search, mid + 1);
            find = 1;
            break;
        }else if (arr[mid] < search) {
            left = mid + 1;
        }else {
            right = mid - 1;
        }
    }
    if (find == 0) {
        printf("Khong ton tai gia tri %d trong mang. ", search);
    }
    return 0;
}