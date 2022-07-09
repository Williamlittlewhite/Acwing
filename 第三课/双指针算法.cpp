#include<iostream>
#include<vector>
using namespace std;
const int N = 1e+5 + 10;
int a[N];
int main() {
    vector<int> v;
    int n;
    scanf("%d", &n);
    for (int i = 0;i < n;i++)
    {
        int temp;
        scanf("%d", &temp);
        v.push_back(temp);
    }
    int length = v.size();
    int ans = 0;
    for (int i = 0, j = 0;i < length;i++)
    {
        a[v[i]]++;                  //核心是j是单调向右的，如果j向左成立的话，那么上次成立的就不会是最大不重复序列
        while (j < i && a[v[i]]>1)      //注意这个双指针的写法，利用一个数组存取每个数出现的次数，i表示最后的位置
            a[v[j++]]--;        //j从开始算，如果最后出现的位置次数大于1说明有重复，通过右移j的方式使得子序列不重复
        ans = max(i - j + 1, ans);
    }
    printf("%d", ans);
    return 0;
}

作者：啥也不会的小白菜
链接：https ://www.acwing.com/activity/content/code/content/3768193/
来源：AcWing
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。