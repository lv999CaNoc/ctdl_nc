#include <iostream>
using namespace std;

const int MAX = 1000;

int n, k;
int config[MAX];
bool is_used[MAX];

void print_config()
{
    for (int i = 0; i < k; i++)
    {
        printf("%3d", config[i]);
    }
    cout << endl;
}

void Try(int c)
{
    if (c == k)
    {
        print_config();
        return;
    }

    for (int i = 1; i <= n; i++)
    {
        if (!is_used[i])
        {
            config[c] = i;
            is_used[i] = 1;

            Try(c + 1);

            is_used[i] = 0;
        }
    }
}

int main()
{
    freopen("b5.txt", "r", stdin);

    cin >> n >> k;
    Try(0);

    return 0;
}