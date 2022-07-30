#include<iostream>
#include<cstring>
#include<queue>
using namespace std;
int n, m;
const int N = 1e+5 + 10;
int dis[N], h[N], e[N], ne[N], w[N], idx;
bool st[N]; //一定要定义成bool数组！！！
void add(int x, int y, int z) {
    e[idx] = y;
    w[idx] = z;
    ne[idx] = h[x];
    h[x] = idx;
    idx++;
}

int SPFA() {  //注意返回值！！
    memset(dis, 0x3f, sizeof dis);//注意初始化 又忘了
    dis[1] = 0;

    queue<int> q;
    q.push(1);
    st[1] = true; //注意用一个数组保存是否入队的情况

    while (q.size()) {
        auto t = q.front();
        q.pop();

        st[t] = false;

        for (int i = h[t]; i != -1; i = ne[i])
        {
            int j = e[i];
            if (dis[j] > dis[t] + w[i])
            {
                dis[j] = dis[t] + w[i];
                if (!st[j])
                {
                    q.push(j);
                    st[j] = true;
                }
            }
        }
    }

    return dis[n];

}

int main()
{
    // int n,m;//不要重复定义 debug了半天！！！
    cin >> n >> m;
    memset(h, -1, sizeof h);
    while (m--) {
        int x, y, z;
        cin >> x >> y >> z;
        // cout << x << y << z;
        add(x, y, z);
    }
    int t = SPFA();
    if (t == 0x3f3f3f3f) cout << "impossible" << endl;
    else cout << t;

    return 0;
}

