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
            if (!st[j] && (t == -1 || d[j] < d[t]))         //t表示不在S集合里面的最短距离的一个点
                t = j;

        for (int j = 1; j <= n; j++)
            d[j] = min(d[j], d[t] + g[t][j]);//这里是用最近点更新其余点的距离

        st[t] = true;  //一定要记得标记已经找到了该点最佳距离于集合S中
    }
    if (d[n] == 0x3f3f3f3f) return -1;
    return d[n];
}
int main() {
    cin >> n >> m;
    memset(g, 0x3f, sizeof g);//把领接矩阵全初始化为最大距离表示不连接
    while (m--) {
        int x, y, z;
        cin >> x >> y >> z;
        // g[x][y] = z;
        g[x][y] = min(g[x][y], z);//处理重边的情况，保证最小距离即可
    }
    cout << dijkstra() << endl;
    return 0;
}

作者：啥也不会的小白菜
链接：https ://www.acwing.com/activity/content/code/content/3928984/
来源：AcWing
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。