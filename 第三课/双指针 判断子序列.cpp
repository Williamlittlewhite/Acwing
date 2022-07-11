#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
const int N = 1e+5 + 10;
int a[N], b[N], c[N];
int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 0;i < n;i++)
        scanf("%d", &a[i]);
    for (int j = 0;j < m;j++)
        scanf("%d", &b[j]);
    int i, j;
    // while (i < n && j < m)
    // {
    //     if (a[i] == b[j]) i ++ ;
    //     j ++ ;
    // }
    for (i = 0, j = 0;i < n;i++, j++)        //死套模板是不可取的，这个题应该想到归并排序的双指针写法，y总注释参考如上
    {                           //明显y总写法更加优秀
        while (j < m && b[j] != a[i])j++;
    }

    if (j > m) printf("No");
    else printf("Yes");




    return 0;
}

作者：啥也不会的小白菜
链接：https ://www.acwing.com/activity/content/code/content/3791253/
来源：AcWing
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。