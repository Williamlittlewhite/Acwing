#include<iostream>
#include<cstring>
using namespace std;
//����Ѱַ��
// const int n = 200003,null = 0x3f3f3f3f;   //��ס����Ѱַ��ʽѡ��2~3�����洢��������
// int h[n];//һ��߽綼����� null = 0x3f3f3f3f �϶���10**9��, ��memsetҪ��Ӧ
// int find(int x){
//     int t = (x%n+n)%n;
//     while(h[t]!=null&&h[t]!=x)
//         t++;
//     if(t==n)t=0;
//     return t;
// }
// int main(){
//     int N,temp;
//     memset(h,0x3f,sizeof h);
//     scanf("%d",&N);
//     while(N--){
//         char op[2];
//         scanf("%s",op);
//         if(op[0]=='I'){
//             scanf("%d",&temp);    //�ǵüӵ�ַ�����
//             int k = find(temp);
//             h[k] = temp;
//         }
//         else{
//             scanf("%d",&temp);   //�ǵõ�ַ�����
//             if(h[find(temp)]==temp)
//                 puts("Yes");
//             else
//                 puts("No");
//         }
//     }
//     return 0;
// }
const int n = 100003;
int h[n], e[n], ne[n], idx;
void insert(int x) {
    int t = (x % n + n) % n;
    e[idx] = x;
    ne[idx] = h[t];
    h[t] = idx;      //h��������ͷ�ڵ�ĵ�ַ
    idx++;
}
bool find(int x) {
    int t = (x % n + n) % n;
    for (int i = h[t];i != -1;i = ne[i]) { //h�������ǹ�ϣ����Ӧ������Ӧ��ͷ�ڵ�ĵ�ַ
        if (e[i] == x)         //ע��e������������
            return true;
    }
    return false;
}
int main() {
    int N, temp;
    memset(h, -1, sizeof h);
    scanf("%d", &N);
    while (N--) {
        char op[2];
        scanf("%s", op);
        if (op[0] == 'I') {
            scanf("%d", &temp);
            insert(temp);
        }
        else {
            scanf("%d", &temp);
            if (find(temp)) puts("Yes");
            else puts("No");
        }

    }

    return 0;
}


���ߣ�ɶҲ�����С�ײ�
���ӣ�https ://www.acwing.com/activity/content/code/content/3866152/
��Դ��AcWing
����Ȩ���������С���ҵת������ϵ���߻����Ȩ������ҵת����ע��������