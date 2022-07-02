#include<iostream>
using namespace std;
const int N = 100010;
//void MergeSort(int q[], int l, int r) {
//    if (l >= r) return;
//    int mid = (l + r) >> 1;
//    MergeSort(q, l, mid);
//    MergeSort(q, mid + 1, r);
//    int tmp[N];
//    int i = l, j = mid + 1, k = 0;
//    while (i <= mid && j <= r) {
//        if (q[i] < q[j]) tmp[k++] = q[i++];
//        else tmp[k++] = q[j++];
//    }
//    while (i <= mid) tmp[k++] = q[i++];
//    while (j <= r)   tmp[k++] = q[j++];
//
//    for (int i = l, j = 0;i <= r;i++, j++)
//        q[i] = tmp[j];
//}
//
//
//int main()
//{
//    int n;
//    int a[N];
//    scanf("%d", &n);
//    for (int i = 0;i < n;i++)
//        cin >> a[i];
//    MergeSort(a, 0, n - 1);
//    for (int i = 0;i < n;i++)
//        cout << a[i] << " ";
//    return 0;
//}

/*ÇóÄæÐòÊý*/
#include<iostream>
using namespace std;
const int N = 100010;
int tmp[N];
int q[N];
long long MergeSort(int q[], int l, int r) {
    if (l >= r) return 0;
    int mid = (l + r) >> 1;
    int i = l, j = mid + 1, k = 0;
    long long count = MergeSort(q, l, mid) + MergeSort(q, mid + 1, r);
    while (i <= mid && j <= r) {
        if (q[i] <= q[j]) tmp[k++] = q[i++];
        else { tmp[k++] = q[j++];count += mid - i + 1; }
    }
    while (i <= mid) tmp[k++] = q[i++];
    while (j <= r) tmp[k++] = q[j++];
    for (int i = l, j = 0;i <= r;i++, j++)
        q[i] = tmp[j];
    return count;
}
int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 0;i < n;i++)
        cin >> q[i];
    long long ans = MergeSort(q, 0, n - 1);
    cout << ans;

    return 0;
}