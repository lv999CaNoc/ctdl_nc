#include <fstream>
#include <iostream>
#include <math.h>
using namespace std;

long X[1000] = {}, Y[1000] = {};
long calc_y(int n);
long calc_x(int n);

int main()
{
    freopen("b11.txt", "r", stdin);

    int t;
    cin >> t;
    long n;
    for (int i = 0; i < t; i++)
    {
        cin >> n;
        cout << calc_x(n) << " " << calc_y(n) << endl;
    }

    return 0;
}

long calc_x(int n)
{
    if (X[n] != 0)
    {
        return X[n];
    }
    if (n == 0)
    {
        X[n] = 1;
        return 1;
    }
    X[n] = calc_x(n - 1) + calc_y(n - 1);
    return X[n];
}

long calc_y(int n)
{
    if (n != 0 && Y[n] != 0)
    {
        return Y[n];
    }
    if (n == 0)
    {
        Y[n] = 0;
        return 0;
    }
    Y[n] = 3 * calc_x(n - 1) + calc_y(n - 1);
    return Y[n];
}
