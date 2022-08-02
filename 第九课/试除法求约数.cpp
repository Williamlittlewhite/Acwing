#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


vector<int> get_divisors(int x) {
    vector<int> res;
    for (int i = 1; i <= x / i; i++) {
        if (x % i == 0)
        {
            res.push_back(i);
            if (i != x / i)
                res.push_back(x / i);
        }
    }
    sort(res.begin(), res.end());
    return res;
}

int main() {
    int n;
    cin >> n;
    vector<int> ans;
    while (n--) {
        int a;
        cin >> a;
        ans = get_divisors(a);
        for (int i = 0; i < ans.size(); i++)
            cout << ans[i] << " ";
        cout << endl;
    }



    return 0;
}

作者：啥也不会的小白菜
链接：https ://www.acwing.com/activity/content/code/content/3976679/
来源：AcWing
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。