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
    if (2 * x <= cnt && h[2 * x] < h[t]) t = 2 * x;   //ע��up��down�Ĳ��������±꣡
    if (2 * x + 1 <= cnt && h[2 * x + 1] < h[t]) t = 2 * x + 1;   //ע���жϵ�һ����h[t]��h[2*x]/h[2*x+1]!debug�˰���
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
        scanf("%s", op);//�ַ������벻��ȡ��ַ
        if (op[0] == 'I') {  //�������ڶ����������� Ȼ���ϸ� Ȼ��ά���ѵĸ���Ԫ�ؼ���
            int temp;
            scanf("%d", &temp);
            h[++cnt] = temp;
            ph[++m] = cnt;    //�ǵ�ά��hp��ph����
            hp[cnt] = m;
            up(cnt);
        }
        else if (op[0] == 'P' && op[1] == 'M') {
            printf("%d\n", h[1]);
        }
        else if (!strcmp(op, "DM")) {
            heap_swap(1, cnt); //����Ҫ�������swap����ǵ�
            cnt--;
            down(1);
        }
        else if (!strcmp(op, "D")) {  //scanf("%s")���Զ����������ַ�������ĩβ���Ͻ�����
            int temp;
            scanf("%d", &temp);
            temp = ph[temp];
            // heap_swap(ph[temp],cnt);//��������ph���飬��˲�����ôд
            heap_swap(temp, cnt);
            cnt--;
            up(temp);
            down(temp);
        }
        else if (!strcmp(op, "C")) {
            int temp1, temp2;
            scanf("%d%d", &temp1, &temp2);  //һ��ȡ��ַ debug�˰���
            temp1 = ph[temp1];
            h[temp1] = temp2;
            up(temp1);
            down(temp1);

        }
    }

    return 0;
}

���ߣ�ɶҲ�����С�ײ�
���ӣ�https ://www.acwing.com/activity/content/code/content/3865687/
��Դ��AcWing
����Ȩ���������С���ҵת������ϵ���߻����Ȩ������ҵת����ע��������