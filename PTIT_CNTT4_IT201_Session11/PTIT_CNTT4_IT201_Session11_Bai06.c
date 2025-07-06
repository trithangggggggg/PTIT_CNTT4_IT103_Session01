//
// Created by ROG on 7/4/2025.
//
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
    struct Node *prev;
} Node;

Node *creatNode(int data) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

void printfList(Node *head) {
    printf("NULL <->");
    Node* current = head;
    while (current != NULL) {
        printf(" %d <-> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

Node* deleteAtFirst(Node *head) {
    if (head == NULL) {
        return NULL;
    }
    Node *current = head;
    if (head->next == NULL) {
        free(current);
        return NULL;
    }
    head = head->next;
    head->prev = NULL;
    free(current);
    return head;
}



int main() {
    Node *head = creatNode(1);
    Node *node2 = creatNode(2);
    Node *node3 = creatNode(3);
    Node *node4 = creatNode(4);
    Node *node5 = creatNode(5);

    head -> next = node2;
    node2 -> next = node3;
    node3 -> next = node4;
    node4 -> next = node5;

    node5 -> prev = node4;
    node4 -> prev = node3;
    node3 -> prev = node2;
    node2 -> prev = head;

    printf("Dslk ban dau:\n");
    printfList(head);
    printf("Dslk sau khi xoa dau: \n");


    head = deleteAtFirst(head);
    printfList(head);

    return 0;
}