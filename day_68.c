#include <stdio.h>

#define MAX 10

int queue[MAX], front = -1, rear = -1;

void enqueue(int x) {
    if (rear == MAX - 1)
        return;
    if (front == -1)
        front = 0;
    queue[++rear] = x;
}

int dequeue() {
    if (front == -1)
        return -1;
    int x = queue[front];
    if (front == rear)
        front = rear = -1;
    else
        front++;
    return x;
}

int main() {
    int n, i, j;
    int graph[MAX][MAX];
    int indegree[MAX] = {0};

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (graph[i][j] == 1)
                indegree[j]++;
        }
    }

    for (i = 0; i < n; i++) {
        if (indegree[i] == 0)
            enqueue(i);
    }

    printf("Topological Sort: ");

    while (front != -1) {
        int node = dequeue();
        printf("%d ", node);

        for (j = 0; j < n; j++) {
            if (graph[node][j] == 1) {
                indegree[j]--;
                if (indegree[j] == 0)
                    enqueue(j);
            }
        }
    }

    return 0;
}