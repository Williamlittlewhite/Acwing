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

作者：啥也不会的小白菜
链接：https ://www.acwing.com/activity/content/code/content/3975667/
来源：AcWing
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。