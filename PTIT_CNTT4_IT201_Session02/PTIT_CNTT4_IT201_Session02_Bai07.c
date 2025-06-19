//
#include <stdio.h>
#include <stdlib.h>

int main() {

    int n, sum;
    printf("Moi nhap so phan tu cua mang: ");
    scanf("%d", &n);

    int* arr=(int*)malloc(n*sizeof(int));
    printf("Moi nhap %d phan tu cua mang: ", n);
    for (int i = 0;i < n; i++) {
        scanf("%d", &arr[i]);
    }
    printf("Mang  ban dau: \n[");
    for (int i = 0; i < n; i++) {
        printf("%d", arr[i]);
        if (i != n - 1) {
            printf(", ");
        }
    }
    printf("]\n");

    printf("Nhap so can tim tong:");
    scanf("%d", &sum);
    int find = 0;
    for (int i = 0; i < n -1;i++) {
        for (int j = i + 1; j  < n;j++) {
            if (arr[i] + arr[j] == sum) {
                printf("%d, %d", arr[i], arr[j]);
                find = 1;
                break;
            }
        }
    }
    if (!find) {
        printf("Khong tim thay\n");
    }
    free(arr);

    return 0;
}