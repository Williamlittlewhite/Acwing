#include<iostream>
using namespace std;
const int N = 1010;
int a[N][N], s[N][N];
int main() {

    int n, m, q;
    scanf("%d%d%d", &n, &m, &q);
    for (int i = 1;i <= n;i++)
        for (int j = 1; j <= m;j++)
            scanf("%d", &a[i][j]);

    for (int i = 1;i <= n;i++)
        for (int j = 1; j <= m;j++)
            s[i][j] = s[i][j - 1] + s[i - 1][j] - s[i - 1][j - 1] + a[i][j];   //脑海里想图清晰化即可

    int x1, y1, x2, y2;
    for (int i = 1;i <= q;i++)
    {
        scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
        printf("%d\n", s[x2][y2] - s[x2][y1 - 1] - s[x1 - 1][y2] + s[x1 - 1][y1 - 1]);  //脑海里想图自然清晰
    }
    return 0;

}

//作者：啥也不会的小白菜
//链接：https ://www.acwing.com/activity/content/code/content/3747034/
//来源：AcWing
//著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。