#include<iostream>
#include<unordered_map>
const int mod = 1e+9 + 7;
typedef long long LL;
using namespace std;

int main() {
    int n;
    LL res = 1;  //注意过界的问题
    unordered_map<int, int> primes;
    cin >> n;
    while (n--) {
        int x;
        cin >> x;
        for (int i = 2; i <= x / i; i++)   //分解质因数一定小于sqrt(x) 如果有两个大于 那么会出错
        //容易导致TLE错误这里
        {
            while (x % i == 0) {
                x /= i;
                primes[i]++;

            }
        }
        if (x > 1) primes[x]++;
    }
    for (auto prime : primes)
        res = res * (prime.second + 1) % mod;  //res虽然在int范围 但是乘一个数就不一定在int范围了
    cout << res << endl;
}

作者：啥也不会的小白菜
链接：https ://www.acwing.com/activity/content/code/content/3977603/
来源：AcWing
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。