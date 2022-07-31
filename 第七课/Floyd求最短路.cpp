#include<iostream>
using namespace std;
const int N = 210;
int n, m, k, idx;
int d[N][N];
const int INF = 0x3f3f3f3f;
//注意结点编号都从1开始
void floyd() {
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
            }
        }
    }
}

int main() {
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (i == j) d[i][j] = 0;
            else d[i][j] = INF;
        }
    }
    while (m--) {
        int x, y, z;
        cin >> x >> y >> z;
        d[x][y] = min(d[x][y], z);
    }

    floyd();

    while (k--) {
        int x, y;
        cin >> x >> y;
        if (d[x][y] >= INF / 2) cout << "impossible" << endl;  //注意这里的判断也是INF/2 和Bellman ford一样
        else cout << d[x][y] << endl;
    }

    return 0;
}

作者：啥也不会的小白菜
链接：https ://www.acwing.com/activity/content/code/content/3944474/
来源：AcWing
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。