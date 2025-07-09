//
// Created by ROG on 7/8/2025.
//
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct Stack{
    int *arr;
    int top;
    int cap;

} Stack;
Stack *createStack(int cap){
    Stack *stack = (Stack *)malloc(sizeof(Stack));
    stack->top = -1;
    stack->cap = cap;
    stack->arr = (int *)malloc( sizeof(int)* cap);
    return stack;
}
int isFull(Stack *stack){
    if(stack->top == stack->cap - 1){
        return 1;
    }
    return 0;
}
int push(Stack *stack, int value) {
    if(isFull(stack)) {
        return 0;
    }
    stack-> top=stack->top +1;
    stack->arr[stack->top] = value;
    return 1;
}
int isEmpty(Stack *stack) {
    if(stack->top == -1) {
        return 1;
    }
    return 0;
}

int pop(Stack *stack) {
    if(isEmpty(stack)) {
        return 0;
    }
    return stack->arr[stack->top--];
}
int main() {
    char str[100];
    printf("Moi nhap mot chuoi bat ki: ");
    fgets(str,100, stdin);
    str[strcspn(str, "\n")] = '\0';
    int leng = strlen(str);

    Stack *stack = createStack(leng);
    for(int i = 0; i < leng; i++) {
        push(stack,str[i]);
    }
    for(int i = 0; i < leng; i++) {
        if (pop(stack) != str[leng - i - 1]) {
            printf("false");
            return 1;
        }
    }
    printf("true\n");

    return 0;
}