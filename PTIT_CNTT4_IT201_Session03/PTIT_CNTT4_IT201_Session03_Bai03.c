//
// Created by ROG on 6/23/2025.
//
#include <stdio.h>
#include <stdlib.h>

int main() {

    int n;
    printf("Moi nhap so phan tu cua mang (1-100): ");
    scanf("%d", &n);
    if (n < 1 || n > 100) {
        printf("So luong phan tu khong hop le");
        return 1;
    }
    int *arr= (int *)malloc(n * sizeof(int));
    if (arr == NULL) {
        printf("Cap phat bo nho that bai");
        return 1;
    }
    printf("Moi nhap cac phan tu cua mang: \n");
    for (int i = 0; i < n;i++) {
        printf("Phan tu thu %d: ",i+1);
        scanf("%d", &arr[i]);
    }
    int sum = 0;
    for (int i = 0; i< n;i++) {
        sum += arr[i];
    }
    int tbc = sum / n;
    printf("Trung binh cong = %d\n", tbc);
    free(arr);

    return 0;
}