//
// Created by ROG on 7/14/2025.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[31];
} Customer;

typedef struct {
    Customer array[100];
    int front;
    int rear;
    int maxSize;
} Queue;

void initQueue(Queue *q) {
    q->front = 0;
    q->rear = -1;
    q->maxSize = 100;
}

int isEmpty(Queue *q) {
    if (q->rear < q->front) {
        return 1;
    }
    return 0;
}

int isFull(Queue *q) {
    if (q->rear == q->maxSize - 1) {
        return 1;
    }
    return 0;
}

void enQueue(Queue *q, char name[]) {
    if (isFull(q)) {
        printf("Hang doi da day, khong the them khach moi.\n");
        return;
    }
    q->rear++;
    strcpy(q->array[q->rear].name, name);
    printf("Da them khach: %s\n", name);
}

void deQueue(Queue *q) {
    if (isEmpty(q)) {
        printf("Hang doi rong, khong co khach de phuc vu.\n");
        return;
    }
    printf("Dang phuc vu khach: %s\n", q->array[q->front].name);
    q->front++;
}

void printQueue(Queue *q) {
    if (isEmpty(q)) {
        printf("Khong co khach dang cho.\n");
        return;
    }
    printf("Danh sach khach dang cho:\n");
    for (int i = q->front; i <= q->rear; i++) {
        printf("%d. %s\n", i - q->front + 1, q->array[i].name);
    }
}

int main() {
    Queue q;
    initQueue(&q);
    int chon;
    char ten[31];

    do {
        printf("\n=== QUAY BAN VE ===\n");
        printf("1. Them khach hang\n");
        printf("2. Phuc vu khach\n");
        printf("3. Hien thi danh sach\n");
        printf("4. Thoat\n");
        printf("Chon: ");
        scanf("%d", &chon);
        getchar();

        if (chon == 1) {
            printf("Nhap ten khach: ");
            fgets(ten, sizeof(ten), stdin);
            ten[strcspn(ten, "\n")] = '\0';
            enQueue(&q, ten);
        } else if (chon == 2) {
            deQueue(&q);
        } else if (chon == 3) {
            printQueue(&q);
        } else if (chon == 4) {
            printf("Da thoat chuong trinh.\n");
        } else {
            printf("Lua chon khong hop le.\n");
        }

    } while (chon != 4);

    return 0;
}
