#include<iostream>
#include<cstring>
using namespace std;
const int N = 1e+5 + 10;
bool st[N];
int ans = N;
int n;
int h[N], e[2 * N], ne[2 * N], idx;
void add(int a, int b) {
    e[idx] = b;
    ne[idx] = h[a];
    h[a] = idx;
    idx++;
}
//以u为根子树中点的数量  这个是关键
int dfs(int u) {
    st[u] = true;                 //一定要把父节点打上标记 否则由于无向树很有可能陷入无限递归
    int sum = 1;
    int res = 0;
    for (int i = h[u]; i != -1; i = ne[i])   //遍历u的所有子节点的树的点的数量
    {
        int j = e[i];
        if (!st[j])
        {
            int s = dfs(j);
            res = max(s, res);          //res记录u的所有子树的最大的节点数目
            sum += s;                 //sum记录u的所有子树一共的节点数目
        }
    }
    res = max(res, n - sum);
    // cout<<res<<endl;
    ans = min(ans, res);              //记录重心删去各个连通块最大的数目
    return sum;
}


int main()
{
    scanf("%d", &n);
    memset(h, -1, sizeof h);

    for (int i = 0; i < n - 1; i++)   //这里输入n-1条边是个大坑
    {
        int a, b;
        cin >> a >> b;
        add(a, b);
        add(b, a);
    }
    dfs(1);
    cout << ans;
    return 0;
}

作者：啥也不会的小白菜
链接：https ://www.acwing.com/activity/content/code/content/3905131/
来源：AcWing
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。