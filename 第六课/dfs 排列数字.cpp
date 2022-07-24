#include<iostream>
using namespace std;
const int N = 7;
bool st[N];
int n;
int path[N];
void dfs(int u) {
    if (u == n)
    {     //dfs必须有递归终止条件！
        for (int i = 0; i < n; i++)
            cout << path[i] << ' ';
        cout << endl;
        return;
    }

    else {   //当u=0,1,2代表给各个位置进行安排数组
        for (int j = 1; j <= n; j++)   //恢复现场不会重复的原因是j一定会++
            if (!st[j])           //如果该数没有被用过，则用该数构成路径
            {
                path[u] = j;
                st[j] = true;
                dfs(u + 1);       //继续深度优先遍历！
                st[j] = false; //恢复现场，因为此时这里的路径已经走完了 
                //为了回溯现场必须如此！
                path[u] = 0;
            }
    }
}
int main()
{
    scanf("%d", &n);

    dfs(0);
    return 0;
}

作者：啥也不会的小白菜
链接：https ://www.acwing.com/activity/content/code/content/3893198/
来源：AcWing
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。