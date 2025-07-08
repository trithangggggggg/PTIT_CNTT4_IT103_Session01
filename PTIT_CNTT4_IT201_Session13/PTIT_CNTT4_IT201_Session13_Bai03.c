//
// Created by ROG on 7/8/2025.
//
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *arr;
    int top;
    int maxSize;
} Stack;

Stack createStack(int maxSize) {
    Stack s;
    s.arr = (int *)malloc(maxSize * sizeof(int));
    s.top = -1;
    s.maxSize = maxSize;
    return s;
}

void pushToStack(Stack *s, int value) {
    if (s->top >= s->maxSize - 1) {
        printf("Khong the them");
        return;
    }
    s->arr[++(s->top)] = value;
}

int popFromStack(Stack *s) {
    if (s->top == -1) {
        printf("No element in stack");
        return -1;
    }
    return s->arr[(s->top)--];
}

void printStack(Stack s) {
    printf("stack={\n");
    printf("  elements: [");
    for (int i = 0; i <= s.top; i++) {
        printf("%d", s.arr[i]);
        if (i < s.top){
            printf(", ");
        }
    }
    printf("],\n");
    printf("  top: %d,\n", s.top);
    printf("  cap: %d\n", s.maxSize);
    printf("}\n");
}

int main() {
    Stack myStack = createStack(5);

    printf("Hay nhap cac phan tu:\n");
    for (int i = 0; i < 5; i++) {
        int value;
        printf("Phan tu thu %d: ", i + 1);
        scanf("%d", &value);
        pushToStack(&myStack, value);
    }
    printStack(myStack);
    printf("\nPop cac phan tu:\n");
    for (int i = 0; i < 5; i++) {
        int val = popFromStack(&myStack);
        if (val != -1)
            printf("Lay ra: %d\n", val);
    }
    printStack(myStack);
    printf("\nThu pop khi stack rong:\n");
    popFromStack(&myStack);

    free(myStack.arr);
    return 0;
}