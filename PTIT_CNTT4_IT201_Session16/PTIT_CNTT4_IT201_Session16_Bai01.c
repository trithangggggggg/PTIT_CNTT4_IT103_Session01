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




