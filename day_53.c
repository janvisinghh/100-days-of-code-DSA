#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *left, *right;
} Node;

typedef struct QNode {
    Node* treeNode;
    int hd;
} QNode;

typedef struct Queue {
    QNode arr[1000];
    int front, rear;
} Queue;

void initQueue(Queue* q) {
    q->front = q->rear = 0;
}

int isEmpty(Queue* q) {
    return q->front == q->rear;
}

void enqueue(Queue* q, Node* node, int hd) {
    q->arr[q->rear].treeNode = node;
    q->arr[q->rear].hd = hd;
    q->rear++;
}

QNode dequeue(Queue* q) {
    return q->arr[q->front++];
}

Node* newNode(int val) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->data = val;
    node->left = node->right = NULL;
    return node;
}

Node* buildTree(int arr[], int n) {
    if (n == 0 || arr[0] == -1) return NULL;

    Node* root = newNode(arr[0]);
    Queue q;
    initQueue(&q);

    enqueue(&q, root, 0);
    int i = 1;

    while (!isEmpty(&q) && i < n) {
        Node* curr = dequeue(&q).treeNode;

        if (i < n && arr[i] != -1) {
            curr->left = newNode(arr[i]);
            enqueue(&q, curr->left, 0);
        }
        i++;

        if (i < n && arr[i] != -1) {
            curr->right = newNode(arr[i]);
            enqueue(&q, curr->right, 0);
        }
        i++;
    }
    return root;
}

void verticalOrder(Node* root) {
    if (!root) return;

    int count[200] = {0};

    int offset = 100; 

    Queue q;
    initQueue(&q);

    enqueue(&q, root, 0);

    while (!isEmpty(&q)) {
        QNode temp = dequeue(&q);
        Node* curr = temp.treeNode;
        int hd = temp.hd + offset;

        map[hd][count[hd]++] = curr->data;

        if (curr->left)
            enqueue(&q, curr->left, temp.hd - 1);
        if (curr->right)
            enqueue(&q, curr->right, temp.hd + 1);
    }

    for (int i = 0; i < 200; i++) {
        if (count[i] > 0) {
            for (int j = 0; j < count[i]; j++) {
                printf("%d ", map[i][j]);
            }
            printf("\n");
        }
    }
}

int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    Node* root = buildTree(arr, n);
    verticalOrder(root);

    return 0;
}