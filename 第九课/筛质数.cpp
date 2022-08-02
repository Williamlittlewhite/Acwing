#include<iostream>
using namespace std;
const int N = 1e+6 + 10;
bool st[N];
int primes[N];

//����ɸ��
// int get_primes(int x){
//     int i,cnt=0;
//     for(i=2;i<=x;i++){
//         if(!st[i]) primes[cnt++] = i;
//         for(int j=i+i;j<=x;j+=i) st[j]=true;
//     }

//     return cnt;
// }

//����ɸ��
// int get_primes(int x){
//     int cnt=0;
//     for(int i=2;i<=x;i++){
//         if(st[i]) continue;
//         primes[cnt++] = i;
//         for(int j=i+i;j<=x;j+=i) st[j]=true;
//     }
//     return cnt;
// }

//����ɸ��
int get_primes(int x) {
    int cnt = 0;
    for (int i = 2; i <= x; i++) {
        if (!st[i]) primes[cnt++] = i;
        for (int j = 0; primes[j] <= x / i; j++)
        {
            st[i * primes[j]] = true;
            if (i % primes[j] == 0) break; //�����Ƿ�Ϊ0�������Ա�֤����С������ɸ����
            //����������ҵ�i����С��������ʱ��break����˼,��ֹ�ظ�ɸ��
        }
    }
    return cnt;
}


int main() {
    int n;
    cin >> n;
    cout << get_primes(n);
}

���ߣ�ɶҲ�����С�ײ�
���ӣ�https ://www.acwing.com/activity/content/code/content/3976170/
��Դ��AcWing
����Ȩ���������С���ҵת������ϵ���߻����Ȩ������ҵת����ע��������