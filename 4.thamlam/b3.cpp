#include <fstream>
#include <iostream>
using namespace std;

const int CNT_MONEY = 6;
int money[] = {1, 5, 10, 50, 100, 500};

void solve(int N)
{
    int res = 0;
    int i = CNT_MONEY - 1;
    int re_N = 1000 - N;

    while (re_N > 0 && i >= 0)
    {
        int curr_money = money[i];
        if (re_N >= curr_money)
        {
            short cnt = re_N / curr_money;
            re_N -= cnt * curr_money;
            res += cnt;
        }

        i--;
    }

    cout << res << endl;
}

int main()
{
    freopen("b3.txt", "r", stdin);
    int n, N;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> N;
        solve(N);
    }

    return 0;
}