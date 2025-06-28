//
// Created by ROG on 6/26/2025.
//
#include <stdio.h>
void output(int i, int n) {
    if (i > n) {
        return;
    }
    printf("%d\n", i);
    output(i+1, n);
}

int main() {
    int n;
    printf("Nhap 1 so n nguyen duong: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("SO n khong hop le! ");
        return 1;
    }
    printf("Cac so tu 1 den %d la:\n ", n);
    output(1, n);
    printf("\n");

    return 0;
}