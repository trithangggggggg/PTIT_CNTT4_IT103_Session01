//
// Created by ROG on 6/26/2025.
//
#include <stdio.h>

int total(int firstNum, int secondNum) {
    if(firstNum > secondNum) {
        return 0;
    }
    return firstNum + total(firstNum + 1, secondNum);
}

int main() {
    int a, b;
    printf("Nhap so nguyen firstNumber: ");
    scanf("%d", &a);
    printf("Nhap so nguyen secondNumber: ");
    scanf("%d", &b);

    int sum = total(a, b);
    printf("TOng tu %d den %d la: %d", a, b, sum);

    return 0;
}