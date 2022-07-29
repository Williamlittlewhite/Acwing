#include<iostream>
#include<cstring>
#include<queue>
using namespace std;
typedef pair<int, int> PII;
int n, m;
const int N = 1e+6 + 10;
int idx, h[N], e[N], ne[N], w[N], d[N];
bool st[N];
void add(int a, int b, int c) {
    e[idx] = b;
    w[idx] = c;
    ne[idx] = h[a];
    h[a] = idx;
    idx++;
}

int dijkstra() {
    memset(d, 0x3f, sizeof d);
    d[1] = 0;
    priority_queue<PII, vector<PII>, greater<PII>> q;
    q.push({ 0,1 });
    while (q.size()) {
        auto t = q.top();             //找到当前已经在S集合里的最近的点
        q.pop();

        int ver = t.second, distance = t.first;

        if (st[ver]) continue;
        st[ver] = true;

        for (int i = h[ver]; i != -1; i = ne[i]) {//更新其余相邻点的距离！
            int j = e[i];
            if (d[j] > d[ver] + w[i])
            {
                d[j] = d[ver] + w[i];
                q.push({ d[j],j });
            }
        }
    }

    if (d[n] == 0x3f3f3f3f) return -1;     //记得这个放在外层 debug了半天
    return d[n];
}


int main() {

    cin >> n >> m;
    memset(h, -1, sizeof h);
    while (m--) {
        int x, y, z;
        cin >> x >> y >> z;
        add(x, y, z);
    }
    cout << dijkstra() << endl;
    return 0;
}


作者：啥也不会的小白菜
链接：https ://www.acwing.com/activity/content/code/content/3929349/
来源：AcWing
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。