//
// Created by ROG on 6/17/2025.
//
#include <stdio.h>
#include <stdlib.h>


int findValueMax(int * arr, int size) {
    if (size <= 0) {
        return 0;
    }
    int max = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}

int main() {
    int size;
    printf("Moi nhap so luong phan tu (1-100): \n");
    scanf("%d", &size);

    if (size <= 0 || size > 100) {
        printf("So luong pan tu khong hop le \n");
        return 1;
    }

    int* arr = (int* )malloc(size * sizeof(int));
    if (arr == NULL) {
        printf("cap pat bo nho thhat bai \n");
        return 1;
    }

    printf("Moi nhap %d phan tu: \n", size);
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }
    int max = findValueMax(arr, size);
    printf("Phan tu lon nhat la: %d \n", max);

    free(arr);

    return 0;
}
