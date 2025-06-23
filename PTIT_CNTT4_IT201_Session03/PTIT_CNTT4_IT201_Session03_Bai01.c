//
// Created by ROG on 6/23/2025.
//
#include <stdio.h>
#include <stdlib.h>

int main() {

    int n;
    printf("Moi nhap so luong phan tu (1-100): ");
    scanf("%d", &n);
    if (n < 1 || n > 100 ) {
        printf("So luong phan tu nhat: ");
        return 1;
    }
    int *arr = (int*)malloc(n * sizeof(int));
    if (arr == NULL) {
        printf("cap [hat bo nho that bai\n");
        return 1;
    }
    printf("Moi nhap cac phan tu trong mang: \n");
    for (int i = 0; i < n;i++) {
        printf("Phan tu thu %d:   ", i + 1);
        scanf("%d", &arr[i]);
    }
    printf("Cac phan tu trong mang:\n[");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
        if (i != n - 1) {
            printf(", ");
        }
    }

    printf("]\n");

    free(arr);


    return 0;
}