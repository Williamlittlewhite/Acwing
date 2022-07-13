#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
typedef pair<int, int> PII;
int main() {
    int n;
    scanf("%d", &n);
    vector<PII> segs;
    int l, r;
    while (n--)
    {
        scanf("%d%d", &l, &r);
        segs.push_back({ l,r });
    }
    int st = -2e9, ed = -2e9;
    vector<PII> res;
    sort(segs.begin(), segs.end());//debug了半天 一定要记得排序以后才能用贪心区间合并
    for (auto seg : segs)
    {
        if (ed < seg.first)   //一定先判断是否属于分离的情况
        {

            if (st != -2e9) // 然后如果开始点不是初始值才记录，否则直接进行替换为第一个区间再开始合并！
                res.push_back({ st,ed });
            // printf("%d,%d ",st,ed);
            st = seg.first;
            ed = seg.second;
        }
        else
            ed = max(ed, seg.second);

    }
    if (st != -2e9)
    {
        res.push_back({ st,ed });
        // printf("%d,%d ",st,ed);
    }

    printf("%d", res.size());
    return 0;
}