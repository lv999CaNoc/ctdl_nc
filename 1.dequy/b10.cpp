#include <fstream>
#include <iostream>
#include <math.h>
using namespace std;

double power(double x, int n)
{
    double res = 1;
    for (int i = 0; i < n; i++)
    {
        res *= x;
    }
    return res;
}

long fact(int n)
{
    if (n == 1)
    {
        return 1;
    }
    return fact(n - 1) * n;
}

double calc(double x, int n)
{
    if (n == 1)
        return x;
    return (power(x, n) / fact(n)) + calc(x, n - 1);
}

int main()
{
    freopen("b10.txt", "r", stdin);

    int t;
    cin >> t;
    double x;
    int n;
    for (int i = 0; i < t; i++)
    {
        cin >> x >> n;
        printf("%.8lf\n", calc(x, n));
    }

    return 0;
}