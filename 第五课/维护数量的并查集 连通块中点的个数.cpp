#include<iostream>
using namespace std;
const int N = 1e+5 + 10;
int p[N], Size[N];
int find(int x)
{
    if (p[x] != x)
        p[x] = find(p[x]);
    return p[x];
}
int main() {
    int n, m;
    scanf("%d%d", &n, &m);

    for (int i = 1;i <= n;i++) {
        p[i] = i;
        Size[i] = 1;
    }
    while (m--) {
        char op[2];
        int a, b;
        scanf("%s", op);
        if (op[0] == 'C') {
            scanf("%d%d", &a, &b);
            if (find(a) != find(b)) {
                // p[find(a)]=find(b);     //����һ���Ǹ��ڵ�ĸ��ӹ�ϵ
                // Size[find(b)]+=Size[find(a)]; //����һ��Ҫ��ֵ֮����д��Ϊ����ôд���Ѿ���a�����ڱ��� 
                //���Գ��� ����˳��Ϳ���AC��
                Size[find(b)] += Size[find(a)];
                p[find(a)] = find(b);
            }
        }
        else if (op[0] == 'Q' && op[1] == '1') {
            scanf("%d%d", &a, &b);
            if (a == b) printf("Yes\n");
            else if (find(a) != find(b))printf("No\n");
            else printf("Yes\n");
        }
        else if (op[0] == 'Q' && op[1] == '2') {
            scanf("%d", &a);
            printf("%d\n", Size[find(a)]);   //����һ��Ҫ�ҵ����ڵ㷵��ֵ
        }

    }


    return 0;
}

���ߣ�ɶҲ�����С�ײ�
���ӣ�https ://www.acwing.com/activity/content/code/content/3854913/
��Դ��AcWing
����Ȩ���������С���ҵת������ϵ���߻����Ȩ������ҵת����ע��������