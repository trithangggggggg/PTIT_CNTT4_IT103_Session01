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
Node *createNode(int data) {
    Node *node = (Node *)malloc(sizeof(Node));
    node->data = data;
    node->next = NULL;
    return node;
}
void addEdge(int u, int v) {
    Node *newNode = createNode(v);
    newNode->next = adjList[u];
    adjList[u] = newNode;
}

void printGraph(int V) {
    for (int i = 0; i < V; i++) {
        printf("%d ", i);
        Node *temp = adjList[i];
        while (temp != NULL) {
            printf("%d ->", temp->data);
            temp = temp->next;
        }
        printf( " NULL\n");
    }
}

int main() {
    int n;
    int a[MAX][MAX];
    initGraph(n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &a[i][j]);
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (a[i][j] == 1) {
                addEdge(i, j);
            }
        }
    }
    printGraph(n);


    return 0;
}