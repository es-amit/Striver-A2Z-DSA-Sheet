#include <bits/stdc++.h>
using namespace std;

double power(double x, int n)
{
    if (n == 0)
    {
        return 1;
    }
    if (n % 2 == 0)
    {
        double p = power(x, n / 2);
        return p * p;
    }
    else
    {
        double p = power(x, n / 2);
        return p * p * x;
    }
}
double myPow(double x, int n)
{
    if (x == 0)
    {
        return 0;
    }
    double ans = power(x, n);
    if (n > 0)
    {
        return ans;
    }
    return 1 / ans;
}
int main(){
    double x;
    int n;
    cin >> x >> n;
    cout << myPow(x,n);
}