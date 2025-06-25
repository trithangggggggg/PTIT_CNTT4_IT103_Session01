//
// Created by ROG on 6/25/2025.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Student {
    int id;
    char name[100];
    int age;
};

int main() {
    struct Student student[5];
    int n = 5;
    printf("Nhap thong tin cua 5 sinh vien: \n");
    for (int i = 0; i < n; i++) {
        printf("Sinh vien thu %d: \n", i + 1);
        printf("ID: ");
        scanf("%d", &student[i].id);
        printf("Name: ");
        scanf(" %[^\n]", student[i].name);
        printf("Age: ");
        scanf("%d", &student[i].age);
    }
    int searchID;
    printf("Nhap ID can tim: ");
    scanf("%d", &searchID);
    int find = 0;
    for (int i = 0; i < n; i++) {
        if (student[i].id == searchID) {
            printf("Thong tin sinh vien: \n");
            printf("{id: %d, name: \"%s\", age: %d}\n", student[i].id, student[i].name, student[i].age);
            find = 1;
            break;
        }
    }
    if (!find) {
        printf("Sinh vien khong ton tai!\n");
    }


    return 0;
}