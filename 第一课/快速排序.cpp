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

//#�ڶ��� ����ѡ������
//#include<iostream>
//using namespace std;
//const int N = 1e+5 + 10;
//int quicksort(int q[], int l, int r, int k)
//{
//    if (l >= r) return q[l];
//    int x = q[(l + r) >> 1];
//    int i = l - 1, j = r + 1;
//    while (i < j)
//    {
//        do { i++; } while (q[i] < x);
//        do { j--; } while (q[j] > x);
//        if (i < j) swap(q[i], q[j]);
//    }
//    int bound = j - l + 1;
//    if (bound >= k)
//        return quicksort(q, l, j, k);
//    else
//        return quicksort(q, j + 1, r, k - bound);
//}
//
//int main() {
//    int q[N];
//    int n, k;
//    scanf("%d %d", &n, &k);
//    for (int i = 0;i < n;i++)
//        scanf("%d", &q[i]);
//    cout << quicksort(q, 0, n - 1, k);
//    return 0;
//}
//
//���ߣ�ɶҲ�����С�ײ�
//���ӣ�https ://www.acwing.com/activity/content/code/content/3706087/
//��Դ��AcWing
//����Ȩ���������С���ҵת������ϵ���߻����Ȩ������ҵת����ע��������