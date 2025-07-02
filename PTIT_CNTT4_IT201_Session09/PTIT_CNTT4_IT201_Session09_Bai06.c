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
//ham in toan bo danh sach lien ket
void printList(Node *head) {
    // Node *current = head;
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}
//ham xoa phan tu o dau
Node *deleteNode(Node *head) {
    if (head == NULL) {
        printf("Danh sach khong co phan tu\n");
        return NULL;
    }
    Node *temp = head;
    head = head->next;
    free(temp);
    return head;
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

    printf("Danh sach ban dau: ");
    printList(head);

    head = deleteNode(head);
    printf("Danh sach sau khi xoa phan tu o dau: ");
    printList(head);

    return 0;
}
