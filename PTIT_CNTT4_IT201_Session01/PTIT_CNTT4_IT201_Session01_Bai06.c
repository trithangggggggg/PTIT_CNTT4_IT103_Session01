//
// Created by ROG on 6/16/2025.
//
#include <stdio.h>

int main() {
    int arr[] = {1, 3, 5, 7, 9, 8,4 ,6 ,4 3, 6, 3, 6, 2};
    int arrLength = sizeof(arr)/ sizeof(arr[0]);

    int x;
    printf("Nhap so can kiem tra trung lap: ");
    scanf("%d", &x);

    int sum = 0;

    for (int i = 0; i < arrLength; i++) { // phuc tap thoi gian O(n), khhong gian la  O(1)
        if (arr[i] == x) {
            sum += arr[i];
        }
    }
    printf("So %d xuan hien %d lan ",x, sum);

    return 0;
}