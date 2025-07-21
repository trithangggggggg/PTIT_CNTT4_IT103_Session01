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

typedef struct QueueNode {
    Node *treeNode;
    struct QueueNode *next;
}QueueNode;

typedef struct Queue {
    QueueNode *front;
    QueueNode *rear;
} Queue;

Queue *createQueue() {
    Queue *newQueue = (Queue *)malloc(sizeof(Queue));
    newQueue->front = NULL;
    newQueue->rear = NULL;
    return newQueue;
}

int isEmpty(Queue *q) {
    return q->front == NULL && q->rear == NULL;
}

void enqueue(Queue *q, Node *treeNode) {
    QueueNode *newQueueNode = (QueueNode *)malloc(sizeof(QueueNode));
    newQueueNode->treeNode = treeNode;
    newQueueNode->next = NULL;

    if (q->rear == NULL) {
        q->front = q->rear = newQueueNode;
        return;
    }
    q->rear->next = newQueueNode;
    q->rear = newQueueNode;
}


Node *dequeue(Queue *q) {
    if (isEmpty(q)) {
        printf("Queue is empty\n");
        return NULL;
    }
    QueueNode *temp = q->front;
    Node *treeNode = temp->treeNode;
    q->front = q->front->next;
    if (q->front == NULL) {
        q->rear = NULL;
    }
    free(temp);
    return treeNode;
}


//ham duyet bfs
void bfsTraversal(Node *root) {
    if (root == NULL) {
        return;
    }
    Queue *q = createQueue();
    enqueue(q, root);

    while (!isEmpty(q)) {
        Node *temp = dequeue(q);
        printf("%d ", temp->data);
        if (temp->left != NULL) {
            enqueue(q, temp->left);
        }
        if (temp->right != NULL) {
            enqueue(q, temp->right);
        }
    }
}
int bfsSearch(Node *root, int target){
    if (root == NULL) return 0;

    Queue *q = createQueue();
    enqueue(q, root);

    while (!isEmpty(q)) {
        Node *temp = dequeue(q);
        if (temp->data == target) {
            return 1;
        }
        if (temp->left != NULL) enqueue(q, temp->left);
        if (temp->right != NULL) enqueue(q, temp->right);
    }
    return 0;
}


int main() {

    Node *root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);

    int target;
    printf("Enter Taget: ");
    scanf("%d", &target);
    if (bfsSearch(root, target)) {
        printf("\nFound %d in the tree\n", target);
    } else {
        printf("\n%d no found in the tree\n", target);
    }

    printf("\n");
    printf("BFS Traversal: \n");
    bfsTraversal(root);



    return 0;
}