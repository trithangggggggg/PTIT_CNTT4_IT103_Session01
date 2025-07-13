//
// Created by ROG on 7/12/2025.
//
//
// Created by ROG on 7/12/2025.
//
//
// Created by ROG on 7/12/2025.
//
#include<stdio.h>
#include<stdlib.h>


typedef struct Queue {
    int *array;
    int maxSize;
    int front;
    int rear;
} Queue;

Queue* initQueue(int maxSize) {
    Queue* q = (Queue *)malloc(sizeof(Queue));
    q->maxSize = maxSize;
    q->front = 0;
    q->rear = -1;
    q->array = (int *)malloc(maxSize * sizeof(int));
    return q;
}

void enQueue(Queue* q, int value) {
    if (q->rear == q->maxSize - 1) {
        printf("Queue is full\n");
        return;
    }
    q->rear++;
    q->array[q->rear] = value;
}

int isEmpty(Queue *q) {
    if (q->rear == -1) {
        return 1;
    }else {
        return 0;
    }
}

void printQueue(Queue *q) {
    if (q->rear == -1) {
        printf("Queue is empty\n");
        return;
    }
    for (int i = q->front; i <= q->rear; i++) {
        printf("%d ", q->array[i]);
    }
}


int main() {
    int n = 5;
    Queue *myQueue = initQueue(n);

    enQueue(myQueue, 1);
    enQueue(myQueue, 2);
    enQueue(myQueue, 3);
    enQueue(myQueue, 4);

    printf("Hang doi: ");
    printQueue(myQueue);

    free(myQueue->array);
    free(myQueue);

    return 0;
}