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

typedef struct Queue {
    Node *items[MAX];
    int front, rear;
} Queue;

void initQueue(Queue *q) {
    q->front = 0;
    q->rear = 0;
}

int isEmpty(Queue *q) {
    return q->front == q->rear;
}
void enQueue(Queue *q, Node *node) {
    if (q->rear < MAX) {
        q->items[q->rear++] = node;
    }
}
Node *deQueue(Queue *q) {
    if (!isEmpty(q)) {
        return q->items[q->front++];
    }
    return NULL;
}


Node *createNode(int data) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
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
void insertNodeLevelOrder(Node* root, int value) {
    if (root == NULL) return;

    Queue q;
    initQueue(&q);
    enQueue(&q, root);

    while (!isEmpty(&q)) {
        Node* current = deQueue(&q);

        if (current->left == NULL) {
            current->left = createNode(value);
            break;
        } else {
            enQueue(&q, current->left);
        }

        if (current->right == NULL) {
            current->right = createNode(value);
            break;
        } else {
            enQueue(&q, current->right);
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

    insertNodeLevelOrder(root, 5);
    insertNodeLevelOrder(root, 6);

    printf("Level Order: ");
    levelOrder(root);

    freeTree(root);

    return 0;
}