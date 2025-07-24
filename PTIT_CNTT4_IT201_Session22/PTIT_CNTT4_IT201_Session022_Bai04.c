//
// Created by ROG on 7/24/2025.
//
#include <stdio.h>
#define MAX 100


int main() {
    int n;
    int a[MAX][MAX];
    int count = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &a[i][j]);
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (a[i][j] == 1) {
                count++;
            }
        }
    }
    printf("%d\n", count);

    return 0;
}