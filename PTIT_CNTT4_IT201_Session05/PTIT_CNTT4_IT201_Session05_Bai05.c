//
// Created by ROG on 6/26/2025.
//
#include <stdio.h>
#include<string.h>

int check(char str[], int left, int right) {
    if(left >= right) {
        return 1;
    }if (str[left] != str[right]) {
        return 0;
    }
    return check(str, left + 1, right - 1);
}

int main() {
    char str[100];

    printf("Nhap chuoi: ");
    gets(str);

    int length = strlen(str);
    if(check(str, 0, length - 1)) {
        printf("La chuoi doi xung\n");
    }else {
        printf("Khong la chuoi doi xung\n");
    }


    return 0;
}