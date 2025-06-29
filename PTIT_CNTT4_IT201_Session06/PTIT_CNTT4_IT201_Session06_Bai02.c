//
// Created by ROG on 6/29/2025.
//
#include<stdio.h>

int fibonaci(int n) {
    if(n == 1 || n == 2) {
        return 1;
    }
    return fibonaci(n - 1) + fibonaci(n - 2);
}
void fibonaciReverse(int n) {
    if (n == 0) {
        return;
    }
    printf("%d", fibonaci(n));
    if (n > 1 ) {
        printf(", ");
    }
    fibonaciReverse(n - 1);
}

int main() {
    int n;
    printf("Nhap so n nguyen duong: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf(" so n khong hop le");
        return 1;
    }
    fibonaciReverse(n);
    printf("\n");

    return 0;
}