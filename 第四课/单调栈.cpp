#include<iostream>
#include<cstdio>
using namespace std;
const int M = 1e+5 + 10;
int stk[M], a[M];
int tt = 0;
int main() {
    int N;
    scanf("%d", &N);
    for (int i = 0;i < N;i++) {
        scanf("%d", &a[i]);
    }
    for (int i = 0, j = 0;i < N;i++)
    {
        while (tt && stk[tt] >= a[i])tt--;    //维持栈中的元素一定是单调递增的，并且小于a[i]的，
                                         //因为如果如果中间有数比其右边界更大，那么该数无用 因为取的是最小的a[i]
        if (tt == 0) cout << -1 << ' ';         //一定是先进行输出的判断 然后再入栈 因为求的是某数之前的最小数
        else printf("%d ", stk[tt]);
        stk[++tt] = a[i];
    }


    return 0;
}

作者：啥也不会的小白菜
链接：https ://www.acwing.com/activity/content/code/content/3842152/
来源：AcWing
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。