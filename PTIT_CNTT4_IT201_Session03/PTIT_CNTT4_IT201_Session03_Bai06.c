//
// Created by ROG on 6/24/2025.
//
#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, m;
    printf("Moi nhap so luong phan tu (1-1000): ");
    scanf("%d", &n);
    if (n <= 0 || n > 1000) {
        printf("So luong phan tu khong hop le! \n");
        return 1;
    }
    int *arr = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        printf("Moi nhap phan tu thu %d cho mang: ", i + 1);
        scanf("%d", &arr[i]);
    }
    printf("Moi ban nhap so phan tu muon them (m): ");
    scanf("%d", &m);
    arr = (int *)realloc(arr, (n + m) * sizeof(int));
    for (int i = n; i < n + m; i++) {
        printf("Moi ban nhap phan tu thu %d cho mang: ", i + 1);
        scanf("%d", &arr[i]);
    }
    printf("Mang hoan thien: \n[");
    for (int i = 0; i < n + m; i++) {
        printf("%d", arr[i]);
        if (i < n + m - 1) {
            printf(", ");
        }
    }
    printf("]\n");
    free(arr);


    return 0;
}