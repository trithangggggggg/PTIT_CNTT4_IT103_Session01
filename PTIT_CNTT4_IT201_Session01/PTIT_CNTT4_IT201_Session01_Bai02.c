//
// Created by ROG on 6/16/2025.
//


void printDouble(int n) {
    int i = 1;
    while (i < n) {
        // do phuc tap thoi gian cua n : o(n) ; cua i la o(n) neu i >= n
        printf("%d\n", i); // do phuc tap thoi gian:
        i *= 2; // do phuc tap cua i : O(log n) neu i < n
    }
}
