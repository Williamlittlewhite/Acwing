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
    // if(x%i==0)  //ע������Ҫ���ж�������ʾ�оٵĶ�������!
    // //���ڱ�֤��ǰ���Ѿ��������е�i-1֮�ڵ���������x������2~i-1  ���iҲû��
    // //��֤��i������
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