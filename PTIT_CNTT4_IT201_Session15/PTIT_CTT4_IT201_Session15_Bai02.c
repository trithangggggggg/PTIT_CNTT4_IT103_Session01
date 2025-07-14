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
    if (q == NULL) {
        printf("Cap phat bo nho that bai!");
        return NULL;
    }
    q->maxSize = maxSize;
    q->front = 0;
    q->rear = -1;
    q->array = (int *)malloc(maxSize * sizeof(int));
    if (q->array == NULL) {
        printf("Cap phat bo nho that bai!");
        return NULL;
    }
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


int main() {
    int n = 5;
    Queue *myQueue = initQueue(n);

    enQueue(myQueue, 10);
    enQueue(myQueue, 20);
    enQueue(myQueue, 30);
    enQueue(myQueue, 40);
    enQueue(myQueue, 50);


    enQueue(myQueue, 60);

    printf("Queue sau khi them: \n");
    for(int i = 0; i <= myQueue->rear; i++) {
        printf("%d ",myQueue->array[i]);
    }

    free(myQueue->array);
    free(myQueue);

    return 0;
}