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

void push(Stack *s, int value) {
    if (s->top < s->maxSize - 1) {
        s->top++;
        s->arr[s->top] = value;
    }
}

int pop(Stack *s) {
    if (s->top >= 0) {
        return s->arr[s->top--];
    }
    return -1;
}

void reverseArray(int *array, int size) {
    Stack s = createStack(size);
    for (int i = 0; i < size; i++) {
        push(&s, array[i]);
    }
    for (int i = 0; i < size; i++) {
        array[i] = pop(&s);
    }
    free(s.arr);
}

void printArray(int *array, int size) {
    printf("[");
    for (int i = 0; i < size; i++) {
        printf("%d", array[i]);
        if (i != size - 1) printf(", ");
    }
    printf("]\n");
}

int main() {
    int n;
    printf("Enter the number of nodes: ");
    scanf("%d", &n);
    int *arr = (int *)malloc(n * sizeof(int));
    printf("Nhap phan tu: \n");

    for (int i = 0; i < n; i++) {
        printf("Nhap phan tu %d: ", i + 1);
        scanf("%d", &arr[i]);
    }
    printf("Mang ban dau: ");
    printArray(arr, n);
    reverseArray(arr, n);
    printf("Mang sau dao nguoc la: ");
    printArray(arr, n);

    free(arr);
    return 0;
}