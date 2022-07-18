#include<iostream>
using namespace std;
const int N = 1e+6 + 10;
int q[N], hh = 0, tt = -1;
int temp[N];
int main() {
    int n, k;
    scanf("%d%d", &n, &k);
    for (int i = 0;i < n;i++) {
        scanf("%d", &temp[i]);
    }
    for (int i = 0;i < n;i++) {
        while (tt >= hh && q[hh] < i - k + 1) hh++; //滑动窗口的左边位置移动到当前数组的遍历首元素
        while (tt >= hh && temp[q[tt]] >= temp[i])tt--;//维持滑动窗口是单调递增的,队列存储的元素是下标
        q[++tt] = i;
        if (i >= k - 1)                //如果滑动窗口不要求从第三个开始 那么取消这里的特判条件即可
            printf("%d ", temp[q[hh]]);
    }
    printf("\n");
    hh = 0;tt = -1;
    for (int i = 0;i < n;i++)                    //i表示当前数的起始位置
    {
        while (tt >= hh && q[hh] < i - k + 1)hh++;    //滑动窗口左边移动到当前数的位置
        while (tt >= hh && temp[q[tt]] <= temp[i])tt--; //维持队列中的索引对应的值是单调递减的
        q[++tt] = i;
        if (i >= k - 1)
            printf("%d ", temp[q[hh]]);    //对首元素就永远是当前的最大值
    }
    return 0;
}

作者：啥也不会的小白菜
链接：https ://www.acwing.com/activity/content/code/content/3842322/
来源：AcWing
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。