//
// Created by ROG on 6/24/2025.
//
#include <stdio.h>
#include <stdlib.h>

void inputMatrix(int matrix[10][10], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("matrix[%d][%d] = ", i, j);
            scanf("%d", &matrix[i][j]);
        }
    }
}

void showMatrix(int matrix[10][10], int rows, int cols) {
    printf("Ma tran: \n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}
int  sum(int matrix[10][10], int rows, int cols) {
    int k, total = 0;
    printf("Nhap chi so muon tinh tong: ");
    scanf("%d", &k);
    if (k < 0 || k >= rows) {
        printf("Mang can tinh khong ton tai!\n");
        return -1;
    }
    for (int j = 0; j < cols; j++) {
        total += matrix[k][j];
    }
    return total;
}

int main() {
    int matrix[10][10];
    int rows, cols;

    printf("Nhap so hang: ");
    scanf("%d", &rows);
    if (rows <= 0 || rows >= 1000) {
        printf("So hang khong hop le! \n");
        return 1;
    }
    printf("Nhap so cot: ");
    scanf("%d", &cols);
    if (cols <= 0 || cols >= 1000) {
        printf("So cot khong hop le! \n");
        return 1;
    }

    inputMatrix(matrix, rows, cols);
    showMatrix(matrix, rows, cols);
    int result = sum(matrix, rows, cols);
    if (result != -1) {
        printf("Sum = %d", result);
    }



    return 0;
}