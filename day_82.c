#include <stdio.h>

int lowerBound(int a[], int n, int x) {
    int low = 0, high = n - 1, ans = n;
    while(low <= high) {
        int mid = (low + high) / 2;
        if(a[mid] >= x) {
            ans = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return ans;
}

int upperBound(int a[], int n, int x) {
    int low = 0, high = n - 1, ans = n;
    while(low <= high) {
        int mid = (low + high) / 2;
        if(a[mid] > x) {
            ans = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return ans;
}

int main() {
    int n;
    scanf("%d", &n);

    int a[n];
    for(int i = 0; i < n; i++)
        scanf("%d", &a[i]);

    int x;
    scanf("%d", &x);

    printf("%d %d", lowerBound(a, n, x), upperBound(a, n, x));

    return 0;
}