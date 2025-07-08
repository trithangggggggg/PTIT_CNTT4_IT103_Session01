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

int main() {
    Stack myStack = createStack(5);
    printf("Ngan xep toi da %d phan tu", myStack.maxSize);
    free(myStack.arr);

    return 0;
}