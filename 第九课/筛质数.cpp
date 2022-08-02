#include<iostream>
using namespace std;
const int N = 1e+6 + 10;
bool st[N];
int primes[N];

//朴素筛法
// int get_primes(int x){
//     int i,cnt=0;
//     for(i=2;i<=x;i++){
//         if(!st[i]) primes[cnt++] = i;
//         for(int j=i+i;j<=x;j+=i) st[j]=true;
//     }

//     return cnt;
// }

//埃氏筛法
// int get_primes(int x){
//     int cnt=0;
//     for(int i=2;i<=x;i++){
//         if(st[i]) continue;
//         primes[cnt++] = i;
//         for(int j=i+i;j<=x;j+=i) st[j]=true;
//     }
//     return cnt;
// }

//线性筛法
int get_primes(int x) {
    int cnt = 0;
    for (int i = 2; i <= x; i++) {
        if (!st[i]) primes[cnt++] = i;
        for (int j = 0; primes[j] <= x / i; j++)
        {
            st[i * primes[j]] = true;
            if (i % primes[j] == 0) break; //无论是否为0，都可以保证被最小质因数筛掉，
            //这个仅仅是找到i的最小质因数的时候break的意思,防止重复筛！
        }
    }
    return cnt;
}


int main() {
    int n;
    cin >> n;
    cout << get_primes(n);
}

作者：啥也不会的小白菜
链接：https ://www.acwing.com/activity/content/code/content/3976170/
来源：AcWing
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。