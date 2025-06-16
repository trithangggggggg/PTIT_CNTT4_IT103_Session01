//
// Created by ROG on 6/16/2025.
//
#include <stdio.h>

int main() {
    int arr[] = {1, 7, 9,32, 3, 73 };
    int n = sizeof(arr) / sizeof(arr[0]);

    for (int i = 0; i < n - 1; i++) {  // do phuc tap thoi gian O(n^2), do phuc tap khongg gian O(1)
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        printf("%d", arr[i]);
    }

    return 0;
}