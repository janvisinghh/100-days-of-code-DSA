#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX 100

struct Node {
    int vertex;
    int weight;
    struct Node* next;
};

struct Node* adj[MAX];

struct HeapNode {
    int vertex;
    int dist;
};

struct MinHeap {
    int size;
    struct HeapNode heap[MAX];
};

struct Node* createNode(int v, int w) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->vertex = v;
    newNode->weight = w;
    newNode->next = NULL;
    return newNode;
}

void addEdge(int u, int v, int w) {
    struct Node* newNode = createNode(v, w);
    newNode->next = adj[u];
    adj[u] = newNode;
}

void swap(struct HeapNode* a, struct HeapNode* b) {
    struct HeapNode temp = *a;
    *a = *b;
    *b = temp;
}

void heapify(struct MinHeap* mh, int i) {
    int smallest = i;
    int left = 2*i + 1;
    int right = 2*i + 2;

    if (left < mh->size && mh->heap[left].dist < mh->heap[smallest].dist)
        smallest = left;

    if (right < mh->size && mh->heap[right].dist < mh->heap[smallest].dist)
        smallest = right;

    if (smallest != i) {
        swap(&mh->heap[i], &mh->heap[smallest]);
        heapify(mh, smallest);
    }
}

struct HeapNode extractMin(struct MinHeap* mh) {
    struct HeapNode root = mh->heap[0];
    mh->heap[0] = mh->heap[mh->size - 1];
    mh->size--;
    heapify(mh, 0);
    return root;
}

void insertHeap(struct MinHeap* mh, int v, int dist) {
    int i = mh->size++;
    mh->heap[i].vertex = v;
    mh->heap[i].dist = dist;

    while (i && mh->heap[(i-1)/2].dist > mh->heap[i].dist) {
        swap(&mh->heap[i], &mh->heap[(i-1)/2]);
        i = (i-1)/2;
    }
}

void dijkstra(int V, int src) {
    int dist[MAX];

    for (int i = 0; i < V; i++)
        dist[i] = INT_MAX;

    struct MinHeap mh;
    mh.size = 0;

    dist[src] = 0;
    insertHeap(&mh, src, 0);

    while (mh.size > 0) {
        struct HeapNode minNode = extractMin(&mh);
        int u = minNode.vertex;

        struct Node* temp = adj[u];
        while (temp != NULL) {
            int v = temp->vertex;
            int weight = temp->weight;

            if (dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
                insertHeap(&mh, v, dist[v]);
            }
            temp = temp->next;
        }
    }

    printf("Vertex\tDistance\n");
    for (int i = 0; i < V; i++)
        printf("%d\t%d\n", i, dist[i]);
}

int main() {
    int V = 5;

    for (int i = 0; i < V; i++)
        adj[i] = NULL;

    addEdge(0, 1, 10);
    addEdge(0, 4, 5);
    addEdge(1, 2, 1);
    addEdge(4, 1, 3);
    addEdge(4, 2, 9);
    addEdge(4, 3, 2);
    addEdge(2, 3, 4);
    addEdge(3, 0, 7);
    addEdge(3, 2, 6);

    dijkstra(V, 0);

    return 0;
}