#include<iostream>
using namespace std;
const int N = 1e+5 + 10;
int p[N], Size[N];
int find(int x)
{
    if (p[x] != x)
        p[x] = find(p[x]);
    return p[x];
}
int main() {
    int n, m;
    scanf("%d%d", &n, &m);

    for (int i = 1;i <= n;i++) {
        p[i] = i;
        Size[i] = 1;
    }
    while (m--) {
        char op[2];
        int a, b;
        scanf("%s", op);
        if (op[0] == 'C') {
            scanf("%d%d", &a, &b);
            if (find(a) != find(b)) {
                // p[find(a)]=find(b);     //这里一定是根节点的父子关系
                // Size[find(b)]+=Size[find(a)]; //这里一定要赋值之后再写因为我这么写，已经把a的祖宗变了 
                //所以出错 调换顺序就可以AC了
                Size[find(b)] += Size[find(a)];
                p[find(a)] = find(b);
            }
        }
        else if (op[0] == 'Q' && op[1] == '1') {
            scanf("%d%d", &a, &b);
            if (a == b) printf("Yes\n");
            else if (find(a) != find(b))printf("No\n");
            else printf("Yes\n");
        }
        else if (op[0] == 'Q' && op[1] == '2') {
            scanf("%d", &a);
            printf("%d\n", Size[find(a)]);   //这里一定要找到根节点返回值
        }

    }


    return 0;
}

作者：啥也不会的小白菜
链接：https ://www.acwing.com/activity/content/code/content/3854913/
来源：AcWing
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。