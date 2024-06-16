#include <iostream>
using namespace std;

const long MAX = 100000;

int n;
int bins[MAX];

void print_bins()
{
    for (int i = 0; i < n; i++)
    {
        cout << bins[i];
    }
    cout << endl;
}

void backtrack(int k)
{
    if (k == n)
    {
        print_bins();
        return;
    }

    for (int i = 1; i >= 0; i--)
    {
        bins[k] = i;
        backtrack(k + 1);
    }
}

int main()
{

    freopen("b2.txt", "r", stdin);

    cin >> n;
    backtrack(0);

    return 0;
}