//
// Created by ROG on 7/1/2025.
//
#include <stdio.h>

void quickSort(int arr[], int left, int right) {
    if (left >= right) {
        return;
    }
    int pivot = arr[(left + right)/2];
    int i = left;
    int j = right;
    while (i <= j) {
        while (arr[i] < pivot) {
            i++;
        }
        while (arr[j] > pivot) {
            j--;
        }
        if (i <= j) {
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
            i++;
            j--;
        }
    }
    if (left < j) {
        quickSort(arr, left, j);
    }
    if (i < right) {
        quickSort(arr, i, right);
    }
}

int main() {
    int n;
    printf("Nhap so phan tu: ");
    scanf("%d", &n);
    if (n <= 0 || n > 1000) {
        printf("So luong phna tu khong hop le");
        return 1;
    }
    int arr[1000];
    for (int i = 0; i < n; i++) {
        printf("Nhap phan tu thu %d: ", i + 1);
        scanf("%d", &arr[i]);
    }
    quickSort(arr, 0, n - 1);
    printf("Mang da sap xep: [");
    for (int i = 0; i < n; i++) {
        printf("%d", arr[i]);
        if (i != n - 1) {
            printf(", ");
        }
    }
    printf("]");

    return 0;
}