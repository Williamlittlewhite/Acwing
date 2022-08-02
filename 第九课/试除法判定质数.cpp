#include<iostream>
using namespace std;

bool is_prime(int x) {
    if (x < 2) return false;
    for (int i = 2; i <= x / i; i++) {
        if (x % i == 0)
            return false;
    }
    return true;
}

int main() {
    int n;
    cin >> n;
    while (n--) {
        int a;
        cin >> a;
        if (is_prime(a)) cout << "Yes" << endl;
        else cout << "No" << endl;
    }

    return 0;
}

���ߣ�ɶҲ�����С�ײ�
���ӣ�https ://www.acwing.com/activity/content/code/content/3975667/
��Դ��AcWing
����Ȩ���������С���ҵת������ϵ���߻����Ȩ������ҵת����ע��������