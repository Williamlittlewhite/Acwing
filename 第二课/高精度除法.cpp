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
    reverse(C.begin(), C.end());    //高精度除法要注意push进去也是从高位push 因此要与其他高精度对应必须reverse
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
    for (int i = s.size() - 1;i >= 0;i--)  //这里写成++调试了半天 要注意
        A.push_back(s[i] - '0');

    DIV(A, b);

    return 0;
}

//作者：啥也不会的小白菜
//链接：https ://www.acwing.com/activity/content/code/content/3747030/
//来源：AcWing
//著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。