//
// Created by ROG on 7/14/2025.
//
//
// Created by ROG on 7/14/2025.
//
//
// Created by ROG on 7/14/2025.
//
//
// Created by ROG on 7/14/2025.
//
//
// Created by ROG on 7/14/2025.
//
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

typedef struct Queue{
    Node *front;
    Node *rear;
} Queue;

Queue *initQueue() {
    Queue *q = (Queue*)malloc(sizeof(Queue));
    if (q == NULL) {
        printf("Cap phat bo nho that bai! ");
        return NULL;
    }
    q->front = NULL;
    q->rear = NULL;
    return q;
}

Node *creatNode(int data){
    Node *newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Cap phat bo nho that bai! ");
        return NULL;
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void enqueue(Queue *q, int data) {
    Node *newNode = creatNode(data);
    if (newNode == NULL) {
        return;
    }
    if (q->rear == NULL) {
        q->front = newNode;
        q->rear = newNode;
    }else {
        q->rear->next = newNode;
        q->rear = newNode;
    }
}

int getFront(Queue *q) {
    if (q->front == NULL) {
        printf("ham doi rong!\n");
        return -1;
    }
    return q->front->data;
}

void dequeue(Queue *q) {
    if (q->front == NULL) {
        printf("ham doi rong!\n");
        return;
    }
    Node *temp = q->front;
    printf("Da xoa phan tu: %d \n", temp->data);
    q->front = q->front->next;
    if (q->front == NULL) {
        q->rear = NULL;
    }
    free(temp);
}

void printQueue(Queue *q) {
    Node *current = q->front;
    printf("cac phan tu trong hang doi queue: ");
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main() {

    Queue *q = initQueue();

    int n, data;
    printf("Moi nhap so phan tu trong hang doi: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        printf("Nhap phan tu thu %d: ", i + 1);
        scanf("%d", &data);
        enqueue(q, data);
    }


    printQueue(q);
    int value = getFront(q);
    if (value != -1) {
        printf("Phan tu dau hang doi la: %d\n", value);
    }

    dequeue(q);
    printQueue(q);


    return 0;
}




