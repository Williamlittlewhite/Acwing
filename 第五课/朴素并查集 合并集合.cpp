#include<iostream>
using namespace std;
const int N = 1e+5 + 10;
int p[N];
int find(int x) {
    if (p[x] != x)             //����һ������p[x]ȥ�ж��Ƿ��ǵݹ��յ�  ����debug�˰��죡
        p[x] = find(p[x]);
    return p[x];
}
int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 1;i <= n;i++)
        p[i] = i;
    while (m--) {
        char str[2];
        scanf("%s", str);
        if (str[0] == 'M') {
            int a, b;
            scanf("%d%d", &a, &b);
            if (find(a) == find(b))
                continue;
            else
                p[find(a)] = find(b);
        }
        else {
            int a, b;
            scanf("%d%d", &a, &b);
            if (find(a) == find(b))
                printf("Yes\n");
            else
                printf("No\n");
        }
    }

    return 0;
}