#include<iostream>
#include<cstring>
const int N = 510, M = 1e+5 + 10;
int d[N], g[N][N], st[M];
int n, m;
using namespace std;
int dijkstra() {
    memset(d, 0x3f, sizeof d);
    d[1] = 0;
    for (int i = 0; i < n - 1; i++) {
        int t = -1;
        for (int j = 1; j <= n; j++)
            if (!st[j] && (t == -1 || d[j] < d[t]))         //t��ʾ����S�����������̾����һ����
                t = j;

        for (int j = 1; j <= n; j++)
            d[j] = min(d[j], d[t] + g[t][j]);//���������������������ľ���

        st[t] = true;  //һ��Ҫ�ǵñ���Ѿ��ҵ��˸õ���Ѿ����ڼ���S��
    }
    if (d[n] == 0x3f3f3f3f) return -1;
    return d[n];
}
int main() {
    cin >> n >> m;
    memset(g, 0x3f, sizeof g);//����Ӿ���ȫ��ʼ��Ϊ�������ʾ������
    while (m--) {
        int x, y, z;
        cin >> x >> y >> z;
        // g[x][y] = z;
        g[x][y] = min(g[x][y], z);//�����رߵ��������֤��С���뼴��
    }
    cout << dijkstra() << endl;
    return 0;
}

���ߣ�ɶҲ�����С�ײ�
���ӣ�https ://www.acwing.com/activity/content/code/content/3928984/
��Դ��AcWing
����Ȩ���������С���ҵת������ϵ���߻����Ȩ������ҵת����ע��������