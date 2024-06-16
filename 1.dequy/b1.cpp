#include <fstream>
#include <iostream>
using namespace std;

long factorial(int n)
{
    if (n == 0)
    {
        cout << "0! = 1" << endl;
        return 1;
    }
    long fact = factorial(n - 1) * n;
    cout << n << "! = " << fact << endl;
    return fact;
}

int main()
{
    freopen("b1.txt", "r", stdin);
    int n;
    cin >> n;

    factorial(n);

    return 0;
}