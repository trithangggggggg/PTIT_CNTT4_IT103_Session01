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

void deleteNodeAtEnd(Node *head) {
    if (head == NULL) {
        printf("Danh sach khong co phan tu!");
        return;
    }
    if (head->next == NULL) {
        printf("Danh sach chi co 1 phan tu!");
        return;
    }
    Node *prev = NULL;
    Node *temp = head;
    while (temp->next != NULL) {
        prev = temp;
        temp = temp->next;
    }
    prev->next = NULL;
    free(temp);
    printf("Da xoa thanh cong phan tu o cuoi!");
}


int main() {

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
    deleteNodeAtEnd(head);
    printf("\n");
    printList(head);

    return 0;
}