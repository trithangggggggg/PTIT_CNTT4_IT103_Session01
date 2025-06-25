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

    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j+1]) {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
    printf("Mang sau khi da xap xep: [");
    for (int i = 0; i < n; i++) {
        printf("%d", arr[i]);
        if (i < n - 1) {
            printf(", ");
        }
    }
    printf("]\n");
    printf("Moi nhap gia tri can tim: ");
    scanf("%d", &value);
    int left = 0;
    int right = n - 1;
    int find = 0;
    while (left <= right) {
        int mid = (left + right) / 2;
        if (arr[mid] == value) {
            find = 1;
            break;
        }else if (arr[mid] > value) {
            right = mid - 1;
        }else {
            left = mid + 1;
        }
    }
    if (find) {
        printf("Phan tu %d co trong mang", value);
    }else {
        printf("Phan tu %d co trong mang", value);
    }




    return 0;
}