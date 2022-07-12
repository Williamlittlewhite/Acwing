#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
typedef pair<int, int> PII;  //pair������std���ֿռ��� һ���ں���
const int N = 3e+5 + 10;   //����һ����3*10**5+10����Ϊx��l��r��Ҫ������ɢ�� Ĭ������Ϊ10**5�������
int a[N], s[N];
vector<int> alls;
vector<PII> add, query;
int find(int x) {
    int l = 0, r = alls.size() - 1;
    while (l < r) {
        int mid = l + r >> 1;    //���һ����ѭ���� ���򲻻���ֳɹ��� debug�˰���~
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
    //  for(int i=1;i<=alls.size();i++)  //��ɢ���ķ�Χ����0~alls.size
    //     printf("%d ",a[i]);
    for (int i = 1;i <= alls.size();i++)   //ע��ǰ׺�͵ķ�ΧӦ�úͲ�����鳤��һ��
        s[i] = s[i - 1] + a[i];
    // cout<<endl<<s[1]<<" "<<s[3]<<endl;
    for (auto num : query) {
        int l = find(num.first);
        int r = find(num.second);
        cout << s[r] - s[l - 1] << endl;
    }
    return 0;
}

���ߣ�ɶҲ�����С�ײ�
���ӣ�https ://www.acwing.com/activity/content/code/content/3791915/
��Դ��AcWing
����Ȩ���������С���ҵת������ϵ���߻����Ȩ������ҵת����ע��������