//
// Created by ROG on 6/17/2025.
//
#include <stdio.h>

int main() {
    int n;
    int arr[100];

    printf("Moi nhaap so luong phan tu (1-100):");
    scanf("%d", &n);

    printf("Moi nhap %d phan tu: \n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Mang dao nguoc la: \n [");
    for (int i = n - 1; i >= 0;i--) {
        printf("%d",arr[i]);
        if (i != 0) {
            printf(", ");
        }
    }
    printf("] \n");


    return 0;
}