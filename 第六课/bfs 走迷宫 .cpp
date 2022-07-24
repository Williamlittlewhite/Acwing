#include<iostream>
#include<cstring>
#include<queue>
#include<cstdio>
using namespace std;
const int N = 110;
int g[N][N], d[N][N];

queue<pair<int, int>> q;
int dx[4] = { 0,-1,0,1 }, dy[4] = { 1,0,-1,0 };
int n, m;
int bfs() {
    memset(d, -1, sizeof d);
    q.push({ 0,0 });
    d[0][0] = 0;
    while (!q.empty())
    {
        auto t = q.front();
        q.pop();

        for (int k = 0; k < 4; k++)
        {
            int x = t.first + dx[k], y = t.second + dy[k];
            // cout<<x<<' '<<y<<endl;
            if (x >= 0 && x < n && y >= 0 && y < m && g[x][y] == 0 && d[x][y] == -1)
                //注意y<m && d[x][y]==-1要保证该路径没有被走过求最短距离
            {
                d[x][y] = d[t.first][t.second] + 1;
                // cout << d[0][1];
                q.push({ x,y });
            }

        }
    }
    return d[n - 1][m - 1];
}

int main() {
    scanf("%d%d", &n, &m);  //scanf这里输入格式有问题debug了半天 气死自己了
    // cout<<n<<m;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> g[i][j];
    // for(int i=0;i<n;i++)
    //     for(int j=0;j<m;j++)
    //         cout<<g[i][j];    
    cout << bfs() << endl;

    return 0;
}


作者：啥也不会的小白菜
链接：https ://www.acwing.com/activity/content/code/content/3902740/
来源：AcWing
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。