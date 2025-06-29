//
// Created by ROG on 6/29/2025.
//
#include <stdio.h>

int sum(int n) {
    if (n == 0) {
        return 0;
    }
    return (n % 10) + sum(n / 10);
}

int main(void) {
    int n;
    printf("Nhap so nguyen n: ");
    scanf("%d", &n);
    if (n <=0 ) {
        printf("So n khong hop le! ");
        return 1;
    }
    int total = sum(n);
    printf("Tong cac chu so la: %d", total);



    return 0;
}