#include<iostream>
using namespace std;
const int N = 1e+5 + 10;
int idx, head, e[N], ne[N];
void init()
{
    head = -1;
    idx = 0;
}
void InsertHead(int c) {
    e[idx] = c;
    // ne[head] = idx; //这里head始终指向头结点
    ne[idx] = head;
    head = idx;
    idx++;   //记得idx要更新
}

void Delete(int k) {
    ne[k] = ne[ne[k]];
}

void Insert(int k, int c) {
    e[idx] = c;
    ne[idx] = ne[k];
    ne[k] = idx;
    idx++;
}

int main()
{
    init();
    int M;
    char c;
    int k, k1;
    scanf("%d", &M);
    while (M--)
    {
        cin >> c;//scanf读字符会把前面换行读入，所以采用cin！，debug出处理输入的问题
        // printf("%c",c);
        if (c == 'H') {
            scanf("%d", &k);
            // printf("%d",k);
            InsertHead(k);
        }
        else if (c == 'I') { scanf("%d%d", &k, &k1); Insert(k - 1, k1); }
        else if (c == 'D') {
            scanf("%d", &k);
            if (k == 0) head = ne[head];  //注意这里要有特判
            Delete(k - 1);
        }
    }
    for (int i = head;i != -1;i = ne[i])   //注意链表的结尾实际上由-1掌控
        printf("%d ", e[i]);
    return 0;
}

