#include <iostream>
using namespace std;

int n;
short config[10000];

void m_swap(int i, int j)
{
    int tmp = config[i];
    config[i] = config[j];
    config[j] = tmp;
}

void m_reverse(int i, int j)
{
    while (i < j)
    {
        m_swap(i, j);
        i++;
        j--;
    }
}

bool generate_next_config()
{
    int i = n - 2;
    while (i >= 0 && config[i] < config[i + 1])
        i--;
    if (i >= 0)
    {
        int j = n - 1;
        while (config[i] < config[j])
            j--;

        m_swap(i, j);
        m_reverse(i + 1, n - 1);

        return true;
    }

    // last config
    return false;
}

void print_config()
{
    for (int i = 0; i < n; i++)
    {
        printf("%3d", config[i]);
    }
    cout << endl;
}

void solve()
{
    for (int i = 0; i < n; i++)
    {
        config[i] = n - i;
    }
    print_config();

    while (generate_next_config())
    {
        print_config();
    }
}

int main()
{
    freopen("b2.txt", "r", stdin);

    cin >> n;

    solve();

    return 0;
}