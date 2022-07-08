#include<iostream>
using namespace std;
const int N = 1e+5 + 10;
int a[N], b[N];
void insert(int& l, int& r, int& c)   //核心操作：把遍历中间所有元素加一个数，修改为差分数组加边界数，最后通过                                    //再次构造前缀和 更新满足条件的前缀和数组
{
    b[l] += c;
    b[r + 1] -= c;
}
int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 1;i <= n;i++)
        scanf("%d", &a[i]);   //逐个插入方法构造差分数组 避免数学意义上的构造

    for (int i = 1;i <= n;i++)
        insert(i, i, a[i]);

    for (int i = 1;i <= m;i++)
    {
        int l, r, c;
        scanf("%d%d%d", &l, &r, &c);
        insert(l, r, c);
    }

    for (int i = 1;i <= n;i++)
        a[i] = a[i - 1] + b[i];

    for (int i = 1;i <= n;i++)
        printf("%d ", a[i]);  //注意输出格式

    return 0;
}

作者：啥也不会的小白菜
链接：https ://www.acwing.com/activity/content/code/content/3747394/
来源：AcWing
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。