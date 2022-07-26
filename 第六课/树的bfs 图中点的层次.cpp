#include<iostream>
#include<queue>
#include<cstring>
using namespace std;
const int N = 1e+5 + 10;
int d[N];
int e[N], ne[N], idx, h[N];
void add(int a, int b) {
    e[idx] = b;
    ne[idx] = h[a];
    h[a] = idx;        //注意头插结点的写法
    idx++;
}
void bfs() {
    queue<int> q;
    q.push(1);

    memset(d, -1, sizeof d);
    d[1] = 0;  //注意这两行的顺序
    while (!q.empty()) {
        auto t = q.front();
        q.pop();
        for (int i = h[t]; i != -1; i = ne[i])
        {
            int j = e[i];
            if (d[j] == -1)
            {
                q.push(j);
                d[j] = d[t] + 1;
            }
        }
    }
}
int main() {
    int n, m;
    memset(h, -1, sizeof h);//记得也要初始化链表的头节点
    scanf("%d%d", &n, &m);
    while (m--) {
        int a, b;
        scanf("%d%d", &a, &b);
        add(a, b);
    }
    bfs();
    cout << d[n];
    return 0;
}