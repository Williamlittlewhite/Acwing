#include<iostream>
#include<string>
#include<vector>
using namespace std;
vector<int> C;
bool cmp(vector<int>& A, vector<int>& B) {
    if (A.size() != B.size()) return A.size() > B.size();  //�����ô��ں� �����ü���ʽ�� ��Ϊ�����false����Ϊtrue
    else {
        for (int i = A.size() - 1;i >= 0;i--)
            if (A[i] != B[i])
                return A[i] > B[i];
        return true;
    }
}
vector<int> sub(vector<int>& A, vector<int>& B) {
    int t = 0;
    for (int i = 0;i < A.size();i++)
    {
        t = A[i] - t;
        if (i < B.size())
            t -= B[i];
        C.push_back((t + 10) % 10);
        if (t < 0) t = 1;
        else t = 0;
    }

    while (C.size() > 1 && C.back() == 0)
        C.pop_back();

    return C;//�������Ƿ���ֵdebug�˰���  ���Ҳ�����segmentation fault
}
int main() {
    string a, b;
    char c = '-';
    vector<int> A, B;
    cin >> a >> b;
    for (int i = a.size() - 1;i >= 0;i--)  //����Ҫע�����鳤�Ȳ�һ��
        A.push_back(a[i] - '0');
    for (int i = b.size() - 1;i >= 0;i--)
        B.push_back(b[i] - '0');
    if (cmp(A, B))
        sub(A, B);
    else
    {
        sub(B, A);printf("-");
    }
    for (int i = C.size() - 1;i >= 0;i--)
        printf("%d", C[i]);
    return 0;
}