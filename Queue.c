//
// Created by ROG on 7/25/2025.
//
#include <stdio.h>
#include <stdlib.h>

// khai bao cau truc node
typedef struct Node {
    int data;
    struct Node* next;
}Node;

typedef struct Queue {
    Node* front;
    Node* rear;
} Queue;

Node *createNode(int value) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (!newNode) {
        printf("Memory allocation error!");
        exit(1);
    }
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

void initQueue(Queue* q) {
    q->front = q->rear = NULL;
}

// kiem tra hang doi co phan tu khong
int isEmptyQueue(Queue* q) {
    return q->front == NULL;
}

// them phan tu vaoo trong hang doi
void enQueue(Queue* q, int value) {
    Node *newNode = createNode(value);
    //kiem tra xem trong hang doi co phan tu chua
    if (isEmptyQueue(q)) {
        q->front = q->rear = newNode;
    }else{
        q->rear->next = newNode;
        q->rear = newNode;
    }
}

//lay phan tu ra khoi hang doi
int deQueue(Queue* q) {
    if (isEmptyQueue(q)) {
        printf("Queue is empty!\n");
        return -1;
    }
    Node *temp = q->front;
    int data = temp->data; // du lieu cua node
    q->front = temp->next;

    if (q->front == NULL) {
        q->rear = NULL;
    }
    free(temp);
    return data;
}

void printQueue(Queue* q) {
    if (isEmptyQueue(q)) {
        printf("Queue is empty!\n");
        return;
    }
    Node *temp = q->front;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
}

int sizeQueue(Queue* q) {
    if (isEmptyQueue(q)) {
        printf("Queue is empty!\n");
        return -1;
    }
    int count = 0;
    Node *temp = q->front;
    while (temp != NULL) {
        count++;
    }
    return count;
}


int main() {

    Queue *q;
    initQueue(&q);
    enQueue(&q, 10);
    enQueue(&q, 20);
    enQueue(&q, 30);
    enQueue(&q, 40);

    printQueue(&q);


    return 0;
}