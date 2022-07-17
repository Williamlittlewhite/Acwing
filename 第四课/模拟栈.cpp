#include<cstdio>
#include<iostream>
#include<string.h>
using namespace std;
const int N = 1e+6 + 10;
int stk[N];
int tt = 0;
int main() {
    int M;
    scanf("%d", &M);
    while (M--) {
        char op[5];
        scanf("%s", op);   //记住读入操作的操作
        if (!strcmp(op, "push")) { //strcmp是当两个字符串相等的时候返回0  str1<str2 返回负数 str1>str2 返回正数
            int temp;
            scanf("%d", &temp);
            stk[++tt] = temp;
        }
        else if (!strcmp(op, "pop")) {
            tt--;
        }
        else if (!strcmp(op, "empty")) {
            if (tt > 0) printf("NO\n");
            else printf("YES\n");
        }
        else if (!strcmp(op, "query")) {
            printf("%d\n", stk[tt]);
        }

    }

    return 0;
}

作者：啥也不会的小白菜
链接：https ://www.acwing.com/activity/content/code/content/3828019/
来源：AcWing
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。