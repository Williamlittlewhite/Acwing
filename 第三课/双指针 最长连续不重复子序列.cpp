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
        a[v[i]]++;                  //������j�ǵ������ҵģ����j��������Ļ�����ô�ϴγ����ľͲ���������ظ�����
        while (j < i && a[v[i]]>1)      //ע�����˫ָ���д��������һ�������ȡÿ�������ֵĴ�����i��ʾ����λ��
            a[v[j++]]--;        //j�ӿ�ʼ�㣬��������ֵ�λ�ô�������1˵�����ظ���ͨ������j�ķ�ʽʹ�������в��ظ�
        ans = max(i - j + 1, ans);
    }
    printf("%d", ans);
    return 0;
}

���ߣ�ɶҲ�����С�ײ�
���ӣ�https ://www.acwing.com/activity/content/code/content/3768193/
��Դ��AcWing
����Ȩ���������С���ҵת������ϵ���߻����Ȩ������ҵת����ע��������