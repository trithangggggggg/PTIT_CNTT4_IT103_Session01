//
// Created by ROG on 7/2/2025.
//
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

//ham tao phan tu
Node* createNode(int data) {
    Node *node = (Node*)malloc(sizeof(Node));
    node->data = data;
    node->next = NULL;
    return node;
}

//ham them phan tu vao dau mang
Node *addValue(Node *head, int data) {
    Node *node1 = createNode(data);
    node1->next = head;
    head = node1;
    return head;
}

//ham in toan bo danh sach lien ket
void printList(Node *head) {
    // Node *current = head;
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}


int main() {
    Node *head = NULL;
    Node *node1 = createNode(1);
    Node *node2 = createNode(2);
    Node *node3 = createNode(3);
    Node *node4 = createNode(4);
    Node *node5 = createNode(5);

    head = node1;
    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node5;

    int n;
    printf("Nhap so can them vao dau danh sach: ");
    scanf("%d", &n);

    head = addValue(head, n);
    printf("Danh sach sau khi them: ");
    printList(head);

    return 0;
}
