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

void pushToStack(Stack *s, int item) {
    if (s->top >= s->maxSize - 1) {
        printf("Stack is full\n");
        return;
    }
    s->arr[++s->top] = item;
}

void printStack(Stack *s) {
    printf("stack = [\n");
    printf("element: [");
    for (int i = 0; i < s->top; i++) {
        printf("%d", s->arr[i]);
        if (i < s->top) {
            printf(", ");
        }
    }
    printf("]\n");
    printf("    top: %d,\n", s->top);
    printf("    cap: %d,\n", s->maxSize);
    printf("}\n");
}




int main() {
    Stack myStack = createStack(5);
    printf("Moi nhap 5 phan tu: ");
    for (int i = 0; i < 5; i++) {
        int item;
        printf("Nhap phan tu thu %d: ", i + 1);
        scanf("%d", &item);
        pushToStack(&myStack, item);
    }
    printStack(&myStack);
    free(myStack.arr);



    return 0;
}