//
// Created by ROG on 6/23/2025.
//

#include <stdio.h>
#include <stdlib.h>

int main() {
    int rows, cols;
    printf("Nhap so hang rows: ");
    scanf("%d", &rows);
    printf("Nhap so cot cols: ");
    scanf("%d", &cols);
    if (rows <= 0 || rows > 1000 || cols <= 0 || cols > 1000) {
        if (rows <= 0 && cols <= 0) {
            printf("So cot va hang khong hop le");
        }else if (cols <= 0) {
            printf("So cot khong hop le");
        }else if (rows <= 0) {
            printf("So hang khong hop le");
        }
        return 1;
    }
    int **matrix = (int **)malloc(rows * sizeof (int *));
    for (int i = 0; i < rows; i++) {
        matrix[i] = (int *)malloc(cols * sizeof (int));
    }


    printf("Nhap cac phan tu cua mang:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("Phan tu [%d][%d]: ",i,j);
            scanf("%d", &matrix[i][j]);
        }
    }

    int max, min;
    int isFirstElement = 1;

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (isFirstElement == 1) {
                max = matrix[i][j];
                min = matrix[i][j];
                isFirstElement = 0;
            }else {
                if (matrix[i][j] > max) {
                    max = matrix[i][j];
                }
                if (matrix[i][j] < min) {
                    min = matrix[i][j];
                }
            }
        }
    }
    printf("max = %d\n ",max);
    printf("min = %d\n ",min);

    free(matrix);

    return 0;
}