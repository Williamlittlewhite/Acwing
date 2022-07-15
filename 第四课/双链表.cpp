#include<iostream>
#include<cstdio>
using namespace std;
const int N = 1e+5 + 10;
int e[N], l[N], r[N], idx;
void init()
{
    idx = 2;
    l[1] = 0;
    r[0] = 1;
}
void add_tohead(int x) {
    e[idx] = x;
    r[idx] = r[0];
    l[idx] = 0;
    l[r[0]] = idx;
    r[0] = idx;
    idx++;
}
void add_totail(int x) {
    e[idx] = x;
    r[idx] = 1;
    l[idx] = l[1];
    r[l[1]] = idx;
    l[1] = idx;
    idx++;
}
void remove(int k) {
    r[l[k]] = r[k];
    l[r[k]] = l[k];
}
void insert(int k, int c)
{
    e[idx] = c;
    l[idx] = k;
    r[idx] = r[k];
    l[r[k]] = idx;
    r[k] = idx;
    idx++;
}

int main() {
    init();
    int M;
    scanf("%d", &M);
    while (M--) {
        char str[4];                     //char�����һЩ�����ַ�  ��%s�Ķ�������ȡ�����кͿո�
        scanf("%s", str);
        if (str[0] == 'L') {
            int temp;
            scanf("%d", &temp);
            // printf("%d",temp);
            add_tohead(temp);
        }
        else if (str[0] == 'R') {
            int temp;
            scanf("%d", &temp);
            // printf("%d",temp);
            add_totail(temp);
        }
        else if (str[0] == 'D') {
            int temp;
            scanf("%d", &temp);
            // printf("%d",temp);               //˫����ĵ�k���ڵ��Ӧ��������k+1 ����д����       idx��2��ʼ
            remove(temp + 1);                     //������ĵ�k���ڵ��Ӧ��������k-1 head=-1��д����  idx��0��ʼ
        }
        else if (str[0] == 'I' && str[1] == 'L') {
            int temp1, temp2;
            scanf("%d%d", &temp1, &temp2);
            // printf("%d",temp);
            insert(l[temp1 + 1], temp2);
        }
        else if (str[0] == 'I' && str[1] == 'R') {
            int temp1, temp2;
            scanf("%d%d", &temp1, &temp2);
            // printf("%d",temp);
            insert(temp1 + 1, temp2);
        }

    }

    for (int i = r[0];i != 1;i = r[i])
        printf("%d ", e[i]);


    return 0;
}

���ߣ�ɶҲ�����С�ײ�
���ӣ�https ://www.acwing.com/activity/content/code/content/3809076/
��Դ��AcWing
����Ȩ���������С���ҵת������ϵ���߻����Ȩ������ҵת����ע��������