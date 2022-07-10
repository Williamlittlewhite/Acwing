#include<iostream>
using namespace std;
const int N = 1e+5 + 10;
int A[N], B[N];
int main() {
    int n, m, x;
    scanf("%d%d%d", &n, &m, &x);
    for (int i = 0;i < n;i++)
        scanf("%d", &A[i]);
    for (int i = 0;i < m;i++)
        scanf("%d", &B[i]);

    for (int i = 0, j = m - 1;i < n;i++)
    {
        while (j >= 0 && A[i] + B[j] > x)j--;  //判断条件的核心在于双指针一个从左往右遍历 另外一个从右往左遍历不回头
         //如果找到的和小于x那么说明此次遍历找不到，增加i后，j只能左移，右移会导致更不满足条件，由此确定双指针写法

        if (A[i] + B[j] == x)
            printf("%d %d", i, j);
    }
    return 0;
}

作者：啥也不会的小白菜
链接：https ://www.acwing.com/activity/content/code/content/3780515/
来源：AcWing
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。