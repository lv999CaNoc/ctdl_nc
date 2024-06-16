#include <fstream>
#include <iostream>
#include <math.h>
using namespace std;

double calc(int n, int dent)
{
    if (dent == 0)
    {
        return sqrt(n);
    }
    return sqrt((n - dent) + calc(n, dent - 1));
}

int main()
{
    freopen("b7.txt", "r", stdin);

    int t;
    cin >> t;
    long n;
    for (int i = 0; i < t; i++)
    {
        cin >> n;
        printf("%.10f\n", calc(n, n - 1));
    }

    return 0;
}