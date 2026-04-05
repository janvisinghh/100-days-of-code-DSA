#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int queue[MAX], front = -1, rear = -1;

void enqueue(int x) {
    if (rear == MAX - 1) return;
    if (front == -1) front = 0;
    queue[++rear] = x;
}

int dequeue() {
    if (front == -1 || front > rear) return -1;
    return queue[front++];
}

int isEmpty() {
    return front == -1 || front > rear;
}

struct Node {
    int data;
    struct Node* next;
};

struct Node* adj[MAX];

void addEdge(int u, int v) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = v;
    newNode->next = adj[u];
    adj[u] = newNode;
}

void bfs(int n, int s) {
    int visited[MAX] = {0};
    enqueue(s);
    visited[s] = 1;

    while (!isEmpty()) {
        int u = dequeue();
        printf("%d ", u);

        struct Node* temp = adj[u];
        while (temp) {
            if (!visited[temp->data]) {
                enqueue(temp->data);
                visited[temp->data] = 1;
            }
            temp = temp->next;
        }
    }
}

int main() {
    int n, e, u, v, s;
    scanf("%d", &n);

    for (int i = 0; i < n; i++) adj[i] = NULL;

    scanf("%d", &e);
    for (int i = 0; i < e; i++) {
        scanf("%d %d", &u, &v);
        addEdge(u, v);
        addEdge(v, u);
    }

    scanf("%d", &s);
    bfs(n, s);

    return 0;
}