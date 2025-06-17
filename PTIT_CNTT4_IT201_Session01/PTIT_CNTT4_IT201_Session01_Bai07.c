//
// Created by ROG on 6/16/2025.
//
#include <stdio.h>

int loop(int arr[], int len) {   // do phuc tap: O(n^2)
    for (int i = 0; i < len - 1; i++) {
        for (int j = i + 1; j < len; j++) {
            if (arr[i] == arr[j]) return 1;
        }
        return 0;
    }
}

int count(int arr[], int len) {     // do phuc tap: O(n)
    int freq[1001] = {0};
    for (int i = 0; i < len; i++) {
        if (freq[arr[i]]) return 1;
        freq[arr[i]] = 1;
    }
    return 0;
}

int main() {
    int data[] = {1, 3, 4, 5, 7, 2, 6};
    int size = sizeof(data)/ sizeof(data[0]);

    if (loop(data, size)) {
        printf("loop: duplicated");

    }else {
        printf("loop: unique");
    }

    if (count(data,size)) {
        printf("count: duplicated");
    }else {
        printf("count: unique");
    }
    return 0;
}