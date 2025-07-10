//
// Created by ROG on 7/10/2025.
//
#include <stdlib.h>
#include <stdio.h>
//
// Created by ROG on 7/10/2025.
//
typedef struct Node {
    int data;
    struct Node *next;
} Node;


Node *createNode(int data) {
    Node *temp = (Node *)malloc(sizeof(Node));
    if (temp == NULL) {
        printf("Caap phat bo nho that bai");
    }
    temp->data = data;
    temp->next = NULL;
    return temp;
}

typedef struct Stack{
    Node *top;
} Stack;

Stack *createStack() {
    Stack *stack = (Stack *)malloc(sizeof(Stack));
    if (stack == NULL) {
        printf("Stack phat bo nho that bai");
        return NULL;
    }
    stack->top = NULL;
    return stack;
}

int push(Stack *stack, int data) {
    Node *newNode = createNode(data);
    newNode->next = stack->top;
    stack->top = newNode;
    return 1;
}

void printfStack(Stack *stack) {
    if (stack->top == NULL) {
        printf("Stack = { NULL }");
        return;
    }
    printf("stack : { NULL -> ");
    Node *current = stack->top;
    while (current != NULL) {
        printf("%d-> ", current->data);
        current = current->next;
    }
    printf(" NULL }\n");
}

int peek (Stack *stack) {
    if (stack->top == NULL) {
        printf("Ngan xep rong\n");
        return -1;
    }
    return stack->top->data;
}

int main() {
    Stack *stack = createStack();
    push(stack, 10);
    push(stack, 20);
    push(stack, 30);
    push(stack, 40);
    push(stack, 50);
    push(stack, 60);


    printfStack(stack);

    int top = peek(stack);
    if (top != -1) {
        printf("Gia tri tren top la: %d", top);
    }
    free(stack);

    return 0;
}