#include <fstream>
#include <iostream>
using namespace std;

long gcd(long a, long b)
{
    return (b == 0) ? a : gcd(b, a % b);
}
int main()
{
    freopen("b4.txt", "r", stdin);

    int t;
    cin >> t;
    long a, b;
    for (int i = 0; i < t; i++)
    {
        cin >> a >> b;

        cout << gcd(a, b) << endl;
    }

    return 0;
}