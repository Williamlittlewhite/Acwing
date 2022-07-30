#include<iostream>
#include<cstring>
#include<queue>
using namespace std;
int n, m;
const int N = 1e+5 + 10;
int dis[N], h[N], e[N], ne[N], w[N], idx;
bool st[N]; //һ��Ҫ�����bool���飡����
void add(int x, int y, int z) {
    e[idx] = y;
    w[idx] = z;
    ne[idx] = h[x];
    h[x] = idx;
    idx++;
}

int SPFA() {  //ע�ⷵ��ֵ����
    memset(dis, 0x3f, sizeof dis);//ע���ʼ�� ������
    dis[1] = 0;

    queue<int> q;
    q.push(1);
    st[1] = true; //ע����һ�����鱣���Ƿ���ӵ����

    while (q.size()) {
        auto t = q.front();
        q.pop();

        st[t] = false;

        for (int i = h[t]; i != -1; i = ne[i])
        {
            int j = e[i];
            if (dis[j] > dis[t] + w[i])
            {
                dis[j] = dis[t] + w[i];
                if (!st[j])
                {
                    q.push(j);
                    st[j] = true;
                }
            }
        }
    }

    return dis[n];

}

int main()
{
    // int n,m;//��Ҫ�ظ����� debug�˰��죡����
    cin >> n >> m;
    memset(h, -1, sizeof h);
    while (m--) {
        int x, y, z;
        cin >> x >> y >> z;
        // cout << x << y << z;
        add(x, y, z);
    }
    int t = SPFA();
    if (t == 0x3f3f3f3f) cout << "impossible" << endl;
    else cout << t;

    return 0;
}

