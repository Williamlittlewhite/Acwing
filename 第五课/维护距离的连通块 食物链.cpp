#include<iostream>
using namespace std;
const int n = 5e+4 + 10;
int p[n], d[n];
int find(int x) {
    if (p[x] != x) {
        int u = find(p[x]);
        d[x] += d[p[x]];           //�����д�����õ��˵ݹ��ʱp[x]�Ѿ�ά�����˵����ڵ�ľ��� d[x]��ʱ����1
                                //��û��ά�� ��˿�����ôд
        p[x] = u;
    }
    return p[x];
}
int main()
{
    int N, K;
    scanf("%d%d", &N, &K);
    for (int i = 0;i < N;i++)
        p[i] = i;
    int res = 0;
    while (K--) {
        int D, X, Y;
        scanf("%d%d%d", &D, &X, &Y);
        if (X > N || Y > N)    res++;
        else {
            int px = find(X), py = find(Y);
            if (D == 1) {
                if (px == py && (d[X] - d[Y]) % 3) res++;  //�μ��²���ϲ�Ĺ涨  ͬ�༴ͬ�� �þ��볤�ȱ�ʾ����
                else if (px != py)
                {
                    p[px] = py;
                    d[px] = d[Y] - d[X];
                }
            }
            else {
                if (px == py && (d[X] - d[Y] - 1) % 3) res++;      //�����д�����Ի���ͼ����һ�¼��ɣ�
                //�μ��²���ϲ�Ĺ涨
                else if (px != py) {
                    p[px] = py;
                    d[px] = d[Y] + 1 - d[X];
                }
            }

        }
    }
    printf("%d", res);
}

���ߣ�ɶҲ�����С�ײ�
���ӣ�https ://www.acwing.com/activity/content/code/content/3856186/
��Դ��AcWing
����Ȩ���������С���ҵת������ϵ���߻����Ȩ������ҵת����ע��������