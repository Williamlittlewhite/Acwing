#include<iostream>
#include<cstdio>
using namespace std;
const int N = 1e+5 + 10;
int e[N], l[N], r[N], idx;
void init()
{
    idx = 2;
    l[1] = 0;
    r[0] = 1;
}
void add_tohead(int x) {
    e[idx] = x;
    r[idx] = r[0];
    l[idx] = 0;
    l[r[0]] = idx;
    r[0] = idx;
    idx++;
}
void add_totail(int x) {
    e[idx] = x;
    r[idx] = 1;
    l[idx] = l[1];
    r[l[1]] = idx;
    l[1] = idx;
    idx++;
}
void remove(int k) {
    r[l[k]] = r[k];
    l[r[k]] = l[k];
}
void insert(int k, int c)
{
    e[idx] = c;
    l[idx] = k;
    r[idx] = r[k];
    l[r[k]] = idx;
    r[k] = idx;
    idx++;
}

int main() {
    init();
    int M;
    scanf("%d", &M);
    while (M--) {
        char str[4];                     //char会读到一些换行字符  用%s的读法可以取消换行和空格
        scanf("%s", str);
        if (str[0] == 'L') {
            int temp;
            scanf("%d", &temp);
            // printf("%d",temp);
            add_tohead(temp);
        }
        else if (str[0] == 'R') {
            int temp;
            scanf("%d", &temp);
            // printf("%d",temp);
            add_totail(temp);
        }
        else if (str[0] == 'D') {
            int temp;
            scanf("%d", &temp);
            // printf("%d",temp);               //双链表的第k个节点对应的索引是k+1 这种写法下       idx从2开始
            remove(temp + 1);                     //单链表的第k个节点对应的索引是k-1 head=-1的写法下  idx从0开始
        }
        else if (str[0] == 'I' && str[1] == 'L') {
            int temp1, temp2;
            scanf("%d%d", &temp1, &temp2);
            // printf("%d",temp);
            insert(l[temp1 + 1], temp2);
        }
        else if (str[0] == 'I' && str[1] == 'R') {
            int temp1, temp2;
            scanf("%d%d", &temp1, &temp2);
            // printf("%d",temp);
            insert(temp1 + 1, temp2);
        }

    }

    for (int i = r[0];i != 1;i = r[i])
        printf("%d ", e[i]);


    return 0;
}

作者：啥也不会的小白菜
链接：https ://www.acwing.com/activity/content/code/content/3809076/
来源：AcWing
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。