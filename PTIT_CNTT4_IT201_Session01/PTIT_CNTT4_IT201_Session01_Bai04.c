//
// Created by ROG on 6/16/2025.
//
#include <stdio.h>

int main() {
    // cach 1
    int n; // do phuc tap khong gian la O(1)
    printf("Moi ban nhap n");
    scanf("%d", &n);

    int sum = 0;
    for (int i = 1; i <= n; i++) {
        // do phuc tap khong gian O(n)
        sum += i;
    }
    printf("%d", sum);

    //cach 2
    int sum2 = n * (n + 1) / 2; // do phuc tap khong gian O(1)
    printf("%d", sum2);
    return 0;
}
