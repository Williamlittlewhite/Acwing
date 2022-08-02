#include<iostream>
using namespace std;

void divide(int x) {
    for (int i = 2; i <= x / i; i++)
    {
        int s = 0;
        while (x % i == 0) {
            x /= i; s++;
        }
        cout << i << " " << s << endl;
    }
    // if(x%i==0)  //注意这里要有判断条件表示列举的都是质数!
    // //由于保证了前面已经除了所有的i-1之内的数，所以x不含有2~i-1  因此i也没有
    // //保证了i是素数
    // {
    //     int s=0;
    //     while(x%i==0) x/=i,s++;
    //     cout << i << " " << s << endl;
    // }
    if (x > 1)
        cout << x << " " << 1 << endl;
}

int main() {
    int n;
    cin >> n;
    while (n--) {
        int a;
        cin >> a;
        divide(a);
        cout << endl;
    }
    cin.get();
    return 0;
}