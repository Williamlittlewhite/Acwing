#include<iostream>
#include<string>
#include<vector>
using namespace std;
vector<int> ADD(vector<int>& A, vector<int>& B) {
    int t = 0;
    vector<int> C;
    for (int i = 0;i < A.size();i++)
    {
        t += A[i];
        if (i < B.size()) t += B[i];
        C.push_back(t % 10);
        t /= 10;
    }
    if (t)
        C.push_back(t);
    return C;
}
int main() {
    string a, b;
    vector<int> A, B;
    vector<int> C;
    cin >> a >> b;
    for (int i = a.size() - 1;i >= 0;i--)
        A.push_back(a[i] - '0');
    for (int i = b.size() - 1;i >= 0;i--)
        B.push_back(b[i] - '0');
    if (A.size() < B.size()) C = ADD(B, A);
    else C = ADD(A, B);
    for (int i = C.size() - 1;i >= 0;i--)
        cout << C[i];
    return 0;
}
//
//���ߣ�ɶҲ�����С�ײ�
//���ӣ�https ://www.acwing.com/activity/content/code/content/3708249/
//��Դ��AcWing
//����Ȩ���������С���ҵת������ϵ���߻����Ȩ������ҵת����ע��������