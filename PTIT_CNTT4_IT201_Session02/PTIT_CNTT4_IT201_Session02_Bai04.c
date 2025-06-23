//
// Created by ROG on 6/17/2025.
//
#include <stdio.h>

int main() {
    int n, arr[100];
    int position, newValue;

    printf("Nhap so luong phan tu (1-100): ");
    scanf("%d", &n);

    printf("Nhap %d phan tu: ",n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Moi nhap vi tri muon sua (0-%d): ",n -1);
    scanf("%d", &position);

    printf("Moi nhap gia tri moi: ");
    scanf("%d", &newValue);

    if (position >= 0 && position < n) {
        arr[position] = newValue;
    } else {
        printf("Vi tri khong hop le \n");
        return 1;
    }
    printf("Mang sau khi da cap nhat: \n [ ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
        if (i != n - 1) {
            printf(", ");
        }
    }
    printf("]\n");


    return 0;
}

