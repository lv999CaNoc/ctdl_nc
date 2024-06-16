#include <fstream>
#include <iostream>
using namespace std;

double calc(long n)
{
    if (n == 0)
    {
        return 0;
    }
    return ((double)n / (n + 1)) + calc(n - 1);
}

int main()
{
    freopen("b13.txt", "r", stdin);

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