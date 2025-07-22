//
// Created by ROG on 7/22/2025.
//
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *left;
    struct Node *right;
}Node;

Node *createNode(int data) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

int main() {

    int x;
    printf("Enter value for node: ");
    scanf("%d", &x);

    Node *root = createNode(x);
    printf("Node da duoc tao: data = %d, left = %p, right = %p", root->data, root->left, root->right);

    free(root);



    return 0;
}