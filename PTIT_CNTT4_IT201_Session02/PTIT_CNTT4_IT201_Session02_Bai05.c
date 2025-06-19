//
// Created by ROG on 6/17/2025.
//
#include <stdio.h>
#include <stdlib.h>

int main() {

    int n,daleteIndex;

    printf("Moi nhap so phan tu cua mang: ");
    scanf("%d", &n);

    int* arr = (int*)malloc(n * sizeof(int));

    printf("Moi nhap %d phan tu cua mang: \n", n);
    for (int i = 0; i < n;i++) {
        scanf("%d", &arr[i]);
    }

    printf("Mang ban dau: \n[");
    for (int i = 0; i < n; i++) {
        printf("%d", arr[i]);
        if (i < n-1) {
            printf(", ");
        }
    }
    printf("]\n");

    printf("Moi nhap vi tri muon xoa (0-%d):",n - 1);
    scanf("%d", &daleteIndex);
    if (daleteIndex < 0 || daleteIndex >= n) {
        printf("Vi tri khong hop le!!!!!!!!");
        free(arr);
        return 1;
    }
    for (int i = daleteIndex; i < n; i++) {
        arr[i] = arr[i + 1];
    }
    n--;
    printf("Mang sau khhi da xoa thanh cong: \n[");
    for (int i = 0;i < n;i++) {
        printf("%d", arr[i]);
        if (i < n - 1) {
            printf(", ");
        }
    }
    printf("]\n");
    free(arr);

    return 0;
}