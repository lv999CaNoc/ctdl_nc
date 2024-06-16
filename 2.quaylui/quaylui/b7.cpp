#include <iostream>
using namespace std;

const int MAX = 1000;

int n, k;
int config[MAX];

void print_config()
{
    cout << config[0];
    for (int i = 1; i < k; i++)
    {
        printf("%3d", config[i]);
    }
    cout << endl;
}

void Try(int c, int start = n)
{
    if (c == k)
    {
        print_config();
        return;
    }
    for (int i = start; i >= 1; i--)
    {
        config[c] = i;
        Try(c + 1, i - 1);
    }
}

int main()
{
    freopen("b7.txt", "r", stdin);

    cin >> n >> k;
    Try(0);

    return 0;
}