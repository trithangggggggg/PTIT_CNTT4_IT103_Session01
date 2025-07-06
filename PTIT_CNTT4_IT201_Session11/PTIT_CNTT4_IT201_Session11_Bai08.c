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

Node *deleteAtPosition(Node *head, int position) {
    if (head == NULL) {
        return NULL;
    }
    Node *current = head;
    int index = 0;
    if (position == 0) {
        head = head->next;
        if (head != NULL) {
            head -> prev = NULL;
        }
        free(current);
        return head;
    }
    while (current != NULL && index < position) {
        current = current -> next;
        index++;
    }
    if (current->prev != NULL) {
        current->prev -> next = current->next;
    }
    if (current->next != NULL) {
        current->next -> prev = current->prev;
    }
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

    printf("Dslk ban dau: \n");
    printfList(head);

    int position;
    printf("Enter position : ");
    scanf("%d", &position);
    head = deleteAtPosition(head, position);

    printf("Dslk sau do: \n");
    printfList(head);

    return 0;
}