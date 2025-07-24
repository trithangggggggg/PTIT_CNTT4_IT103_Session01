//
// Created by ROG on 7/24/2025.
//
#include <stdio.h>
#include <stdlib.h>
#define MAX 100

typedef struct Node {
    int data;
    struct Node* next;
}Node;

Node * adjList[MAX];

void initGraph(int n) {
    for (int i = 0; i < n; i++) {
        adjList[i] = NULL;
    }
}

Node * createNode(int data) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
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

int countAdjacentNodes(int k) {
    int count = 0;
    Node *p = adjList[k];
    while (p != NULL) {
        count++;
        p = p->next;
    }
    return count;
}
int main() {
    int n, m;
    printf("Enter the so dinh va so canh: ");
    scanf("%d %d", &n, &m);
    printf("\n");
    initGraph(n);
    printf("Enter cac canh: ");
    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        addEdge(u, v);
    }
    printf("\n");
    int k;
    printf("Enter dinh k muon kiem traa: ");
    scanf("%d", &k);
    int result = countAdjacentNodes(k);
    printf("So dinh ke voi %d la: %d", k, result );
    return 0;
}





