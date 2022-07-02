//#include<iostream>
//using namespace std;
//const int N = 10000010;
//void QuickSort(int a[], int l, int r)
//{
//    if (l >= r) return;
//    int i = l - 1, j = r + 1;
//    int x = a[(l + r) >> 1];
//    while (i < j) {
//        do i++; while (a[i] < x);
//        do j--; while (a[j] > x);
//        if (i < j) swap(a[i], a[j]);
//    }
//    QuickSort(a, l, j);
//    QuickSort(a, j + 1, r);
//}
//int main()
//{
//    int n;
//    int a[N];
//    scanf("%d\n", &n);
//    for (int i = 0;i < n;i++)
//        cin >> a[i];
//    QuickSort(a, 0, n - 1);
//    for (int i = 0;i < n;i++)
//        cout << a[i] << " ";
//    return 0;
//
//}