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

void deleteNodes(Node *head, int valueDeleted) {
    if (head == NULL) {return;}
    Node *current = head->next;
    Node *prev = head;
    while (current != NULL) {
        if (current->data == valueDeleted) {
            prev->next = current->next;
            free(current);
            printf("Da xoa thanh cong phan tu %d!\n", valueDeleted);
            current = prev->next;
        }else {
            prev = current;
            current = current->next;
        }
    }
}



int main() {
    int valueDeleted;

    Node *node1 = creatNode(1);
    Node *node2 = creatNode(4);
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
    printf("Nhap gia tri muon xoa: ");
    scanf("%d", &valueDeleted);

    deleteNodes(head, valueDeleted);
    printList(head);

    return 0;
}