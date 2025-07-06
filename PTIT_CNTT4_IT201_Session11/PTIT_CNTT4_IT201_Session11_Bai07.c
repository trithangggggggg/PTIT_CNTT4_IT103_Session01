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

Node* addToPosition(Node *head, int data, int pos) {
    Node *newNode = creatNode(data);
    if (pos == 0) {
        newNode->next = head;
        if (head != NULL) {
            head->prev = newNode;
        }
        return newNode;
    }
    Node* current = head;
    int index = 0;
    while (current != NULL && index < pos - 1) {
        current = current->next;
        index++;
    }
    if (current == NULL) {
        free(newNode);
        return head;
    }
    newNode->next = current->next;
    newNode->prev = current;
    if (current->next != NULL) {
        current->next->prev = newNode;
    }
    current->next = newNode;
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


    int data, pos;
    printf("Enter data : ");
    scanf("%d", &data);
    printf("Enter pos : ");
    scanf("%d", &pos);

    head = addToPosition(head, data, pos);

    printf("Dslk sau them:\n");
    printfList(head);

    return 0;
}