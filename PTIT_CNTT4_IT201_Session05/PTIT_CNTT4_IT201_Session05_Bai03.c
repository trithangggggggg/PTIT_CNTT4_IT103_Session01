//
// Created by ROG on 6/26/2025.
//
#include<stdio.h>
int factorial(int n) {
    if (n == 0 || n == 1 ) {
        return 1;
    }
    return n * factorial(n - 1);
}


int main() {
    int n;
    printf("Moi nhap so n nguyen duong: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("So n khong hop le! ");
        return 1;
    }
    int sum = factorial(n);
    printf("giai thua cua %d la: %d ",n ,sum);

    return 0;
}