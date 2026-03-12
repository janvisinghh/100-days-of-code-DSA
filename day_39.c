#include <stdio.h>

#define MAX 100

int heap[MAX];
int size = 0;

void swap(int *a, int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

void insert(int x)
{
    if(size == MAX)
        return;

    int i = size;
    heap[size++] = x;

    while(i != 0 && heap[(i-1)/2] > heap[i])
    {
        swap(&heap[(i-1)/2], &heap[i]);
        i = (i-1)/2;
    }
}

void heapify(int i)
{
    int smallest = i;
    int left = 2*i + 1;
    int right = 2*i + 2;

    if(left < size && heap[left] < heap[smallest])
        smallest = left;

    if(right < size && heap[right] < heap[smallest])
        smallest = right;

    if(smallest != i)
    {
        swap(&heap[i], &heap[smallest]);
        heapify(smallest);
    }
}

void extractMin()
{
    if(size <= 0)
    {
        printf("-1\n");
        return;
    }

    if(size == 1)
    {
        size--;
        printf("%d\n", heap[0]);
        return;
    }

    int root = heap[0];
    heap[0] = heap[size-1];
    size--;

    heapify(0);

    printf("%d\n", root);
}

void peek()
{
    if(size == 0)
        printf("-1\n");
    else
        printf("%d\n", heap[0]);
}

int main()
{
    int n;
    scanf("%d", &n);

    while(n--)
    {
        char op[20];
        scanf("%s", op);

        if(op[0] == 'i')
        {
            int x;
            scanf("%d", &x);
            insert(x);
        }
        else if(op[0] == 'e')
        {
            extractMin();
        }
        else if(op[0] == 'p')
        {
            peek();
        }
    }

    return 0;
}