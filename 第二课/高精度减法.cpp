#include<iostream>
#include<string>
#include<vector>
using namespace std;
vector<int> C;
bool cmp(vector<int>& A, vector<int>& B) {
    if (A.size() != B.size()) return A.size() > B.size();  //这里用大于号 不能用计算式子 因为会造成false误判为true
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

    return C;//这里忘记返回值debug了半天  这个也会造成segmentation fault
}
int main() {
    string a, b;
    char c = '-';
    vector<int> A, B;
    cin >> a >> b;
    for (int i = a.size() - 1;i >= 0;i--)  //这里要注意数组长度不一样
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