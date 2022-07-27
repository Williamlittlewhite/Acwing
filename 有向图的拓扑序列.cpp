#include<iostream>
#include<cstring>
using namespace std;
const int N = 1e+5 + 10;
int h[N], e[N], ne[N], idx;
int d[N];
int q[N];
int n, m, hh = 0, tt = -1;
void Add(int a, int b) {
    e[idx] = b;
    ne[idx] = h[a];
    h[a] = idx;
    idx++;
}

bool topsort() {
    for (int i = 1; i <= n; i++)           //首先提取所有的入度为0的点入队
        if (!d[i])
            q[++tt] = i;
    // printf("%d",q[tt]);
    while (tt >= hh) {                      //bfs找寻不断变化的入度为0的点连成一个队列
        auto t = q[hh++];
        for (int i = h[t]; i != -1; i = ne[i])
        {
            int u = e[i];
            d[u]--;
            if (!d[u])
                q[++tt] = u;
        }
    }
    return tt == n - 1;        //当队列元素满足把所有点入过队 说明存在拓扑序列
}


int main() {

    memset(h, -1, sizeof h);
    cin >> n >> m;      //笔误了，debug了这里半天
    while (m--)
    {
        int x, y;
        cin >> x >> y;
        // cout<< x << y <<endl;
        Add(x, y);
        d[y]++;
        // cout<<d[y]<<endl;
    }

    if (!topsort()) cout << "-1" << endl;
    else
    {
        for (int i = 0; i < n; i++)
            cout << q[i] << " ";
    }
    return 0;

}



作者：啥也不会的小白菜
链接：https ://www.acwing.com/activity/content/code/content/3928605/
来源：AcWing
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。