#include<iostream>
#include<cstring>
using namespace std;
const int N = 1e+5 + 10;
int h[N], e[N], ne[N], idx;
int d[N];
int q[N];
int n, m, hh = 0, tt = -1;
void Add(int a, int b) {
    e[idx] = b;
    ne[idx] = h[a];
    h[a] = idx;
    idx++;
}

bool topsort() {
    for (int i = 1; i <= n; i++)           //������ȡ���е����Ϊ0�ĵ����
        if (!d[i])
            q[++tt] = i;
    // printf("%d",q[tt]);
    while (tt >= hh) {                      //bfs��Ѱ���ϱ仯�����Ϊ0�ĵ�����һ������
        auto t = q[hh++];
        for (int i = h[t]; i != -1; i = ne[i])
        {
            int u = e[i];
            d[u]--;
            if (!d[u])
                q[++tt] = u;
        }
    }
    return tt == n - 1;        //������Ԫ����������е������ ˵��������������
}


int main() {

    memset(h, -1, sizeof h);
    cin >> n >> m;      //�����ˣ�debug���������
    while (m--)
    {
        int x, y;
        cin >> x >> y;
        // cout<< x << y <<endl;
        Add(x, y);
        d[y]++;
        // cout<<d[y]<<endl;
    }

    if (!topsort()) cout << "-1" << endl;
    else
    {
        for (int i = 0; i < n; i++)
            cout << q[i] << " ";
    }
    return 0;

}



���ߣ�ɶҲ�����С�ײ�
���ӣ�https ://www.acwing.com/activity/content/code/content/3928605/
��Դ��AcWing
����Ȩ���������С���ҵת������ϵ���߻����Ȩ������ҵת����ע��������