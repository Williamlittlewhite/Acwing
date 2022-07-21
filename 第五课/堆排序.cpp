#include<iostream>
using namespace std;
const int N = 1e+5 + 10;
int h[N], cnt;
void up(int x) {
    while (x / 2 && h[x / 2] > h[x])
    {
        swap(h[x], h[x / 2]);
        x >>= 1;             //记得更新x
    }
}
void down(int x) {
    int t = x;
    if (2 * x <= cnt && h[2 * x] < h[t]) t = 2 * x;  //这里是用if判断  并且一定是小于等于才可以，因为cnt有值
    if (2 * x + 1 <= cnt && h[2 * x + 1] < h[t]) t = 2 * x + 1;
    if (t != x)                                    //这里t!=x就是表示还存在比根节点小的儿子
    {
        swap(h[x], h[t]);
        down(t);                        //继续递归调用down直到不能down为止
    }
}
int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 1;i <= n;i++)
        scanf("%d", &h[i]);  //给数组赋值也要加%d
    cnt = n;
    for (int i = n / 2;i >= 1;i--)
        down(i);

    while (m--) {
        printf("%d ", h[1]);       //堆顶是默认最小值，当pop最小值时候，用最后一个元素值替换最小值
        //然后删除最后一个节点 然后重新down堆顶  就可以一直往复找到堆的最小值
        swap(h[1], h[cnt]);
        // h[1] = h[cnt];
        cnt--;
        down(1);

    }
    return 0;
}

作者：啥也不会的小白菜
链接：https ://www.acwing.com/activity/content/code/content/3856184/
来源：AcWing
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。