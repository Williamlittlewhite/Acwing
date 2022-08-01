#include<iostream>
#include<cstring>
using namespace std;
int n1, n2, m;
const int N = 510, M = 1e+5 + 10;
int h[N], e[M], ne[M], match[N], idx;  //ע��e��ne�����ɱ�ȷ����Χ
bool st[N];
void add(int x, int y) {
    e[idx] = y;
    ne[idx] = h[x];
    h[x] = idx++;
}

bool find(int x) {
    for (int i = h[x]; i != -1; i = ne[i]) {
        int j = e[i];
        if (!st[j])
        {
            st[j] = true;
            if (match[j] == 0 || find(match[j])) {
                match[j] = x;
                return true;
            }
        }
    }
    return false;
}
int main() {
    cin >> n1 >> n2 >> m;
    memset(h, -1, sizeof h);//�ӱ�֮ǰ���г�ʼ��
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        add(u, v);
    }

    int res = 0;
    for (int i = 1; i <= n1; i++) {
        memset(st, false, sizeof st);  //ÿ����ƥ��Ҫ����һ��st���鷽�����ƥ�䣡
        if (find(i)) res++;
    }

    cout << res << endl;
    return 0;
}

���ߣ�ɶҲ�����С�ײ�
���ӣ�https ://www.acwing.com/activity/content/code/content/3966845/
��Դ��AcWing
����Ȩ���������С���ҵת������ϵ���߻����Ȩ������ҵת����ע��������