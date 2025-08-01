//
// Created by ROG on 7/21/2025.
//
//
// Created by ROG on 7/21/2025.
//
//
// Created by ROG on 7/21/2025.
//
//
// Created by ROG on 7/21/2025.
//
//
// Created by ROG on 7/21/2025.
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

//preorder
void preOrder(Node *root) {
    if (root == NULL) {
        return;
    }
    printf("%d ", root->data);
    preOrder(root->left);
    preOrder(root->right);
}
//Postorder
void postOrder(Node *root) {
    if (root == NULL) {
        return;
    }
    postOrder(root->left);
    postOrder(root->right);
    printf("%d ", root->data);
}
//inorder
void inOrder(Node *root) {
    if (root == NULL) {
        return;
    }
    inOrder(root->left);
    printf("%d ", root->data);
    inOrder(root->right);
}

int dfsSearch(Node *root, int key) {
    if (root == NULL) {
        return 0;
    }
    if (root->data == key) {
        return 1;
    }
    if (dfsSearch(root->left, key)) {
        return 1;
    }
    if (dfsSearch(root->right, key)) {
        return 1;
    }
    return 0;
}


int main() {

    Node *root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);


    printf("Pre Order Traversal: \n");
    preOrder(root);

    printf("\n");
    printf("Post Order Traversal: \n");
    postOrder(root);

    printf("\n");
    printf("In Order Traversal: \n");
    inOrder(root);


    printf("\n");
    int keySearch;
    printf("Enter Key to Search: ");
    scanf("%d", &keySearch);
    if (dfsSearch(root, keySearch)) {
        printf("Da tim thay %d trong cay!\n", keySearch);
    }else {
        printf("Khong tim thay %d trong cay\n", keySearch);
    }

    return 0;
}