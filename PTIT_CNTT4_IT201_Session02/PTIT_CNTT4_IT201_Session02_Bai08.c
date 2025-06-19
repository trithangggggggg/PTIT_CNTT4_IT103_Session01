//
// Created by ROG on 6/17/2025.
//
#include <stdio.h>
#include <stdlib.h>

int main() {

    int n;
    printf("Moi nhap so phan tu mang: ");
    scanf("%d", &n);

    int *arr = (int *)malloc(n * sizeof(int));
    printf("Moi nhap %d phan tu cua mang:", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Mang ban dau: \n[");
    for (int i = 0; i < n; i++) {
        printf("%d", arr[i]);
        if (i < n -1 ) {
            printf(", ");
        }
    }
    printf("]\n");
    printf("Output: \n[");
    int first = 1;

    for (int i = 0; i < n; i++) {
        int isMax = 1;
        for (int j = i + 1; j < n;j++) {
            if (arr[i] <= arr[j]) {
                isMax = 0;
                break;
            }
        }
        if (isMax) {
            if (first == 0) {
                printf(", ");
            }
            printf("%d", arr[i]);
            first = 0;
        }
    }
    printf("]\n");
    free(arr);

    return  0;
}