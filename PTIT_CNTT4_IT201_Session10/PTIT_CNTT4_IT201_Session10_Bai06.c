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

void findMiddle(Node *head) {
    if (head == NULL || head->next == NULL) {return;}
    int length = 0;
    Node *temp = head;
    while (temp != NULL) {
        length++;
        temp = temp->next;
    }
    int middle = length / 2;
    temp = head;
    for (int i = 0; i < middle; i++) {
        temp = temp->next;
    }
    printf("Phan tu o giua danh sach: %d\n", temp->data);
}



int main() {

    Node *node1 = creatNode(1);
    Node *node2 = creatNode(2);
    Node *node3 = creatNode(3);
    Node *node4 = creatNode(4);
    Node *node5 = creatNode(5);
    Node *node6 = creatNode(6);

    Node *head = node1;
    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node5;
    node5->next = node6;
    node6->next = NULL;


    printList(head);
    findMiddle(head);

    return 0;
}