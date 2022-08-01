#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;


const int N = 1e+5 + 10, M = 2e+5 + 10;
int p[N];
int n, m;
int find(int x) {
    if (p[x] != x) p[x] = find(p[x]);
    return p[x]; //这里一定返回的是祖宗节点，要不递归回来就不对了。。
}
struct Edge {
    int a, b, w;
    bool operator<(const Edge& W) {
        return w < W.w;
    }
}edge[M];

int main() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w; //忘记输入导致segmentation错误！！
        edge[i] = { u,v,w }; //结构体可以这么赋值 
        // edge[i].a = u;
        // edge[i].b = v;    
        // edge[i].w = w;
    }
    sort(edge, edge + m); //普通数组用sort是这么用的！！

    for (int i = 1; i <= n; i++)
        p[i] = i;
    int res = 0, cnt = 0;
    for (int i = 0; i < m; i++) {
        int a = edge[i].a, b = edge[i].b, w = edge[i].w;
        a = find(a), b = find(b);
        if (a != b) {
            p[a] = b;
            cnt++;
            res += w;
        }
    }

    if (cnt < n - 1) cout << "impossible" << endl; //这里是用点来判断 而不是边！
    else cout << res;

    return 0;
}

作者：啥也不会的小白菜
链接：https ://www.acwing.com/activity/content/code/content/3964253/
来源：AcWing
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。