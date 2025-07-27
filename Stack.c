//
// Created by ROG on 7/25/2025.
//
#include <stdio.h>
#define MAX 100

typedef struct Stack {
    int item[MAX];
    int top;
}Stack;

//ham khoi tao stack
void initStack(Stack *s) {
    s->top = -1;
}

//ham kiem tra xem stack co rong hay khong
int isEmtyStack(Stack *s) {
    return s->top == -1;
}
//ham kiem tra xem stack da day chua
int isFullStack(Stack *s) {
    return s->top == MAX - 1;
}
//==========================
//ham them phan tu vao Stack
void push(Stack *s, int value) {
    //kiem tra xem da full chua
    if (isFullStack(s)) {
        printf("Ngan xep da day!!\n");
        return;
    }
    //Them phan tu vao ngan xep
    s->item[++(s->top)] = value;
    printf("Them phan tu vao ngan xep thanh cong!\n");
}

int pop(Stack *s) {
    //kiem tra xem ngan xep co phan tu khong
    if (isEmtyStack(s)) {
        printf("Ngan xep rong!!\n");
        return -1;
    }
    //tra ve phan tu nam tren dinh va xoa di
    return s->item[s->top --];
}

// ham lay phan tu tren cung cua stack ra xem
int peek(Stack *s) {
    if (isEmtyStack(s)) {
        printf("Ngan xep rong!!\n");
        return -1;
    }
    return s->item[s->top];
}

//ham in ra cac phan tu co trong ngan xep
void printStack(Stack *s) {
    if (isEmtyStack(s)) {
        printf("Ngan xep rong!!\n");
        return;
    }
    printf("Ngan xep: \n");
    for (int i = s->top; i >= 0; i--) {
        printf("%d ", s->item[i]);
    }
}


int main(void) {
    Stack *s;
    initStack(&s);
    push(&s, 10);
    push(&s, 20);
    push(&s, 30);
    push(&s, 40);


    printf("1. %d \n", pop(&s));//40
    printf("2. %d \n", peek(&s));//30
    printf("3. %d \n", peek(&s));//30

    printStack(&s);


    return 0;
}


