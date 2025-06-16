//
// Created by ROG on 6/16/2025.
//
#include <stdio.h>

int* mallocArray(int n) {
    int * arr = (int*) malloc(n* sizeof(int)); // độ phức tạp không gian của n: O(n)
    for (int i = 0; i < n; i++) {
        arr[i] = i;
    }
    return arr;
}