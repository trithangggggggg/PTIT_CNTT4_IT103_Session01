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
int findLevel(Node *root, int value, int level) {
    if (root == NULL) {
        return 0;
    }
    if (root->data == value) {
        return level;
    }
    int leftLevel = findLevel(root->left, value, level + 1);
    if (leftLevel != 0) {
        return leftLevel;
    }
    int rightLevel = findLevel(root->right, value, level + 1);
    if (rightLevel != 0) {
        return rightLevel;
    }
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

    int value;
    printf("Enter value for node: ");
    scanf("%d", &value);
    int level = findLevel(root, value, 1);
    if (level != 0) {
        printf("The value is %d and the level is %d\n", value, level);
    }else {
        printf("The value %d not found\n", value);
    }
    freeTree(root);

    return 0;
}