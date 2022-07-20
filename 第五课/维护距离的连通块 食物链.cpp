#include<iostream>
using namespace std;
const int n = 5e+4 + 10;
int p[n], d[n];
int find(int x) {
    if (p[x] != x) {
        int u = find(p[x]);
        d[x] += d[p[x]];           //这里的写法是用到了递归此时p[x]已经维护成了到根节点的距离 d[x]此时还是1
                                //还没有维护 因此可以这么写
        p[x] = u;
    }
    return p[x];
}
int main()
{
    int N, K;
    scanf("%d%d", &N, &K);
    for (int i = 0;i < N;i++)
        p[i] = i;
    int res = 0;
    while (K--) {
        int D, X, Y;
        scanf("%d%d%d", &D, &X, &Y);
        if (X > N || Y > N)    res++;
        else {
            int px = find(X), py = find(Y);
            if (D == 1) {
                if (px == py && (d[X] - d[Y]) % 3) res++;  //牢记下层吃上层的规定  同类即同层 用距离长度表示层数
                else if (px != py)
                {
                    p[px] = py;
                    d[px] = d[Y] - d[X];
                }
            }
            else {
                if (px == py && (d[X] - d[Y] - 1) % 3) res++;      //这里的写法可以画个图想象一下即可，
                //牢记下层吃上层的规定
                else if (px != py) {
                    p[px] = py;
                    d[px] = d[Y] + 1 - d[X];
                }
            }

        }
    }
    printf("%d", res);
}

作者：啥也不会的小白菜
链接：https ://www.acwing.com/activity/content/code/content/3856186/
来源：AcWing
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。