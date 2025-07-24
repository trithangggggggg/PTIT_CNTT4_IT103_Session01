//
// Created by ROG on 7/24/2025.
//
#include <stdio.h>
#include <stdlib.h>
#define MAX 100

typedef struct Node {
    int data;
    struct Node *next;
}Node;

Node *adjList[MAX];

void initGraph(int n) {
    for (int i = 0; i < n; i++) {
        adjList[i] = NULL;
    }
}

Node *createNode(int v) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = v;
    newNode->next = NULL;
    return newNode;
}
void addEdge(int u, int v) {
    Node *newNode = createNode(v);
    newNode->next = adjList[u];
    adjList[u] = newNode;

    newNode = createNode(u);
    newNode->next = adjList[v];
    adjList[v] = newNode;
}

void printGraph(int n) {
    for (int i = 0; i < n; i++) {
        printf("%d:", i);
        Node *temp = adjList[i];
        while (temp) {
            printf(" %d", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}

int main() {
    int n;
    printf("Enter number dinh:");
    scanf("%d", &n);
    printf("\n");

    initGraph(n);
    int u, v;
    printf("Nhap cac canh (dung -1 -1 ): ");
    while (1) {
        scanf("%d%d", &u, &v);
        if (u == -1 && v == -1) {
            break;
        }
        addEdge(u, v);
    }
    printf("Danh sach ke: \n");
    printGraph(n);

    return 0;
}