#include<iostream>
#include<cstring>
const int M = 1e+5 + 10, N = 510;
using namespace std;
int n, m, k;
struct edge {
    int a, b, w;
}edges[M];
int backup[N], dis[N];
bool Bellmanford() {
    memset(dis, 0x3f, sizeof dis);  //别忘记初始化
    dis[1] = 0;

    for (int i = 0; i < k; i++) {
        memcpy(backup, dis, sizeof dis);
        for (int j = 0; j < m; j++)
        {
            int a = edges[j].a, b = edges[j].b, w = edges[j].w;
            if (dis[b] > backup[a] + w)  //注意这里是小于才更新 debug了半天
                dis[b] = backup[a] + w;
        }
    }

    if (dis[n] >= 0x3f3f3f3f / 2)
        return false;
    return true;
}


int main() {
    cin >> n >> m >> k;
    for (int i = 0; i < m; i++) {
        int x, y, z;
        cin >> x >> y >> z;
        edges[i].a = x;
        edges[i].b = y;
        edges[i].w = z;
    }
    if (!Bellmanford()) cout << "impossible" << endl;
    else cout << dis[n];
    return 0;
}