#include<cstdio>
#include<iostream>
using namespace std;
const int n = 100010;
int son[n][26];  //第二位开26个足够了 因为最多是26或者52个的情况

int cnt[n];
int idx = 0;
void insert(char* str)
{
    int p = 0;
    for (int i = 0;str[i];i++)
    {
        int u = str[i] - 'a';
        if (son[p][u] == 0) son[p][u] = ++idx;
        p = son[p][u];
    }
    cnt[p]++;
}

int query(char* str) {
    int p = 0;
    for (int i = 0; str[i];i++)
    {
        int u = str[i] - 'a';
        if (son[p][u] == 0) return 0;
        p = son[p][u];
    }
    return cnt[p];
}
int main() {

    char op[2];
    int N;
    scanf("%d", &N);
    while (N--) {
        scanf("%s", op);
        // printf("%c",op[0]);
        if (op[0] == 'I') {
            char str[n];
            scanf("%s", str);
            insert(str);
        }
        else {
            char str[n];
            scanf("%s", str);
            printf("%d\n", query(str));
        }
    }
    return 0;
}

作者：啥也不会的小白菜
链接：https ://www.acwing.com/activity/content/code/content/3845037/
来源：AcWing
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。