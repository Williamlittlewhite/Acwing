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
                t = j; //这里是赋值 debug了半天
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
    memset(g, 0x3f, sizeof g); //记得矩阵距离也得初始化成无穷
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        g[u][v] = g[v][u] = min(g[u][v], w); //记得处理重边
    }
    int t = prim();
    if (t > 0x3f3f3f3f / 2)  //有负权边记得这么判断！！
        cout << "impossible" << endl;
    else
        cout << t << endl;
}

作者：啥也不会的小白菜
链接：https ://www.acwing.com/activity/content/code/content/3964010/
来源：AcWing
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。