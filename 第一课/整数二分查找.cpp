#include<iostream>
using namespace std;
const int N = 1e5 + 10;
int a[N];
void binary_search(int l, int r, int query)
{
    int left = l, right = r;
    while (l < r)
    {
        int mid = l + r >> 1;
        if (a[mid] >= query) r = mid;
        else l = mid + 1;

    }
    if (a[l] != query) printf("%d %d\n", -1, -1);
    else {
        printf("%d", l);
        int l = left, r = right;
        while (l < r)
        {
            int mid = l + r + 1 >> 1;
            if (a[mid] <= query) l = mid;
            else r = mid - 1;
        }
        printf(" %d\n", l);
    }
}
int main() {
    int n, query, k;
    scanf("%d %d", &n, &k);
    for (int i = 0;i < n;i++)
        scanf("%d", &a[i]);
    for (int i = 0;i < k;i++)
    {
        scanf("%d", &query);
        binary_search(0, n - 1, query);
    }
    return 0;
}