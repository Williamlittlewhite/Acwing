#include<iostream>
#include<cstring>
using namespace std;
const int N = 1e+5 + 10, M = 2e+5 + 10;
int h[N], e[M], ne[M], idx; //ע������ͼҪ��2���Ź��ã���
int color[N];
int n, m;
void add(int x, int y) {
    e[idx] = y;
    ne[idx] = h[x];
    h[x] = idx++;
}
//���Ⱦ��uΪ�ڵ�cΪ��ɫ��ͼ
bool dfs(int u, int c)
{
    color[u] = c;
    for (int i = h[u]; i != -1; i = ne[i]) {
        int j = e[i];
        if (color[j] == -1) {
            if (!dfs(j, !c)) return false;
        }
        else if (color[j] == c)
            return false;
    }
    return true;
}
//Ⱦ�ľ����������
bool check() {
    memset(color, -1, sizeof color);
    bool flag = true;
    for (int i = 1; i <= n; i++) {
        if (color[i] == -1) {
            if (!dfs(i, 1)) {  //����1��0�����Եģ�
                flag = false;
                break;
            }
        }
    }
    return flag;
}

int main() {
    cin >> n >> m;
    memset(h, -1, sizeof h); //�ǵó�ʼ����ӱ�
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        add(u, v);
        add(v, u);
    }
    if (check()) cout << "Yes" << endl;
    else cout << "No";

    return 0;
}

���ߣ�ɶҲ�����С�ײ�
���ӣ�https ://www.acwing.com/activity/content/code/content/3964499/
��Դ��AcWing
����Ȩ���������С���ҵת������ϵ���߻����Ȩ������ҵת����ע��������