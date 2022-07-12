#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
const int N = 1e+6 + 10;
int a[N], b[N];
int lowbit(int x) {
    x = x & (-x);
    return x; //这里居然忘记返回值了 debug了半天！！
}
int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0;i < n;i++)
        scanf("%d", &a[i]);
    for (int i = 0;i < n;i++) {
        int j = 0;
        while (a[i] != 0) { a[i] -= lowbit(a[i]);j++; }
        b[i] = j;
    }
    // printf("%d",lowbit(1));
    for (int i = 0;i < n;i++)
        printf("%d ", b[i]);
    return 0;
}

作者：啥也不会的小白菜
链接：https ://www.acwing.com/activity/content/code/content/3791668/
来源：AcWing
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。