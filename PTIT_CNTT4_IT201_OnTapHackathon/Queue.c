//
// Created by ROG on 7/14/2025.
//
// ====== Ham doi Queue ======
#include <stdio.h>
#include <stdlib.h>

// Khai báo struct Queue
typedef struct Queue {
    int *array;     // Mảng lưu phần tử
    int maxSize;    // Số phần tử tối đa
    int front;      // Vị trí đầu hàng đợi
    int rear;       // Vị trí cuối hàng đợi
} Queue;

// Hàm khởi tạo hàng đợi
Queue* initQueue(int maxSize) {
    Queue* q = (Queue *)malloc(sizeof(Queue));
    if (q == NULL) {
        printf("Khong cap phat duoc bo nho cho queue\n");
        return NULL;
    }
    q->array = (int *)malloc(maxSize * sizeof(int));
    if (q->array == NULL) {
        printf("Khong cap phat duoc bo nho cho mang\n");
        free(q);
        return NULL;
    }
    q->maxSize = maxSize;
    q->front = 0;
    q->rear = -1;
    return q;
}

// Hàm kiểm tra hàng đợi rỗng
int isEmpty(Queue* q) {
    return (q->rear == -1 || q->front > q->rear);
}

// Hàm kiểm tra hàng đợi đầy
int isFull(Queue* q) {
    return (q->rear == q->maxSize - 1);
}

// Hàm thêm phần tử vào queue
void enQueue(Queue* q, int value) {
    if (isFull(q)) {
        printf("Hang doi day\n");
        return;
    }
    q->rear++;
    q->array[q->rear] = value;
}

// Hàm lấy phần tử ra khỏi queue
int deQueue(Queue* q) {
    if (isEmpty(q)) {
        printf("Hang doi rong\n");
        return -1;
    }
    int value = q->array[q->front];
    q->front++;

    // Reset lại nếu không còn phần tử nào
    if (q->front > q->rear) {
        q->front = 0;
        q->rear = -1;
    }

    return value;
}

// Hàm xem phần tử đầu tiên (không lấy ra)
int peek(Queue* q) {
    if (isEmpty(q)) {
        printf("Hang doi rong\n");
        return -1;
    }
    return q->array[q->front];
}

// Hàm in toàn bộ queue
void printQueue(Queue* q) {
    if (isEmpty(q)) {
        printf("Hang doi rong\n");
        return;
    }
    printf("Queue: ");
    for (int i = q->front; i <= q->rear; i++) {
        printf("%d ", q->array[i]);
    }
    printf("\n");
}

// Hàm giải phóng bộ nhớ
void freeQueue(Queue* q) {
    if (q != NULL) {
        free(q->array);
        free(q);
    }
}
int main() {
    Queue* q = initQueue(5);

    enQueue(q, 10);
    enQueue(q, 20);
    enQueue(q, 30);
    printQueue(q);  // In: 10 20 30

    printf("Phan tu dau hang doi (peek): %d\n", peek(q)); // 10

    printf("Lay ra: %d\n", deQueue(q));  // Lấy 10
    printQueue(q);                       // In: 20 30

    printf("Lay ra: %d\n", deQueue(q));  // Lấy 20
    printf("Lay ra: %d\n", deQueue(q));  // Lấy 30
    printf("Lay ra: %d\n", deQueue(q));  // Queue rong

    enQueue(q, 99);
    printQueue(q);  // In: 99

    freeQueue(q);
    return 0;
}


