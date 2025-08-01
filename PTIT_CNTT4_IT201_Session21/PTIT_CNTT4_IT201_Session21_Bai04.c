//
// Created by ROG on 7/23/2025.
//
#include <stdio.h>

void addEdge(int graph[3][3], int firstNode, int secondNode) {
    graph[firstNode][secondNode] = 1;
    graph[secondNode][firstNode] = 1;
}
void printGraph(int graph[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%d ", graph[i][j]);
        }
        printf("\n");
    }
}
int main() {
    int graph[3][3] = {
        {0, 0, 0},
        {0, 0, 0},
        {0, 0, 0}
    };
    addEdge(graph, 1, 0);
    addEdge(graph, 1, 2);
    addEdge(graph, 2, 0);
    printGraph(graph);

    return 0;
}