//
// Created by ROG on 6/26/2025.
//

#include <stdio.h>

int total(int n) {
    if (n <= 0) {
        return 0;
    }
    return  total(n - 1) + n;
}

int main() {
    int n;
    printf("Nhap so nguyen duong n bat ki: " );
    scanf("%d", &n);

    if (n <= 0) {
        printf("khong hop le! ");
        return 1;
    }

    int sum = total(n);
    printf("Tong tu 1 - %d la: %d ",n ,sum);

    return 0;
}