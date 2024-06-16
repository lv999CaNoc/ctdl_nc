#include <iostream>
using namespace std;

int n, k;
short config[10000];

bool generate_next_config()
{
    int i = k;
    while (i >= 1 && config[i] == n - k + i)
        i--;

    if (i >= 1)
    {
        config[i]++;
        for (int j = i + 1; j <= k; j++)
            config[j] = config[j - 1] + 1;
        return true;
    }
    // last config
    return false;
}

void print_config()
{
    cout << config[1];
    for (int i = 2; i <= k; i++)
    {
        printf("%3d", config[i]);
    }
    cout << endl;
}

void solve()
{
    for (int i = 1; i <= k; i++)
    {
        config[i] = i;
    }
    print_config();

    while (generate_next_config())
    {
        print_config();
    }
}

int main()
{
    freopen("b3.txt", "r", stdin);

    cin >> n >> k;

    solve();

    return 0;
}