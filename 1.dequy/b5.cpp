#include <fstream>
#include <iostream>
using namespace std;

void dec_to_bin(int num)
{
    if (num < 2)
    {
        cout << num;
        return;
    }
    dec_to_bin(num / 2);
    cout << num % 2;
}

int main()
{
    freopen("b5.txt", "r", stdin);

    int t;
    cin >> t;
    long num;
    for (int i = 0; i < t; i++)
    {
        cin >> num;

        dec_to_bin(num);
        cout << endl;
    }

    return 0;
}