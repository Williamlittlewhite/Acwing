#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
const int N = 1e+6 + 10;
int a[N], b[N];
int lowbit(int x) {
    x = x & (-x);
    return x; //�����Ȼ���Ƿ���ֵ�� debug�˰��죡��
}
int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0;i < n;i++)
        scanf("%d", &a[i]);
    for (int i = 0;i < n;i++) {
        int j = 0;
        while (a[i] != 0) { a[i] -= lowbit(a[i]);j++; }
        b[i] = j;
    }
    // printf("%d",lowbit(1));
    for (int i = 0;i < n;i++)
        printf("%d ", b[i]);
    return 0;
}

���ߣ�ɶҲ�����С�ײ�
���ӣ�https ://www.acwing.com/activity/content/code/content/3791668/
��Դ��AcWing
����Ȩ���������С���ҵת������ϵ���߻����Ȩ������ҵת����ע��������