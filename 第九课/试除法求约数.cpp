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

���ߣ�ɶҲ�����С�ײ�
���ӣ�https ://www.acwing.com/activity/content/code/content/3976679/
��Դ��AcWing
����Ȩ���������С���ҵת������ϵ���߻����Ȩ������ҵת����ע��������