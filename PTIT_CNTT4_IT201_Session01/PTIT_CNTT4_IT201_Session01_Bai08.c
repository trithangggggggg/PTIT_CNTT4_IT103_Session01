//
// Created by ROG on 6/16/2025.
//
#include <stdio.h>

int main() {
    int data[] = {1, 3, 4, 5, 6, 7, 8, 2, 3, 6, 3 ,6};
    int len = sizeof(data) / sizeof(data[0]);

    int max = 0;
    int  val;
    for (int i = 0; i< len; i++) { // do phuc tap: O(n^2)
        int cnt = 1;
        for (int j = i + 1; j < len; j++) {
            if (data[i] == data[j]) {
                cnt++;    // do phuc tap O(1)
            }
        }
        if (cnt > max) {
            max = cnt;
            val = data[i];
        }
    }
    printf("gia tri xuat hien nhieu nhat la: %d (%d lan)", val, max);
    return 0;
}