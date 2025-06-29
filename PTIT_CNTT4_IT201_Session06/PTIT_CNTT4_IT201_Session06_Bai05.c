//
// Created by ROG on 6/29/2025.
//
#include<stdio.h>

int min(int arr[], int n) {
    if (n == 1) {
        return arr[0];
    }
    int mini = min(arr, n-1);
    if (arr[n-1] < mini) {
        return arr[n-1];
    }else {
        return mini;
    }
}
int max(int arr[], int n) {
    if (n == 1) {
        return arr[0];
    }
    int maxi = max(arr, n-1);
    if (arr[n-1] > maxi) {
        return arr[n-1];
    }else {
        return maxi;
    }
}

int main () {
    int n ;
    printf("Nhap so n: ");
    scanf("%d", &n);
    if (n <= 0) {
        printf("So luong phan tu khong hop le");
        return 1;
    }
    int arr[100];
    for (int i = 0; i < n; i++) {
        printf("Phan tu thu %d: ", i+1);
        scanf("%d", &arr[i]);
    }
    int mini = min(arr, n);
    int maxi = max(arr, n);
    printf("Phan tu nho nhat: %d\n", mini);
    printf("Phan tu lon nhat: %d\n", maxi);

    return 0;
}