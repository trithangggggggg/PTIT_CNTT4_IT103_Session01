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
int findMax(Node *root) {
    if (root == NULL) {
        return -999999999;
    }
    int maxLeft = findMax(root->left);
    int maxRight = findMax(root->right);
    int max = root->data;
    if (maxLeft > max ) {
        max = maxLeft;
    }
    if (maxRight > max ) {
        max = maxRight;
    }
    return max;
}
void freeTree(Node *root) {
    if (root == NULL) {
        return;
    }
    freeTree(root->left);
    freeTree(root->right);
    free(root);
}


int main() {

    Node *root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);
    root->right->left = createNode(6);
    root->right->right = createNode(7);

    int maxValue = findMax(root);
    printf("Max value = %d\n", maxValue);
    freeTree(root);

    return 0;
}