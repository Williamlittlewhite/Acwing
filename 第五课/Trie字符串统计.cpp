#include<cstdio>
#include<iostream>
using namespace std;
const int n = 100010;
int son[n][26];  //�ڶ�λ��26���㹻�� ��Ϊ�����26����52�������

int cnt[n];
int idx = 0;
void insert(char* str)
{
    int p = 0;
    for (int i = 0;str[i];i++)
    {
        int u = str[i] - 'a';
        if (son[p][u] == 0) son[p][u] = ++idx;
        p = son[p][u];
    }
    cnt[p]++;
}

int query(char* str) {
    int p = 0;
    for (int i = 0; str[i];i++)
    {
        int u = str[i] - 'a';
        if (son[p][u] == 0) return 0;
        p = son[p][u];
    }
    return cnt[p];
}
int main() {

    char op[2];
    int N;
    scanf("%d", &N);
    while (N--) {
        scanf("%s", op);
        // printf("%c",op[0]);
        if (op[0] == 'I') {
            char str[n];
            scanf("%s", str);
            insert(str);
        }
        else {
            char str[n];
            scanf("%s", str);
            printf("%d\n", query(str));
        }
    }
    return 0;
}

���ߣ�ɶҲ�����С�ײ�
���ӣ�https ://www.acwing.com/activity/content/code/content/3845037/
��Դ��AcWing
����Ȩ���������С���ҵת������ϵ���߻����Ȩ������ҵת����ע��������