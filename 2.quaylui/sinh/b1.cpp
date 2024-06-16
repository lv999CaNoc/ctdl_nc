#include <iostream>
using namespace std;

int n;
short config[10000];

bool isLastConfig()
{
    for (int i = 0; i < n; i++)
    {
        if (!config[i])
        {
            return false;
        }
    }
    return true;
}

void generate_next_config()
{
    int i = n - 1;
    while (config[i])
    {
        config[i] = 0;
        i--;
    }
    config[i] = 1;
}

void print_config()
{
    for (int i = 0; i < n; i++)
    {
        cout << config[i];
    }
    cout << endl;
}

void solve()
{
    for (int i = 0; i < n; i++)
    {
        config[i] = 0;
    }
    print_config();

    while (!isLastConfig())
    {
        generate_next_config();
        print_config();
    }
}

int main()
{
    freopen("b1.txt", "r", stdin);

    cin >> n;

    solve();

    return 0;
}