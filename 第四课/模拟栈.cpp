#include<cstdio>
#include<iostream>
#include<string.h>
using namespace std;
const int N = 1e+6 + 10;
int stk[N];
int tt = 0;
int main() {
    int M;
    scanf("%d", &M);
    while (M--) {
        char op[5];
        scanf("%s", op);   //��ס��������Ĳ���
        if (!strcmp(op, "push")) { //strcmp�ǵ������ַ�����ȵ�ʱ�򷵻�0  str1<str2 ���ظ��� str1>str2 ��������
            int temp;
            scanf("%d", &temp);
            stk[++tt] = temp;
        }
        else if (!strcmp(op, "pop")) {
            tt--;
        }
        else if (!strcmp(op, "empty")) {
            if (tt > 0) printf("NO\n");
            else printf("YES\n");
        }
        else if (!strcmp(op, "query")) {
            printf("%d\n", stk[tt]);
        }

    }

    return 0;
}

���ߣ�ɶҲ�����С�ײ�
���ӣ�https ://www.acwing.com/activity/content/code/content/3828019/
��Դ��AcWing
����Ȩ���������С���ҵת������ϵ���߻����Ȩ������ҵת����ע��������