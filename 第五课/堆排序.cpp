#include<iostream>
using namespace std;
const int N = 1e+5 + 10;
int h[N], cnt;
void up(int x) {
    while (x / 2 && h[x / 2] > h[x])
    {
        swap(h[x], h[x / 2]);
        x >>= 1;             //�ǵø���x
    }
}
void down(int x) {
    int t = x;
    if (2 * x <= cnt && h[2 * x] < h[t]) t = 2 * x;  //��������if�ж�  ����һ����С�ڵ��ڲſ��ԣ���Ϊcnt��ֵ
    if (2 * x + 1 <= cnt && h[2 * x + 1] < h[t]) t = 2 * x + 1;
    if (t != x)                                    //����t!=x���Ǳ�ʾ�����ڱȸ��ڵ�С�Ķ���
    {
        swap(h[x], h[t]);
        down(t);                        //�����ݹ����downֱ������downΪֹ
    }
}
int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 1;i <= n;i++)
        scanf("%d", &h[i]);  //�����鸳ֵҲҪ��%d
    cnt = n;
    for (int i = n / 2;i >= 1;i--)
        down(i);

    while (m--) {
        printf("%d ", h[1]);       //�Ѷ���Ĭ����Сֵ����pop��Сֵʱ�������һ��Ԫ��ֵ�滻��Сֵ
        //Ȼ��ɾ�����һ���ڵ� Ȼ������down�Ѷ�  �Ϳ���һֱ�����ҵ��ѵ���Сֵ
        swap(h[1], h[cnt]);
        // h[1] = h[cnt];
        cnt--;
        down(1);

    }
    return 0;
}

���ߣ�ɶҲ�����С�ײ�
���ӣ�https ://www.acwing.com/activity/content/code/content/3856184/
��Դ��AcWing
����Ȩ���������С���ҵת������ϵ���߻����Ȩ������ҵת����ע��������