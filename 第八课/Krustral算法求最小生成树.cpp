#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;


const int N = 1e+5 + 10, M = 2e+5 + 10;
int p[N];
int n, m;
int find(int x) {
    if (p[x] != x) p[x] = find(p[x]);
    return p[x]; //����һ�����ص������ڽڵ㣬Ҫ���ݹ�����Ͳ����ˡ���
}
struct Edge {
    int a, b, w;
    bool operator<(const Edge& W) {
        return w < W.w;
    }
}edge[M];

int main() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w; //�������뵼��segmentation���󣡣�
        edge[i] = { u,v,w }; //�ṹ�������ô��ֵ 
        // edge[i].a = u;
        // edge[i].b = v;    
        // edge[i].w = w;
    }
    sort(edge, edge + m); //��ͨ������sort����ô�õģ���

    for (int i = 1; i <= n; i++)
        p[i] = i;
    int res = 0, cnt = 0;
    for (int i = 0; i < m; i++) {
        int a = edge[i].a, b = edge[i].b, w = edge[i].w;
        a = find(a), b = find(b);
        if (a != b) {
            p[a] = b;
            cnt++;
            res += w;
        }
    }

    if (cnt < n - 1) cout << "impossible" << endl; //�������õ����ж� �����Ǳߣ�
    else cout << res;

    return 0;
}

���ߣ�ɶҲ�����С�ײ�
���ӣ�https ://www.acwing.com/activity/content/code/content/3964253/
��Դ��AcWing
����Ȩ���������С���ҵת������ϵ���߻����Ȩ������ҵת����ע��������