#include<iostream>
#include<cstring>
using namespace std;
const int N = 510;
int n, m;
int g[N][N], dist[N], st[N];

int prim() {
    int sum = 0;
    memset(dist, 0x3f, sizeof dist);
    for (int i = 0; i < n; i++) {
        int t = -1;
        for (int j = 1; j <= n; j++) {
            if (!st[j] && (t == -1 || dist[t] > dist[j]))
                t = j; //�����Ǹ�ֵ debug�˰���
        }
        if (i && st[t] == 0x3f3f3f3f) return 0x3f3f3f3f;
        if (i) sum += dist[t];
        st[t] = true;
        for (int j = 1; j <= n; j++)
            dist[j] = min(dist[j], g[t][j]);
    }
    return sum;
}

int main() {
    memset(g, 0x3f, sizeof g); //�ǵþ������Ҳ�ó�ʼ��������
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        g[u][v] = g[v][u] = min(g[u][v], w); //�ǵô����ر�
    }
    int t = prim();
    if (t > 0x3f3f3f3f / 2)  //�и�Ȩ�߼ǵ���ô�жϣ���
        cout << "impossible" << endl;
    else
        cout << t << endl;
}

���ߣ�ɶҲ�����С�ײ�
���ӣ�https ://www.acwing.com/activity/content/code/content/3964010/
��Դ��AcWing
����Ȩ���������С���ҵת������ϵ���߻����Ȩ������ҵת����ע��������