#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
vector<int> C;
void DIV(vector<int> A, int b)
{
    int res = 0;
    for (int i = A.size() - 1;i >= 0;i--)
    {
        res = res * 10 + A[i];
        C.push_back(res / b);
        res %= b;
    }
    reverse(C.begin(), C.end());    //�߾��ȳ���Ҫע��push��ȥҲ�ǴӸ�λpush ���Ҫ�������߾��ȶ�Ӧ����reverse
    while (C.size() > 1 && C.back() == 0) C.pop_back();

    for (int i = C.size() - 1;i >= 0;i--)
        printf("%d", C[i]);
    printf("\n%d", res);
}
int main()
{
    string s;
    vector<int> A;
    int b;
    cin >> s;
    scanf("%d", &b);
    for (int i = s.size() - 1;i >= 0;i--)  //����д��++�����˰��� Ҫע��
        A.push_back(s[i] - '0');

    DIV(A, b);

    return 0;
}

//���ߣ�ɶҲ�����С�ײ�
//���ӣ�https ://www.acwing.com/activity/content/code/content/3747030/
//��Դ��AcWing
//����Ȩ���������С���ҵת������ϵ���߻����Ȩ������ҵת����ע��������