//
// Created by ROG on 6/29/2025.
//
#include <stdio.h>

void nhiPhan(int n) {
    if (n == 0) {
        return;
    }
    printf("%d", n % 2);
    return nhiPhan(n / 2);
}


int main() {
    int n;
    printf("Nhap so n nguyen duong: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Nhap so n nguyen duong!!");
        return 1;
    }else {
        printf("So nhi phan cua %d la: ", n);
        nhiPhan(n);
    }
    printf("\n");

    return 0;
}