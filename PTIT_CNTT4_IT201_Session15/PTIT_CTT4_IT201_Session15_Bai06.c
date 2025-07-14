//
// Created by ROG on 7/12/2025.
//
//
// Created by ROG on 7/12/2025.
//
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

int deQueue(Queue *q) {
    if (q->rear == -1 || q->front > q->rear) {
        printf("Queue is empty\n");
        return -1;
    }
    int value = q->array[q->front];
    q->front++;
    return value;
}

int isIncreasingByOne(Queue *q) {
    for (int i = q->front; i < q->rear; i++) {
        if (q->array[i+1] - q->array[i] != 1) {
            return 0;
        }
    }
    return 1;
}


int main() {
    int n;
    printf("Enter n: ");
    scanf("%d", &n);
    Queue *myQueue = initQueue(n);

    for (int i = 0; i < n; i++) {
        int x;
        printf("Enter a number: ");
        scanf("%d", &x);
        enQueue(myQueue, x);
    }
    if (isIncreasingByOne(myQueue)) {
        printf("True");
    }else {
        printf("False");
    }


    free(myQueue->array);
    free(myQueue);

    return 0;
}