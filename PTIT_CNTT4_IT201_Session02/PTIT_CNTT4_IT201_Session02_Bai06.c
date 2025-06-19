#include <stdio.h>
#include <stdlib.h>

int main() {

    int n, value, index;

    printf("Moi nhap so luong phan tu:");
    scanf("%d", &n);

    int *arr = (int*)malloc(n * sizeof(int));
    if (arr == NULL) {
        printf("cap phat bo nho that bai");
        return 1;
    }

    printf("Moi nhap %d phan tu cua mang:\n", n);
    for (int i = 0; i < n;i++) {
        scanf("%d", &arr[i] );
    }
    printf("Mang ban dau: \n[");
    for (int i = 0; i < n; i++) {
        printf("%d", arr[i]);
        if (i < n-1) {
            printf(", ");
        }
    }
    printf("]\n");

    printf("Nhap vi tri can them (0 - %d):", n);
    scanf("%d", &index);
    printf("Nhap gia tri muon them vao vi tri %d:", index);
    scanf("%d", &value);
    if (index < 0 || index > n) {
        printf("Vi tri khong hop le \n");
        free(arr);
        return 1;
    }

    arr = realloc(arr, (n+1) * sizeof(int));
    if (arr == NULL) {
        printf("cap phat bo nho that bai");
        free(arr);
        return 1;
    }
    for (int  i = n; i > index; i--) {
        arr[i] = arr[i - 1];
    }
    arr[index] = value;
    n++;
    printf("Mang sau khi them phan tu: \n[");
    for (int i = 0; i< n; i++) {
        printf("%d", arr[i]);
        if (i < n -1 ) {
            printf(", ");
        }
    }
    printf("]\n");
    free(arr);

    return 0;
}