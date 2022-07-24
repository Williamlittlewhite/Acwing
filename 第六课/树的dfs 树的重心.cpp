#include<iostream>
#include<cstring>
using namespace std;
const int N = 1e+5 + 10;
bool st[N];
int ans = N;
int n;
int h[N], e[2 * N], ne[2 * N], idx;
void add(int a, int b) {
    e[idx] = b;
    ne[idx] = h[a];
    h[a] = idx;
    idx++;
}
//��uΪ�������е������  ����ǹؼ�
int dfs(int u) {
    st[u] = true;                 //һ��Ҫ�Ѹ��ڵ���ϱ�� �����������������п����������޵ݹ�
    int sum = 1;
    int res = 0;
    for (int i = h[u]; i != -1; i = ne[i])   //����u�������ӽڵ�����ĵ������
    {
        int j = e[i];
        if (!st[j])
        {
            int s = dfs(j);
            res = max(s, res);          //res��¼u���������������Ľڵ���Ŀ
            sum += s;                 //sum��¼u����������һ���Ľڵ���Ŀ
        }
    }
    res = max(res, n - sum);
    // cout<<res<<endl;
    ans = min(ans, res);              //��¼����ɾȥ������ͨ��������Ŀ
    return sum;
}


int main()
{
    scanf("%d", &n);
    memset(h, -1, sizeof h);

    for (int i = 0; i < n - 1; i++)   //��������n-1�����Ǹ����
    {
        int a, b;
        cin >> a >> b;
        add(a, b);
        add(b, a);
    }
    dfs(1);
    cout << ans;
    return 0;
}

���ߣ�ɶҲ�����С�ײ�
���ӣ�https ://www.acwing.com/activity/content/code/content/3905131/
��Դ��AcWing
����Ȩ���������С���ҵת������ϵ���߻����Ȩ������ҵת����ע��������