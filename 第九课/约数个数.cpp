#include<iostream>
#include<unordered_map>
const int mod = 1e+9 + 7;
typedef long long LL;
using namespace std;

int main() {
    int n;
    LL res = 1;  //ע����������
    unordered_map<int, int> primes;
    cin >> n;
    while (n--) {
        int x;
        cin >> x;
        for (int i = 2; i <= x / i; i++)   //�ֽ�������һ��С��sqrt(x) ������������� ��ô�����
        //���׵���TLE��������
        {
            while (x % i == 0) {
                x /= i;
                primes[i]++;

            }
        }
        if (x > 1) primes[x]++;
    }
    for (auto prime : primes)
        res = res * (prime.second + 1) % mod;  //res��Ȼ��int��Χ ���ǳ�һ�����Ͳ�һ����int��Χ��
    cout << res << endl;
}

���ߣ�ɶҲ�����С�ײ�
���ӣ�https ://www.acwing.com/activity/content/code/content/3977603/
��Դ��AcWing
����Ȩ���������С���ҵת������ϵ���߻����Ȩ������ҵת����ע��������