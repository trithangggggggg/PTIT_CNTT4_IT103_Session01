//
// Created by ROG on 7/21/2025.
//
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;

Node* createNode(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

Node* buildTree() {
    Node* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->right->left = createNode(5);
    return root;
}

int treeHeight(Node* root) {
    if (root == NULL) {
        return -1;
    }
    int leftHeight = treeHeight(root->left);
    int rightHeight = treeHeight(root->right);
    if (leftHeight > rightHeight) {
        return leftHeight + 1;
    } else {
        return rightHeight + 1;
    }
}

int main() {

    Node* root = buildTree();

    int height = treeHeight(root);
    printf("Chieu cao cua cay: %d\n", height);



    return 0;
}
