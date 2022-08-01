#include<iostream>
#include<cstring>
using namespace std;
int n1, n2, m;
const int N = 510, M = 1e+5 + 10;
int h[N], e[M], ne[M], match[N], idx;  //注意e和ne矩阵由边确定范围
bool st[N];
void add(int x, int y) {
    e[idx] = y;
    ne[idx] = h[x];
    h[x] = idx++;
}

bool find(int x) {
    for (int i = h[x]; i != -1; i = ne[i]) {
        int j = e[i];
        if (!st[j])
        {
            st[j] = true;
            if (match[j] == 0 || find(match[j])) {
                match[j] = x;
                return true;
            }
        }
    }
    return false;
}
int main() {
    cin >> n1 >> n2 >> m;
    memset(h, -1, sizeof h);//加边之前进行初始化
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        add(u, v);
    }

    int res = 0;
    for (int i = 1; i <= n1; i++) {
        memset(st, false, sizeof st);  //每个点匹配要更新一次st数组方便进行匹配！
        if (find(i)) res++;
    }

    cout << res << endl;
    return 0;
}

作者：啥也不会的小白菜
链接：https ://www.acwing.com/activity/content/code/content/3966845/
来源：AcWing
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。