#include<iostream>
using namespace std;
const int N = 7;
bool st[N];
int n;
int path[N];
void dfs(int u) {
    if (u == n)
    {     //dfs�����еݹ���ֹ������
        for (int i = 0; i < n; i++)
            cout << path[i] << ' ';
        cout << endl;
        return;
    }

    else {   //��u=0,1,2���������λ�ý��а�������
        for (int j = 1; j <= n; j++)   //�ָ��ֳ������ظ���ԭ����jһ����++
            if (!st[j])           //�������û�б��ù������ø�������·��
            {
                path[u] = j;
                st[j] = true;
                dfs(u + 1);       //����������ȱ�����
                st[j] = false; //�ָ��ֳ�����Ϊ��ʱ�����·���Ѿ������� 
                //Ϊ�˻����ֳ�������ˣ�
                path[u] = 0;
            }
    }
}
int main()
{
    scanf("%d", &n);

    dfs(0);
    return 0;
}

���ߣ�ɶҲ�����С�ײ�
���ӣ�https ://www.acwing.com/activity/content/code/content/3893198/
��Դ��AcWing
����Ȩ���������С���ҵת������ϵ���߻����Ȩ������ҵת����ע��������