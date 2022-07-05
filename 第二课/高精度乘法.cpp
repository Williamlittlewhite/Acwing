//#include<iostream>
//#include<string>
//#include<vector>
//using namespace std;
//vector<int> C;
//void Mul(vector<int>& A, int b) {
//    long long int t = 0;
//    for (int i = 0;i < A.size() || t;i++)
//    {
//        if (i < A.size())//这个地方因为有上面||t必须有
//            t += A[i] * b;
//        C.push_back(t % 10);
//        t /= 10;
//    }
//    while (C.size() > 1 && C.back() == 0)
//        C.pop_back();
//}
//int main() {
//    string a;
//    int b;
//    vector<int> A;
//    cin >> a >> b;
//    for (int i = a.size() - 1;i >= 0;i--)
//        A.push_back(a[i] - '0');
//
//    Mul(A, b);
//    for (int i = C.size() - 1;i >= 0;i--)
//        printf("%d", C[i]);
//
//
//    return 0;
//}
//
//作者：啥也不会的小白菜
//链接：https ://www.acwing.com/activity/content/code/content/3735594/
//来源：AcWing
//著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。