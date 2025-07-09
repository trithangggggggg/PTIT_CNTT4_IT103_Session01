//
// Created by ROG on 7/8/2025.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *arr;
    int top;
    int cap;
} Stack;

Stack *createStack(int cap) {
    Stack *stack = (Stack *)malloc(sizeof(Stack));
    stack->arr = (char *)malloc(sizeof(char) * cap);
    stack->top = -1;
    stack->cap = cap;
    return stack;
}

int push(Stack *stack, char mark) {
    if (stack->top >= stack->cap - 1) return 0;
    stack->arr[++(stack->top)] = mark;
    return 1;
}

char pop(Stack *stack) {
    if (stack->top == -1) return '\0';
    return stack->arr[(stack->top)--];
}

int isMatching(char open, char close) {
    return (open == '(' && close == ')') ||
           (open == '[' && close == ']') ||
           (open == '{' && close == '}');
}

int check(char *expr) {
    int len = strlen(expr);
    Stack *stack = createStack(len);
    for (int i = 0; i < len; i++) {
        char hard = expr[i];
        if (hard == '(' || hard == '[' || hard == '{') {
            push(stack, hard);
        } else if (hard == ')' || hard == ']' || hard == '}') {
            char top = pop(stack);
            if (!isMatching(top, hard)) {
                free(stack->arr);
                free(stack);
                return 0;
            }
        }
    }
    int result = (stack->top == -1);
    free(stack->arr);
    free(stack);
    return result;
}

int main() {
    char expr[1000];
    printf("MOI nhap bieu thuc: ");
    fgets(expr, sizeof(expr), stdin);
    expr[strcspn(expr, "\n")] = '\0';
    if (check(expr)) {
        printf("true");
    } else {
        printf("false");
    }


    return 0;
}