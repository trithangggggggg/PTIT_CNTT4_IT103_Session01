//
// Created by ROG on 7/22/2025.
//
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

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

void preOrder(Node *root) {
    if (root == NULL) {
        return;
    }
    printf("%d ", root->data);
    preOrder(root->left);
    preOrder(root->right);
    return;
}
void inOrder(Node *root) {
    if (root == NULL) {
        return;
    }
    inOrder(root->left);
    printf("%d ", root->data);
    inOrder(root->right);
    return;
}
void postOrder(Node *root) {
    if (root == NULL) {
        return;
    }
    postOrder(root->left);
    postOrder(root->right);
    printf("%d ", root->data);
    return;
}
void levelOrder(Node *root) {
    if (root == NULL) {
        return;
    }
    Node *queue[MAX];
    int front = 0;
    int rear = 0;
    queue[rear++] = root;
    while (front < rear) {
        Node *current = queue[front++];
        printf("%d ", current->data);
        if (current->left != NULL) {
            queue[rear++] = current->left;
        }
        if (current->right != NULL) {
            queue[rear++] = current->right;
        }
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

    Node *root = createNode(2);
    root->left = createNode(3);
    root->right = createNode(4);
    root->left->left = createNode(5);

    printf("Preorder: ");
    preOrder(root);
    printf("\n");
    printf("Inorder: ");
    inOrder(root);
    printf("\n");
    printf("Postorder: ");
    postOrder(root);
    printf("\n");
    printf("Level Order: ");
    levelOrder(root);

    freeTree(root);

    return 0;
}