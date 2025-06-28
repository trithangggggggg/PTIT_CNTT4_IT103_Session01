//
// Created by ROG on 6/26/2025.
//
#include<stdio.h>

int total(int arr[], int n) {
    if (n == 0) {
        return 0;
    }else {
        return arr[n - 1] + total(arr, n - 1);
    }

}

int main() {
    int arr[100];
    int n;
    printf("Nhap so luong phan tu:");
    scanf("%d", &n);
    if (n <= 0) {
        printf("So luong phan tu khong hop le!");
        return 1;
    }
    for (int i = 0; i < n; i++) {
        printf("Nhap phan tu thu %d: ", i + 1);
        scanf("%d", &arr[i]);
    }
    int sum = total(arr, n);
    printf("Tong cua mang: %d", sum);



    return 0;
}