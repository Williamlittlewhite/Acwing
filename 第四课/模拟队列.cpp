#include<iostream>
#include<string.h>
const int N = 1e+5 + 10;
int q[N], hh = 0, tt = -1;
using namespace std;
int main() {
    int M;
    scanf("%d", &M);
    while (M--)
    {
        char op[5];
        scanf("%s", op);
        if (!strcmp(op, "push"))
        {
            int temp;
            scanf("%d", &temp);
            q[++tt] = temp;
        }
        else if (!strcmp(op, "pop"))
        {
            hh++;                     //���г���Ҫ��hh++
        }
        else if (!strcmp(op, "empty"))
        {
            if (tt >= hh) printf("NO\n");
            else printf("YES\n");
        }
        else if (!strcmp(op, "query"))
        {
            printf("%d\n", q[hh]);
        }
    }
    return 0;
}

���ߣ�ɶҲ�����С�ײ�
���ӣ�https ://www.acwing.com/activity/content/code/content/3828084/
��Դ��AcWing
����Ȩ���������С���ҵת������ϵ���߻����Ȩ������ҵת����ע��������