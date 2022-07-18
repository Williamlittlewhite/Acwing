#include<cstdio>
#include<iostream>
using namespace std;
const int n = 1e+5 + 10;
const int m = 1e+6 + 10;
int main() {
    char p[n], s[m];
    int N;
    scanf("%d", &N);
    scanf("%s", p + 1);   //KMP模板一定是从1开始存取
    // printf("%c",p[1]);
    int M;
    scanf("%d", &M);
    scanf("%s", s + 1); //KMP模板一定是从1开始存取
    // printf("%c",s[1]);
    int ne[n];
    for (int i = 2, j = 0;i <= N;i++)
    {
        while (j && p[i] != p[j + 1])j = ne[j];
        if (p[i] == p[j + 1])j++;
        ne[i] = j;
    }
    for (int i = 1, j = 0;i <= M;i++)
    {
        while (j && s[i] != p[j + 1])j = ne[j];
        if (s[i] == p[j + 1])j++;
        if (j == N)
        {
            cout << i - N << ' ';   //输出的是起始位置的下标！
            j = ne[j];//这样做的目标是将所有子串都匹配
        }
    }

}

作者：啥也不会的小白菜
链接：https ://www.acwing.com/activity/content/code/content/3842654/
来源：AcWing
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。