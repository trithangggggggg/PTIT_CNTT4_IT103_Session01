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

int isEmpty(Queue *q) {
    if (q->rear == -1) {
        return 1;
    }else {
        return 0;
    }
}

int main() {
    int n = 5;
    Queue *myQueue = initQueue(n);
    if(myQueue != NULL) {
        printf("Queue duoc khoi tao voi suc chua %d phan tu\n",myQueue->maxSize );
        printf("Gia tri font = %d, rear = %d\n",myQueue->front, myQueue->rear);
    }
    if (isEmpty(myQueue)) {
        printf("Ham doi rong (TRUE)\n");
    }else {
        printf("Ham doi co phan tu (FALSE)\n");
    }

    free(myQueue->array);
    free(myQueue);

    return 0;
}