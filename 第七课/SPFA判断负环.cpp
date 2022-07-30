#include<iostream>
#include<cstring>
#include<queue>
using namespace std;
const int N = 1e+5 + 10;
bool st[N];
int h[N], e[N], w[N], ne[N], idx, dist[N], cnt[N];
int n, m;

void add(int x, int y, int z) {
    e[idx] = y;
    w[idx] = z;
    ne[idx] = h[x];
    h[x] = idx;
    idx++;
}

bool SPFA() {
    memset(dist, 0x3f, sizeof dist);
    dist[1] = 0;

    queue<int> q;
    for (int i = 1; i <= n; i++)
    {
        q.push(i);
        st[i] = true;
    }

    while (q.size())
    {
        auto t = q.front();
        q.pop();

        st[t] = false;

        for (int i = h[t]; i != -1; i = ne[i])
        {
            int j = e[i];
            if (dist[j] > dist[t] + w[i])
            {
                dist[j] = dist[t] + w[i];
                cnt[j] = cnt[t] + 1;

                if (cnt[j] >= n) return true;

                if (!st[j])
                {
                    q.push(j);
                    st[j] = true;
                }

            }
        }
    }

    return false;

}




int main() {
    cin >> n >> m;
    memset(h, -1, sizeof h);
    while (m--)
    {
        int x, y, z;
        cin >> x >> y >> z;
        // cout<<x << " "<<y << " " << z<<endl;
        add(x, y, z);
    }
    if (SPFA()) cout << "Yes";  //注意函数调试带括号！！笨蛋我就是！！
    else cout << "No";
    return 0;
}