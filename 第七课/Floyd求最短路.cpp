#include<iostream>
using namespace std;
const int N = 210;
int n, m, k, idx;
int d[N][N];
const int INF = 0x3f3f3f3f;
//ע�����Ŷ���1��ʼ
void floyd() {
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
            }
        }
    }
}

int main() {
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (i == j) d[i][j] = 0;
            else d[i][j] = INF;
        }
    }
    while (m--) {
        int x, y, z;
        cin >> x >> y >> z;
        d[x][y] = min(d[x][y], z);
    }

    floyd();

    while (k--) {
        int x, y;
        cin >> x >> y;
        if (d[x][y] >= INF / 2) cout << "impossible" << endl;  //ע��������ж�Ҳ��INF/2 ��Bellman fordһ��
        else cout << d[x][y] << endl;
    }

    return 0;
}

���ߣ�ɶҲ�����С�ײ�
���ӣ�https ://www.acwing.com/activity/content/code/content/3944474/
��Դ��AcWing
����Ȩ���������С���ҵת������ϵ���߻����Ȩ������ҵת����ע��������