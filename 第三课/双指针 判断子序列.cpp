#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
const int N = 1e+5 + 10;
int a[N], b[N], c[N];
int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 0;i < n;i++)
        scanf("%d", &a[i]);
    for (int j = 0;j < m;j++)
        scanf("%d", &b[j]);
    int i, j;
    // while (i < n && j < m)
    // {
    //     if (a[i] == b[j]) i ++ ;
    //     j ++ ;
    // }
    for (i = 0, j = 0;i < n;i++, j++)        //����ģ���ǲ���ȡ�ģ������Ӧ���뵽�鲢�����˫ָ��д����y��ע�Ͳο�����
    {                           //����y��д����������
        while (j < m && b[j] != a[i])j++;
    }

    if (j > m) printf("No");
    else printf("Yes");




    return 0;
}

���ߣ�ɶҲ�����С�ײ�
���ӣ�https ://www.acwing.com/activity/content/code/content/3791253/
��Դ��AcWing
����Ȩ���������С���ҵת������ϵ���߻����Ȩ������ҵת����ע��������