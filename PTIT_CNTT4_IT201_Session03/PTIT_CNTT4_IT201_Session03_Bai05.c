//
// Created by ROG on 6/23/2025.
//
#include <stdio.h>
#include <stdlib.h>

int sumC(int **matrix, int size) {
    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += matrix[i][i];
    }
    return sum;
}

int sumP(int **matrix, int size) {
    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += matrix[i][size - 1 - i];
    }
    return sum;
}

int main() {
    int rows, cols;
    printf("Nhap so hang rows: ");
    scanf("%d", &rows);
    printf("Nhap so cot cols: ");
    scanf("%d", &cols);
    if (rows <= 0 && cols <= 0) {
        printf("So cot va so hang khong hop le ");
        return 1;
    }else if (rows <= 0) {
        printf("So hang khong hop le ");
        return 1;
    }else if (cols <= 0) {
        printf("So cot khong hop le ");
        return 1;
    }
    int **matrix = (int **)malloc(rows * sizeof (int *));
    for (int i = 0; i < rows; i++) {
        matrix[i] = (int *)malloc(cols * sizeof (int));
    }
    printf("Nhapp cac phan tu cua ma tran: \n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("Phan tu [%d][%d]: ", i, j);
            scanf("%d", &matrix[i][j]);
        }
    }
    if (rows != cols) {
        printf("khong ton tai duong cheo chinh\n ");
        printf("Khong ton tai duong cheo phu \n");
    }else {
        int endC = sumC(matrix, rows);
        int endP = sumP(matrix, cols);
        printf("Tong duong cheo chinh = %d\n",endC);
        printf("Tong duong cheo phu = %d\n",endP);
    }
    for (int i = 0; i < rows; i++) {
        free(matrix[i]);
    }
    free(matrix);

    return 0;
}