#include<cstdio>
#include<iostream>
using namespace std;
const int n = 1e+5 + 10;
const int m = 1e+6 + 10;
int main() {
    char p[n], s[m];
    int N;
    scanf("%d", &N);
    scanf("%s", p + 1);   //KMPģ��һ���Ǵ�1��ʼ��ȡ
    // printf("%c",p[1]);
    int M;
    scanf("%d", &M);
    scanf("%s", s + 1); //KMPģ��һ���Ǵ�1��ʼ��ȡ
    // printf("%c",s[1]);
    int ne[n];
    for (int i = 2, j = 0;i <= N;i++)
    {
        while (j && p[i] != p[j + 1])j = ne[j];
        if (p[i] == p[j + 1])j++;
        ne[i] = j;
    }
    for (int i = 1, j = 0;i <= M;i++)
    {
        while (j && s[i] != p[j + 1])j = ne[j];
        if (s[i] == p[j + 1])j++;
        if (j == N)
        {
            cout << i - N << ' ';   //���������ʼλ�õ��±꣡
            j = ne[j];//��������Ŀ���ǽ������Ӵ���ƥ��
        }
    }

}

���ߣ�ɶҲ�����С�ײ�
���ӣ�https ://www.acwing.com/activity/content/code/content/3842654/
��Դ��AcWing
����Ȩ���������С���ҵת������ϵ���߻����Ȩ������ҵת����ע��������