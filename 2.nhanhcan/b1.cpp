#include <iostream>
#include <climits>
using namespace std;

const int MAX = 1000;

int n, gap = INT_MAX, tmp_gap = 0;
int a[MAX][MAX];
int visited[MAX];

void Try(int k, int c)
{
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            tmp_gap += a[c][i];
            visited[i] = 1;

            if (k == n)
            {
                int curr_gap = tmp_gap + a[i][0];
                if (curr_gap < gap)
                {
                    gap = curr_gap;
                }
            }
            else
            {
                if (tmp_gap < gap)
                {
                    Try(k + 1, i);
                }
            }

            tmp_gap -= a[c][i];
            visited[i] = 0;
        }
    }
}

int main()
{
    freopen("b1.txt", "r", stdin);

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> a[i][j];
        }
        visited[i] = 0;
    }

    visited[0] = 1;
    Try(2, 0);

    cout << gap << endl;
    return 0;
}