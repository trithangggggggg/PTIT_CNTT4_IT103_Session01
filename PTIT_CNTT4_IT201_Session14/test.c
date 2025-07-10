//
// Created by ROG on 7/8/2025.
//
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char *arr;
    int top;
    int cap;
} Stack;

Stack *createStack(int cap) {
    Stack *stack = (Stack *)malloc(sizeof(Stack));
    if (stack == NULL) {
        printf("Cap phat bo nho cho Stack that bai\n");
        exit(1);
    }
    stack->arr = (char *)malloc(sizeof(char) * cap);
    if (stack->arr == NULL) {
        printf("Cap phat bo nho cho mang Stack that bai\n");
        free(stack);
        exit(1);
    }
    stack->top = -1;
    stack->cap = cap;
    return stack;
}

int fullStack(Stack *stack) {
    return stack->top == stack->cap - 1;
}

int emptyStack(Stack *stack) {
    return stack->top == -1;
}

int push(Stack *stack, char value) {
    if (fullStack(stack)) {
        printf("Stack day\n");
        return 0;
    }
    stack->arr[++(stack->top)] = value;
    return 1;
}

char pop(Stack *stack) {
    if (emptyStack(stack)) {
        printf("Stack rong\n");
        return '\0';
    }
    return stack->arr[(stack->top)--];
}

void printStack(Stack *stack) {
    if (emptyStack(stack)) {
        printf("Stack rong\n");
        return;
    }
    printf("Stack hien tai: ");
    for (int i = 0; i <= stack->top; i++) {
        printf("%c ", stack->arr[i]);
    }
    printf("\n");
}

int main() {
    Stack *stack = createStack(10);

    push(stack, 'A');
    push(stack, 'B');
    push(stack, 'C');
    printStack(stack);

    printf("Pop: %c\n", pop(stack)); // Pop: C
    printStack(stack);

    free(stack->arr);
    free(stack);
    return 0;
}
