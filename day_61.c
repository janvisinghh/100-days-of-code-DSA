#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, m, i, j, u, v, type;

    scanf("%d", &n);
    scanf("%d", &m);
    scanf("%d", &type);

    int **adj = (int **)malloc(n * sizeof(int *));
    for(i = 0; i < n; i++)
        adj[i] = (int *)malloc(n * sizeof(int));

    for(i = 0; i < n; i++)
        for(j = 0; j < n; j++)
            adj[i][j] = 0;

    for(i = 0; i < m; i++) {
        scanf("%d %d", &u, &v);
        adj[u][v] = 1;
        if(type == 0)
            adj[v][u] = 1;
    }

    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++)
            printf("%d ", adj[i][j]);
        printf("\n");
    }

    for(i = 0; i < n; i++)
        free(adj[i]);
    free(adj);

    return 0;
}