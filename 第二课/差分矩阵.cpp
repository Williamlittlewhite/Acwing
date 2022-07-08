#include<iostream>
using namespace std;
const int N = 1010;
int a[N][N], b[N][N];
void insert(int& x1, int& y1, int& x2, int& y2, int& c) {   //脑海里画图搞懂核心操作 到右下角点
    b[x1][y1] += c;
    b[x1][y2 + 1] -= c;
    b[x2 + 1][y1] -= c;
    b[x2 + 1][y2 + 1] += c;
}
int main() {
    int n, m, q;
    scanf("%d%d%d", &n, &m, &q);

    for (int i = 1;i <= n;i++)
        for (int j = 1;j <= m;j++)
            scanf("%d", &a[i][j]);//注意这里a[i][j]别写成a[m][n]

    //  for(int i=1;i<=n;i++)
    //     {
    //         for(int j=1;j<=m;j++)
    //             cout<<a[i][j]<<" ";
    //         cout << endl;
    //     }

    for (int i = 1;i <= n;i++)
        for (int j = 1;j <= m;j++)
            insert(i, j, i, j, a[i][j]);   //注意这里a[i][j]别写成a[m][n]

    //  for(int i=1;i<=n;i++)
    //     {
    //         for(int j=1;j<=m;j++)
    //             cout<<b[i][j]<<" ";
    //         cout << endl;
    //     }

    while (q--) {
        int x1, y1, x2, y2, c;
        scanf("%d%d%d%d%d", &x1, &y1, &x2, &y2, &c);
        insert(x1, y1, x2, y2, c);
    }

    for (int i = 1;i <= n;i++)        //脑海里画图 到左上角点
        for (int j = 1;j <= m;j++)
            a[i][j] = a[i][j - 1] + a[i - 1][j] - a[i - 1][j - 1] + b[i][j];

    for (int i = 1;i <= n;i++)
    {
        for (int j = 1;j <= m;j++)
            cout << a[i][j] << " ";
        cout << endl;
    }
    return 0;
}