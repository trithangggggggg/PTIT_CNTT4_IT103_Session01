//
// Created by ROG on 6/16/2025.
//
#include <stdio.h>

int checkDup(int numbers[], int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 1; j < size; j++) {
            if (numbers[i] == numbers[j]) {
                return 1;
            }
        }
    }
    return 0;
}

int checkDupSubArray(int numbers[], int size) {
    // tao mang phu de kiem tra phan tu trung lap
    int seeNumbers[1001];
    // xet tung phan tu
    for (int i = 0; i < size; i++) {
        // kiem tra xem phan tu duoc xet da duoc tim thay chua
        // neu da tung duoc tim thay thi tra ve gia tri la 1
        if (seeNumbers[numbers[i]] == 1) {
            // neu khong co phan tu nao trung lap thi tra ve gia tri 0
            return 1;
        }
    }
}


int main() {
    return 0;
}
