#include<iostream>
#include<cmath>
using namespace std;
int main()
{
    double x;
    scanf("%lf", &x);
    double i = -100, j = 100;
    while (j - i > 1e-10)
    {
        double mid = (i + j) / 2;
        if (pow(mid, 3) >= x) j = mid;
        else i = mid;
    }
    printf("%f", i);

    return 0;
}
