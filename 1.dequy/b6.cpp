#include <fstream>
#include <iostream>
#include <math.h>
using namespace std;

double calc(int n)
{
    return (n == 1) ? 1 : sqrt(n + calc(n - 1));
}

int main()
{
    freopen("b6.txt", "r", stdin);

    int t;
    cin >> t;
    long n;
    for (int i = 0; i < t; i++)
    {
        cin >> n;
        printf("%.10f\n", calc(n));
    }

    return 0;
}