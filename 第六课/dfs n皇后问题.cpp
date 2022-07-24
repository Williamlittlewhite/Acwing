// #include<iostream>
// using namespace std;
// const int N = 10;
// bool col[N],dg[2*N],udg[2*N];
// char path[N][N];
// int n;
// void dfs(int u){                     //������ǰ���������ȱ���������б���
//     if(u==n)                        //u=0,1,...,n-1��ʾ�Ե�n��ѡ��ʺ�
//         {
//             for(int i=0;i<n;i++)
//                 puts(path[i]);
//             puts("");
//             return;
//         }
//     else{
//         for(int i=0;i<n;i++)
//         {
//             if(!col[i]&&!dg[u+i]&&!udg[n+u-i])   //����u+i ��n+u-i��ӳ��Խ��ߵķ���
//             //�ǵ����鿪��2N
//                 {
//                 path[u][i]='Q';
//                 col[i] = true;
//                 dg[u+i] = true;
//                 udg[n+u-i] = true;
//                 dfs(u+1);
//                 col[i] = false;
//                 dg[u+i] = false;
//                 udg[n+u-i] = false;
//                 path[u][i] = '.';  //�ǵûָ��ֳ� debug��
//                 }
//         }
//     }
// }
// int main(){
//     cin >> n;
//     for(int i=0;i<n;i++)
//         for(int j=0;j<n;j++)
//             path[i][j] = '.';   //���ܳ�ʼ��ȫΪ.����������ʼ����ס��debug��
//     dfs(0);
//     return 0;
// }
#include<iostream>
using namespace std;
const int N = 10;
int n;
bool col[N], row[N], dg[2 * N], udg[2 * N];
char g[N][N];
void dfs(int x, int y, int s) {      //����ǰ����ӱ����� x�����д��ϵ��� y�����д�����
    if (y == n) x += 1, y = 0;
    if (x == n)
    {
        if (s == n)
        {
            for (int i = 0; i < n; i++)
                puts(g[i]);
            puts("");
        }
        return;                 //�ݹ���� ��һ��dfsʹ������������.  �ڶ���dfs�Żʺ�
    }
    g[x][y] = '.';
    dfs(x, y + 1, s);

    if (!row[x] && !col[y] && !dg[x + y] && !udg[n + x - y])
    {
        g[x][y] = 'Q';
        row[x] = col[y] = dg[x + y] = udg[n + x - y] = true;
        dfs(x, y + 1, s + 1);                                  //�ظ��ֳ��������dfs
        row[x] = col[y] = dg[x + y] = udg[n + x - y] = false;
        g[x][y] = '.';
    }
}
int main()
{
    cin >> n;
    dfs(0, 0, 0);
    return 0;
}
