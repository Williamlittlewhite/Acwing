#include<iostream>
using namespace std;
const int N = 1e+5 + 10;
int a[N], b[N];
void insert(int& l, int& r, int& c)   //���Ĳ������ѱ����м�����Ԫ�ؼ�һ�������޸�Ϊ�������ӱ߽��������ͨ��                                    //�ٴι���ǰ׺�� ��������������ǰ׺������
{
    b[l] += c;
    b[r + 1] -= c;
}
int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 1;i <= n;i++)
        scanf("%d", &a[i]);   //������뷽������������ ������ѧ�����ϵĹ���

    for (int i = 1;i <= n;i++)
        insert(i, i, a[i]);

    for (int i = 1;i <= m;i++)
    {
        int l, r, c;
        scanf("%d%d%d", &l, &r, &c);
        insert(l, r, c);
    }

    for (int i = 1;i <= n;i++)
        a[i] = a[i - 1] + b[i];

    for (int i = 1;i <= n;i++)
        printf("%d ", a[i]);  //ע�������ʽ

    return 0;
}

���ߣ�ɶҲ�����С�ײ�
���ӣ�https ://www.acwing.com/activity/content/code/content/3747394/
��Դ��AcWing
����Ȩ���������С���ҵת������ϵ���߻����Ȩ������ҵת����ע��������