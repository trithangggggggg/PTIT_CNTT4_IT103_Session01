#include <stdlib.h>
#include <stdio.h>
//
// Created by ROG on 7/3/2025.
//
typedef struct Node {
    int data;
    struct Node *next;
} Node;

Node *creatNode(int data) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void printList(Node *head) {
    Node *temp = head;
    printf("Danh sach lien ket: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void addToEnd(Node *head, int value) {
    Node *newNode = creatNode(value);
    Node *temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}


int main() {
    int value;

    Node *node1 = creatNode(1);
    Node *node2 = creatNode(2);
    Node *node3 = creatNode(3);
    Node *node4 = creatNode(4);
    Node *node5 = creatNode(5);

    Node *head = node1;
    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node5;
    node5->next = NULL;


    printList(head);
    printf("\n");

    printf("Nhap gia tri muon them vao cuoi danh sach: ");
    scanf("%d", &value);

    addToEnd(head, value);
    printf("Da them 1 gia tri vao cuoi danh sach! \n");
    printList(head);

    return 0;
}