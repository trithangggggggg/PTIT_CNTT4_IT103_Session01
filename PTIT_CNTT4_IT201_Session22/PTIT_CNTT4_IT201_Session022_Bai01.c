//
// Created by ROG on 7/24/2025.
//
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

void initGraph(int graph[100][100], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            graph[i][j] = 0;
        }
    }
}
void addEdge(int graph[MAX][MAX], int u, int v) {
    graph[u][v] = 1;
    graph[v][u] = 1;
}
void printGraph(int graph[100][100], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d", graph[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int n;
    scanf("%d", &n);
    int graph[100][100];
    initGraph(graph, n);
    int u, v;
    while (scanf("%1d%1d", &u, &v) == 2) {
        addEdge(graph, u, v);
    }
    printGraph(graph, n);

    return 0;
}