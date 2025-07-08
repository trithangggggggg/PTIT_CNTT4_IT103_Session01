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

void printStack(Stack s) {
    printf("stack={\n");
    printf("    elements: [");
    for (int i = 0; i <= s.top; i++) {
        printf("%d", s.arr[i]);
        if (i < s.top) printf(", ");
    }
    printf("],\n");
    printf("    top: %d,\n", s.top);
    printf("    cap: %d\n", s.maxSize);
    printf("}\n");
}

void viewStack(Stack s) {
    if (s.top == -1) {
        printf("Rong\n");
        return;
    }
    for (int i = s.top; i >= 0; i--) {
        printf("%d\n", s.arr[i]);
    }
}

int main() {
    Stack myStack = createStack(5);
    printf("Nhap cac phan tu: \n");
    for (int i = 0; i < 5; i++) {
        int value;
        printf("phan tu thu %d: ", i + 1);
        scanf("%d", &value);
        pushToStack(&myStack, value);
    }
    printStack(myStack);

    printf("\n");
    printf("Cac phan tu: \n");
    viewStack(myStack);

    free(myStack.arr);
    return 0;
}