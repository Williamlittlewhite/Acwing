// #include<iostream>
// using namespace std;
// const int N = 10;
// bool col[N],dg[2*N],udg[2*N];
// char path[N][N];
// int n;
// void dfs(int u){                     //这个题是按照深度优先遍历规则进行遍历
//     if(u==n)                        //u=0,1,...,n-1表示对第n行选择皇后
//         {
//             for(int i=0;i<n;i++)
//                 puts(path[i]);
//             puts("");
//             return;
//         }
//     else{
//         for(int i=0;i<n;i++)
//         {
//             if(!col[i]&&!dg[u+i]&&!udg[n+u-i])   //这里u+i 与n+u-i是映射对角线的方法
//             //记得数组开到2N
//                 {
//                 path[u][i]='Q';
//                 col[i] = true;
//                 dg[u+i] = true;
//                 udg[n+u-i] = true;
//                 dfs(u+1);
//                 col[i] = false;
//                 dg[u+i] = false;
//                 udg[n+u-i] = false;
//                 path[u][i] = '.';  //记得恢复现场 debug！
//                 }
//         }
//     }
// }
// int main(){
//     cin >> n;
//     for(int i=0;i<n;i++)
//         for(int j=0;j<n;j++)
//             path[i][j] = '.';   //不能初始化全为.必须这样初始化记住！debug！
//     dfs(0);
//     return 0;
// }
#include<iostream>
using namespace std;
const int N = 10;
int n;
bool col[N], row[N], dg[2 * N], udg[2 * N];
char g[N][N];
void dfs(int x, int y, int s) {      //这个是按格子遍历的 x代表行从上到下 y代表列从左到右
    if (y == n) x += 1, y = 0;
    if (x == n)
    {
        if (s == n)
        {
            for (int i = 0; i < n; i++)
                puts(g[i]);
            puts("");
        }
        return;                 //递归出口 第一次dfs使得所有数组变成.  第二次dfs放皇后
    }
    g[x][y] = '.';
    dfs(x, y + 1, s);

    if (!row[x] && !col[y] && !dg[x + y] && !udg[n + x - y])
    {
        g[x][y] = 'Q';
        row[x] = col[y] = dg[x + y] = udg[n + x - y] = true;
        dfs(x, y + 1, s + 1);                                  //回复现场和正规的dfs
        row[x] = col[y] = dg[x + y] = udg[n + x - y] = false;
        g[x][y] = '.';
    }
}
int main()
{
    cin >> n;
    dfs(0, 0, 0);
    return 0;
}
