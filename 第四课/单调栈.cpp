#include<iostream>
#include<cstdio>
using namespace std;
const int M = 1e+5 + 10;
int stk[M], a[M];
int tt = 0;
int main() {
    int N;
    scanf("%d", &N);
    for (int i = 0;i < N;i++) {
        scanf("%d", &a[i]);
    }
    for (int i = 0, j = 0;i < N;i++)
    {
        while (tt && stk[tt] >= a[i])tt--;    //ά��ջ�е�Ԫ��һ���ǵ��������ģ�����С��a[i]�ģ�
                                         //��Ϊ�������м����������ұ߽������ô�������� ��Ϊȡ������С��a[i]
        if (tt == 0) cout << -1 << ' ';         //һ�����Ƚ���������ж� Ȼ������ջ ��Ϊ�����ĳ��֮ǰ����С��
        else printf("%d ", stk[tt]);
        stk[++tt] = a[i];
    }


    return 0;
}

���ߣ�ɶҲ�����С�ײ�
���ӣ�https ://www.acwing.com/activity/content/code/content/3842152/
��Դ��AcWing
����Ȩ���������С���ҵת������ϵ���߻����Ȩ������ҵת����ע��������