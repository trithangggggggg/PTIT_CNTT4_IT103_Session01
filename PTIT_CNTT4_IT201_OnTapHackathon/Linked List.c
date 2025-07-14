#include <stdlib.h>
#include <stdio.h>
#include <string.h>
//
// Created by ROG on 7/14/2025.
//
typedef struct Student {
    char name[20];
    int id;
} Student;

typedef struct Node {
    Student student;
    struct Node *next;
} Node;

Node *createNode(char *name, int id) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Cap phat bo nho that bai!\n");
        return NULL;
    }
    newNode->next = NULL;
    strcpy(newNode->student.name, name);
    newNode->student.id = id;
    return newNode;
}

void printfList(Node *head) {
    Node *current = head;
    while (current != NULL) {
        printf("%s %d\n", current->student.name, current->student.id);
        current = current->next;
    }
}

void editStudentWithId(Node *head, int id) {
    Node *current = head;
    while (current != NULL) {
        if (current->student.id == id) {
            printf("Moi nhap ten moi cho sinh vien co id %d: ", id);
            fgets(current->student.name, 20, stdin);
            current->student.name[strlen(current->student.name)-1] = '\0';
            printf("\nCap nhat sinh vien thanh cong!!\n");
            return;
        }
        current = current->next;
    }
    printf("Khong tim thay sinh vien co id %d !!", id);
}



int main() {
    Node *head = NULL;
    Node *node1 = createNode("Hello", 1);
    Node *node2 = createNode("World", 2);
    Node *node3 = createNode("Hello", 3);

    node1->next = node2;
    node2->next = node3;
    head = node1;

    printfList(head);

    editStudentWithId(head, 2);
    printfList(head);


    return 0;
}