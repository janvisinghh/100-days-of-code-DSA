#include <stdio.h>
#include <stdbool.h>

#define V 100

int graph[V][V];
bool visited[V];
bool recStack[V];
int n;

bool dfs(int v) {
    visited[v] = true;
    recStack[v] = true;

    for (int i = 0; i < n; i++) {
        if (graph[v][i]) {
            if (!visited[i] && dfs(i))
                return true;
            else if (recStack[i])
                return true;
        }
    }

    recStack[v] = false;
    return false;
}

bool hasCycle() {
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            if (dfs(i))
                return true;
        }
    }
    return false;
}

int main() {
    int edges, u, v;

    scanf("%d", &n);
    scanf("%d", &edges);

    for (int i = 0; i < edges; i++) {
        scanf("%d %d", &u, &v);
        graph[u][v] = 1;
    }

    if (hasCycle())
        printf("YES\n");
    else
        printf("NO\n");

    return 0;
}