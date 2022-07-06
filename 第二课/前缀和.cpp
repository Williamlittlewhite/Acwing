#include<iostream>
using namespace std;
const int N = 1e+5 + 10; //注意这个范围
int a[N], s[N];
int main() {
    int n, m;
    int l, r;
    scanf("%d%d", &n, &m);
    for (int i = 1;i <= n;i++)
        scanf("%d", &a[i]);
    for (int i = 1;i <= n;i++)
        s[i] = s[i - 1] + a[i];

    for (int i = 1;i <= m;i++)
    {
        scanf("%d%d", &l, &r);
        printf("%d\n", s[r] - s[l - 1]);  //注意这里
    }
}

//作者：啥也不会的小白菜
//链接：https ://www.acwing.com/activity/content/code/content/3739678/
//来源：AcWing
//著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。