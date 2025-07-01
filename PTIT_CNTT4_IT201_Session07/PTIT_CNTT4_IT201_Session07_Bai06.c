//
// Created by ROG on 6/30/2025.
//
#include<stdio.h>

void meger(int arr[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;
    int L[n1], R[n2];
    for (int i = 0; i < n1; i++) {
        L[i] = arr[left + i];
    }
    for (int j = 0; j < n2; j++) {
        R[j] = arr[mid + 1 + j];
    }
    int i = 0, j = 0, k = left;


    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}
void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        int mid = (left + right) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        meger(arr, left, mid, right);
    }
}
void print(int arr[], int n) {
    printf("[ ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
        if (i != n - 1) {
            printf(", ");
        }
    }
    printf("]\n");
}

int main() {

    int n;
    printf("Nhap so luong phan tu: ");
    scanf("%d", &n);
    if (n <= 0 || n > 1000) {
        printf("So luong khong hop le!!");
        return 1;
    }
    int arr[n];
    printf("Nhap cac phan tu mang: \n");
    for (int i = 0; i < n; i++) {
        printf("Phan tu thu %d", i + 1);
        scanf("%d", &arr[i]);
    }
    printf("Mang ban dau: ");
    print(arr, n);
    mergeSort(arr, 0, n - 1);
    printf("Mang da sap xep: ");
    print(arr, n);

    return 0;
}