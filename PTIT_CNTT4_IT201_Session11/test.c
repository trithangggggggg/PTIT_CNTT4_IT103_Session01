#include <stdio.h>
#include <stdlib.h>

// Cấu trúc dữ liệu
typedef struct Node {
    int data;
    struct Node *next;
    struct Node *prev;
} Node;

// Hàm tạo node
Node *createNode(int data) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

// Hàm hiển thị danh sách
void display(Node *head) {
    Node *current = head;
    while (current != NULL) {
        printf("%d", current->data);
        if (current->next != NULL) {
            printf(" <-> ");
        }
        current = current->next;
    }
    printf("\n");
}

int main() {
    // Khởi tạo node
    Node *head = createNode(1);
    Node *node2 = createNode(2);
    Node *node3 = createNode(3);
    Node *node4 = createNode(4);
    Node *node5 = createNode(5);

    // Liên kết next
    head->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node5;

    // Liên kết prev
    node2->prev = head;
    node3->prev = node2;
    node4->prev = node3;
    node5->prev = node4;

    // Hiển thị
    display(head);

    return 0;
}
