#include <stdio.h>
#include <stdlib.h>
//
// Created by ROG on 7/16/2025.
//
typedef struct Call {
    char *phone;
    int time;
}Call;
typedef struct Stack {
    Call *calls;
    int capacity;
    int top;
}Stack;
typedef struct Queue {
    Call *calls;
    int capacity;
    int front;
    int rear;
} Queue;

Stack *createStack(int capacity) {
    Stack *stack = (Stack *)malloc(sizeof(Stack));
    stack->top = -1;
    stack->capacity = capacity;
    stack->calls = (Call *)malloc(sizeof(Call) * stack->capacity);
    return stack;
}

Queue *createQueue(int capacity) {
    Queue *queue = (Queue *)malloc(sizeof(Queue));
    queue->front = 0;
    queue->rear = -1;
    queue->capacity = capacity;
    queue->calls = (Call *)malloc(sizeof(Call) * queue->capacity);
    return queue;
}
// Xay dung ham kiem tra gioi han cua cau truc
int isStackFull(Stack *stack) {
    if (stack->top == stack->capacity - 1) {
        return 1;
    }
}
int isQueueFull(Queue *queue) {
    if (queue->rear == queue->capacity - 1) {
        return 1;
    }
}

// Xay dung phuong thuc them vao stack
void push(Stack *stack, Call call) {
    // kiem tra gioi han hang doi

    // Cap nhat chi so top
    // Dua cuoc goi vao ngan xep
}
// them vao queue
void enqueue(Queue *queue, Call call) {
    // kiem tra gioi han queue
    // cap nhat chi so rear
    // Dua cuoc goi vao hang doi
}




int main() {
    // Xay dung menu
    int choice;
    do {
        printf("1. Call\n");
        printf("2. Back\n");
        printf("3. Redial\n");
        printf("4. History\n");
        printf("5. Exit\n");
        printf("   Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                break;
            case 2:
                break;
            case 3:
                break;
            case 4:
                break;
            case 5:
                break;
            default:
        }
    } while (choice != 5);

    return 0;
}