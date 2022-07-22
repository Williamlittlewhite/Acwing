#include<iostream>
#include<string.h>

using namespace std;

const int N = 100010;

int h[N], hp[N], ph[N], cnt;

void heap_swap(int x, int y) {
    swap(ph[hp[x]], ph[hp[y]]);
    swap(hp[x], hp[y]);
    swap(h[x], h[y]);
}

void up(int x) {
    while (x / 2 && h[x / 2] > h[x])
    {
        heap_swap(x, x / 2);
        x >>= 1;
    }
}

void down(int x) {
    int t = x;
    if (2 * x <= cnt && h[2 * x] < h[t]) t = 2 * x;   //注意up和down的参数都是下标！
    if (2 * x + 1 <= cnt && h[2 * x + 1] < h[t]) t = 2 * x + 1;   //注意判断的一定是h[t]与h[2*x]/h[2*x+1]!debug了半天
    if (t != x) {
        heap_swap(t, x);
        down(t);
    }
}

int main() {
    int N, m = 0;
    scanf("%d", &N);
    cnt = 0;
    while (N--) {
        char op[3];
        scanf("%s", op);//字符串输入不用取地址
        if (op[0] == 'I') {  //插入是在堆最后插入数组 然后上浮 然后维护堆的各个元素即可
            int temp;
            scanf("%d", &temp);
            h[++cnt] = temp;
            ph[++m] = cnt;    //记得维护hp和ph数组
            hp[cnt] = m;
            up(cnt);
        }
        else if (op[0] == 'P' && op[1] == 'M') {
            printf("%d\n", h[1]);
        }
        else if (!strcmp(op, "DM")) {
            heap_swap(1, cnt); //这里要用特殊的swap处理记得
            cnt--;
            down(1);
        }
        else if (!strcmp(op, "D")) {  //scanf("%s")会自动读完输入字符串并在末尾加上结束符
            int temp;
            scanf("%d", &temp);
            temp = ph[temp];
            // heap_swap(ph[temp],cnt);//这里变更了ph数组，因此不能这么写
            heap_swap(temp, cnt);
            cnt--;
            up(temp);
            down(temp);
        }
        else if (!strcmp(op, "C")) {
            int temp1, temp2;
            scanf("%d%d", &temp1, &temp2);  //一定取地址 debug了半天
            temp1 = ph[temp1];
            h[temp1] = temp2;
            up(temp1);
            down(temp1);

        }
    }

    return 0;
}

作者：啥也不会的小白菜
链接：https ://www.acwing.com/activity/content/code/content/3865687/
来源：AcWing
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。