#include<iostream>
#include<cstring>
using namespace std;
const int N = 1e+5 + 10, M = 2e+5 + 10;
int h[N], e[M], ne[M], idx; //注意无向图要开2倍才够用！！
int color[N];
int n, m;
void add(int x, int y) {
    e[idx] = y;
    ne[idx] = h[x];
    h[x] = idx++;
}
//如何染以u为节点c为颜色的图
bool dfs(int u, int c)
{
    color[u] = c;
    for (int i = h[u]; i != -1; i = ne[i]) {
        int j = e[i];
        if (color[j] == -1) {
            if (!dfs(j, !c)) return false;
        }
        else if (color[j] == c)
            return false;
    }
    return true;
}
//染的具体过程在这
bool check() {
    memset(color, -1, sizeof color);
    bool flag = true;
    for (int i = 1; i <= n; i++) {
        if (color[i] == -1) {
            if (!dfs(i, 1)) {  //这里1和0都可以的！
                flag = false;
                break;
            }
        }
    }
    return flag;
}

int main() {
    cin >> n >> m;
    memset(h, -1, sizeof h); //记得初始化领接表！
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        add(u, v);
        add(v, u);
    }
    if (check()) cout << "Yes" << endl;
    else cout << "No";

    return 0;
}

作者：啥也不会的小白菜
链接：https ://www.acwing.com/activity/content/code/content/3964499/
来源：AcWing
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。