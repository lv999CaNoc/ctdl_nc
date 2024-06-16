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

void Try(int c, int start = 1)
{
    if (c == k)
    {
        print_config();
        return;
    }
    for (int i = start; i <= n; i++)
    {
        config[c] = i;
        Try(c + 1, i + 1);
    }
}

int main()
{
    freopen("b6.txt", "r", stdin);

    cin >> n >> k;
    Try(0);

    return 0;
}