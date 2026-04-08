#include <stdio.h>
#include <stdbool.h>

#define V 100

int graph[V][V];
bool visited[V];
int stack[V];
int top = -1;
int n;

void dfs(int v) {
    visited[v] = true;

    for (int i = 0; i < n; i++) {
        if (graph[v][i] && !visited[i]) {
            dfs(i);
        }
    }

    stack[++top] = v;
}

void topoSort() {
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            dfs(i);
        }
    }

    for (int i = top; i >= 0; i--) {
        printf("%d ", stack[i]);
    }
}

int main() {
    int edges, u, v;

    scanf("%d", &n);
    scanf("%d", &edges);

    for (int i = 0; i < edges; i++) {
        scanf("%d %d", &u, &v);
        graph[u][v] = 1;
    }

    topoSort();

    return 0;
}