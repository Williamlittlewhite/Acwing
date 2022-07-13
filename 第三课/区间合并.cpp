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
    sort(segs.begin(), segs.end());//debug�˰��� һ��Ҫ�ǵ������Ժ������̰������ϲ�
    for (auto seg : segs)
    {
        if (ed < seg.first)   //һ�����ж��Ƿ����ڷ�������
        {

            if (st != -2e9) // Ȼ�������ʼ�㲻�ǳ�ʼֵ�ż�¼������ֱ�ӽ����滻Ϊ��һ�������ٿ�ʼ�ϲ���
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