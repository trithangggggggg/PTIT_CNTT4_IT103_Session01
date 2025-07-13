//
// Created by ROG on 7/12/2025.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[50];
    int age;
} Customer;

typedef struct Node {
    Customer data;
    struct Node *next;
} Node;

typedef struct {
    Node *front;
    Node *rear;
} Queue;

void initQueue(Queue *q) {
    q->front = NULL;
    q->rear = NULL;
}

int isEmptyQueue(Queue *q) {
    return q->front == NULL;
}

void enQueue(Queue *q, Customer c) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Cap phat bo nho that bai !\n");
        return;
    }
    newNode->data = c;
    newNode->next = NULL;
    if (q->rear == NULL) {
        q->front = newNode;
        q->rear = newNode;
    }else {
        q->rear->next = newNode;
        q->rear = newNode;
    }
}

Customer deQueue(Queue *q) {
    Customer temp = {"", -1};

    if (isEmptyQueue(q)) {
        return temp;
    }
    Node *delete = q->front;
    temp = delete->data;

    q->front = q->front->next;

    if (q->front == NULL) {
        q->rear = NULL;
    }

    free(delete);
    return temp;
}

int main(void) {
    Queue queueOld, queueNomal;
    initQueue(&queueOld);
    initQueue(&queueNomal);

    int n;
    printf("Nhap so luong kkhach hang: ");
    scanf("%d", &n);
    getchar();

    for (int i = 0; i < n; i++) {
        Customer c;
        printf("Nhap ten khach hhhang thu %d: ", i + 1);
        fgets(c.name, sizeof(c.name), stdin);
        c.name[strcspn(c.name, "\n")] = 0;
        printf("Nhap tuoi: ");
        scanf("%d", &c.age);
        getchar();
        if (c.age >= 60) {
            enQueue(&queueOld, c);
        }else {
            enQueue(&queueNomal, c);
        }
    }

    printf("Danh sach thu tu phuc vu: \n");
    while (!isEmptyQueue(&queueOld) || !isEmptyQueue(&queueNomal)) {
        Customer next;
        if (!isEmptyQueue(&queueOld)) {
            next = deQueue(&queueOld);
            printf("Phuc vu uu tien: %s (%d tuoi)\n", next.name, next.age);
        }
        else {
            next = deQueue(&queueNomal);
            printf("Phuc vu thuong: %s (%d tuoi)\n", next.name, next.age);
        }
    }

    return 0;
}