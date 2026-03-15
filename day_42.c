#include <stdio.h>

int main()
{
    int n;
    scanf("%d",&n);

    int queue[n], stack[n];
    int front=0,rear=n-1,top=-1;

    for(int i=0;i<n;i++)
        scanf("%d",&queue[i]);

    for(int i=0;i<n;i++)
        stack[++top]=queue[i];

    for(int i=0;i<n;i++)
        queue[i]=stack[top--];

    for(int i=0;i<n;i++)
        printf("%d ",queue[i]);

    return 0;
}