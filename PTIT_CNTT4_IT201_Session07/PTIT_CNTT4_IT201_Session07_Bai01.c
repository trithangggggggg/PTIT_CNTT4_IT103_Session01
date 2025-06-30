//
// Created by ROG on 6/30/2025.
//
#include <stdio.h>

void bublesoft(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}
void print(int arr[],int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int n;
    int arr[1000];
    printf("Nhap so luong phan tu: ");
    scanf("%d", &n);
    if(n <= 0) {
        printf("So luong khong hop le!!!!");
        return 1;
    }
    printf("Nhap cac phan tu: \n");
    for (int i = 0; i < n; i++) {
        printf("Nhap phan tu thu %d: ", i + 1);
        scanf("%d", &arr[i]);
    }
    printf("Mang ban dau: ");
    print(arr, n);
    bublesoft(arr, n);
    printf("Mang da xap xep: ");
    print(arr, n);

    return 0;
}