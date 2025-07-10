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
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Stack phat bo nho that bai");
        return 0;
    }
    newNode->data = data;
    newNode->next = stack->top;
    stack->top = newNode;
    return 1;
}

int pop(Stack *stack) {
    if (stack->top == NULL) {
        printf("Stack rong!");
        return -1;
    }
    Node *current = stack->top;
    int value = current->data;
    stack->top = current->next;
    free(current);
    return value;
}

void printfStack(Stack *stack) {
    if (stack->top == NULL) {
        printf("Stack rong!");
        return;
    }
    printf("Stack : { ");
    Node *current = stack->top;
    while (current != NULL) {
        printf("%d-> ", current->data);
        current = current->next;
    }
    printf(" NULL }\n");
}

void traverseStack(Stack *stack) {
    if (stack->top == NULL) {
        printf("Stack rong!");
        return;
    }
    while (stack->top != NULL) {
        int value = pop(stack);
        printf("%d \n", value);
    }
}


int main() {
    Stack *stack = createStack();
    push(stack, 10);
    push(stack, 20);
    push(stack, 30);

    printfStack(stack);

    traverseStack(stack);

    free(stack);


    return 0;
}