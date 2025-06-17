//
// Created by ROG on 6/17/2025.
//
#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, taget;
    int *arr;
    int count = 0;

    printf("Nhap so luong phan tu (1-100): ");
    scanf("%d", &n);

    if (n <= 0|| n >  100) {
        printf("So luong phan tu khong op le");
        return 1;
    }

    arr = (int* ) malloc(n * sizeof(int));
    if (arr == NULL) {
        printf("Khong the cap phhat bo nho \n");
        return 1;
    }

    printf("Nhhap %d phan tu cua mang: \n", n);
    for (int i = 0; i < n; i++) {
        printf("Phhan tu tu %d: ", i + 1);
        scanf("%d", &arr[i]);
    }

    printf("Nhap so can kiem tra: ");
    scanf("%d", &taget);

    for (int i = 0; i < n; i++) {
        if (arr[i] == taget) {
            count++;
        }
    }
    printf("So %d xuat hien %d lan trong mang \n", taget, count);
    free(arr);

    return 0;
}