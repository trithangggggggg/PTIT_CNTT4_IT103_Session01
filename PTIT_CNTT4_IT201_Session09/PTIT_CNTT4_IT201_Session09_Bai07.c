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
//ham dem phan tu
int countList(Node *head) {
    int count = 0;
    Node *temp = head;
    while (temp != NULL) {
        count++;
        temp = temp->next;
    }
    return count;
}
//ham them vi tri bat ki
Node *addPosition(Node *head, int data, int pos) {
    Node *nodeNew = createNode(data);
    if (pos <= 1) {
        nodeNew->data = head;
        head = nodeNew;
        return head;
    }
    Node *temp = head;
    int count = 1;
    while (temp != NULL && count <= pos - 1) {
        temp = temp->next;
        count++;
    }
    if (temp == NULL) {
        printf("Vi tri vuot do dai danh sach");
        temp = head;
        if (temp == NULL) {
            head = nodeNew;
        }else {
            while (temp->next != NULL) {
                temp = temp->next;
            }
        }
        return head;
    }
    //chen
    nodeNew->next = temp->next;
    temp->next = nodeNew;

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

    int data, pos;
    printf("\nNhap gia tri can chen: ");
    scanf("%d", &data);
    printf("\nNhap vi tri can chen: ");
    scanf("%d", &pos);

    head = addPosition(head, data, pos);

    printf("\nDanh sach sau khi chen :");
    printList(head);

    return 0;
}
