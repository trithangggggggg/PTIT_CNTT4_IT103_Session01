//
// Created by ROG on 6/30/2025.
//
#include<stdio.h>

int step(int n) {
    if (n < 0) {
        return 0;
    }
    if (n == 0) {
        return 1;
    }
    return step (n - 1) + step(n - 2);
}

int main() {
    int n;
    printf("Nhap so bac cau thang: ");
    scanf("%d", &n);
    if (n < 0) {
        printf("So bac khong hop le!!");
        return 1;
    }
    int result = step(n);
    printf("So cach leo cau thang la: %d", result);
    return 0;
}