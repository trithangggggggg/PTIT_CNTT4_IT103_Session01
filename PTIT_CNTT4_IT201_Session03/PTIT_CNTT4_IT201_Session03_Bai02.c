//
// Created by ROG on 6/23/2025.
//
#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    printf("Moi nhap so luong phan tu (1-100): ");
    scanf("%d", &n);
    if (n < 1|| n > 100) {
        printf("So luong phan tu khong hop le\n");
        return 1;
    }
    int *arr = malloc(sizeof(int) * n);
    if (arr == NULL) {
        printf("Cap phat bo nho that bai");
        return 1;
    }
    printf("Moi nhap cac phan tu trong mang: \n");
    for (int i = 0; i < n; i++) {
        printf("Phan tu thu %d: ", i + 1);
        scanf("%d", &arr[i]);
    }
    int max = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    printf("Phan tu lon nhat: %d\n",max);
    free(arr);


    return 0;
}
