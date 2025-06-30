//
// Created by ROG on 6/30/2025.
//
#include<stdio.h>
#include<string.h>

int main() {
    char arr[1000];
    printf("Nhap chuoi ki tu: ");
    fgets(arr, sizeof(arr), stdin);

    size_t len = strlen(arr);
    if(len > 0 && arr[len - 1] == '\n') {
        arr[len - 1] = '\0';
        len--;
    }
    if (len == 0) {
        printf("Chuoi ko hop le!\n");
        return 0;
    }
    printf("Chuoi la: %s\n", arr);

    for (size_t i = 0; i < len - 1; i++) {
        for (size_t j = i + 1; j < len; j++) {
            if (arr[i] > arr[j]) {
                char temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
    printf("Chuoi sau khi sap xep la: %s\n", arr);



    return 0;
}