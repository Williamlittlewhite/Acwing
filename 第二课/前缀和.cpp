#include<iostream>
using namespace std;
const int N = 1e+5 + 10; //ע�������Χ
int a[N], s[N];
int main() {
    int n, m;
    int l, r;
    scanf("%d%d", &n, &m);
    for (int i = 1;i <= n;i++)
        scanf("%d", &a[i]);
    for (int i = 1;i <= n;i++)
        s[i] = s[i - 1] + a[i];

    for (int i = 1;i <= m;i++)
    {
        scanf("%d%d", &l, &r);
        printf("%d\n", s[r] - s[l - 1]);  //ע������
    }
}

//���ߣ�ɶҲ�����С�ײ�
//���ӣ�https ://www.acwing.com/activity/content/code/content/3739678/
//��Դ��AcWing
//����Ȩ���������С���ҵת������ϵ���߻����Ȩ������ҵת����ע��������