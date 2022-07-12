#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
typedef pair<int, int> PII;  //pair包含在std名字空间下 一定在后面
const int N = 3e+5 + 10;   //这里一定开3*10**5+10，因为x，l，r都要进行离散化 默认输入为10**5个的情况
int a[N], s[N];
vector<int> alls;
vector<PII> add, query;
int find(int x) {
    int l = 0, r = alls.size() - 1;
    while (l < r) {
        int mid = l + r >> 1;    //这个一定在循环里 否则不会二分成功的 debug了半天~
        if (alls[mid] >= x) r = mid;
        else l = mid + 1;
    }
    return r + 1;
}
int main() {
    int n, m;
    scanf("%d%d", &n, &m);

    while (n--) {
        int x, c;
        scanf("%d%d", &x, &c);
        alls.push_back(x);
        add.push_back({ x,c });
    }

    while (m--) {
        int l, r;
        scanf("%d%d", &l, &r);
        alls.push_back(l);
        alls.push_back(r);
        query.push_back({ l,r });
    }
    // for(auto i:alls)
    //     printf("%d ",i);
    sort(alls.begin(), alls.end());
    // for(auto i:alls)
    //     printf("%d ",i);
    alls.erase(unique(alls.begin(), alls.end()), alls.end());
    // for(auto i:alls)
    //     printf("%d ",i);
    for (auto num : add) {
        int temp = find(num.first);
        // printf("%d\n",temp);
        a[temp] += num.second;
        // printf("%d\n",a[temp]);
    }
    //  for(int i=1;i<=alls.size();i++)  //离散化的范围就是0~alls.size
    //     printf("%d ",a[i]);
    for (int i = 1;i <= alls.size();i++)   //注意前缀和的范围应该和差分数组长度一致
        s[i] = s[i - 1] + a[i];
    // cout<<endl<<s[1]<<" "<<s[3]<<endl;
    for (auto num : query) {
        int l = find(num.first);
        int r = find(num.second);
        cout << s[r] - s[l - 1] << endl;
    }
    return 0;
}

作者：啥也不会的小白菜
链接：https ://www.acwing.com/activity/content/code/content/3791915/
来源：AcWing
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。