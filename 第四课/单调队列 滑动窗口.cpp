#include<iostream>
using namespace std;
const int N = 1e+6 + 10;
int q[N], hh = 0, tt = -1;
int temp[N];
int main() {
    int n, k;
    scanf("%d%d", &n, &k);
    for (int i = 0;i < n;i++) {
        scanf("%d", &temp[i]);
    }
    for (int i = 0;i < n;i++) {
        while (tt >= hh && q[hh] < i - k + 1) hh++; //�������ڵ����λ���ƶ�����ǰ����ı�����Ԫ��
        while (tt >= hh && temp[q[tt]] >= temp[i])tt--;//ά�ֻ��������ǵ���������,���д洢��Ԫ�����±�
        q[++tt] = i;
        if (i >= k - 1)                //����������ڲ�Ҫ��ӵ�������ʼ ��ôȡ�������������������
            printf("%d ", temp[q[hh]]);
    }
    printf("\n");
    hh = 0;tt = -1;
    for (int i = 0;i < n;i++)                    //i��ʾ��ǰ������ʼλ��
    {
        while (tt >= hh && q[hh] < i - k + 1)hh++;    //������������ƶ�����ǰ����λ��
        while (tt >= hh && temp[q[tt]] <= temp[i])tt--; //ά�ֶ����е�������Ӧ��ֵ�ǵ����ݼ���
        q[++tt] = i;
        if (i >= k - 1)
            printf("%d ", temp[q[hh]]);    //����Ԫ�ؾ���Զ�ǵ�ǰ�����ֵ
    }
    return 0;
}

���ߣ�ɶҲ�����С�ײ�
���ӣ�https ://www.acwing.com/activity/content/code/content/3842322/
��Դ��AcWing
����Ȩ���������С���ҵת������ϵ���߻����Ȩ������ҵת����ע��������