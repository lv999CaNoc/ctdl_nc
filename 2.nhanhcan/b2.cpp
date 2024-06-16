#include <iostream>
#include <climits>
using namespace std;

const int MAX = 1000;

int n, gap = INT_MAX, tmp_gap = 0, cnt = 0;
int a[MAX][MAX];
int visited[MAX];
int route[MAX][MAX], x_route[MAX];

void add_route(int index)
{
    for (int i = 0; i < n; i++)
    {
        route[index][i] = x_route[i];
    }
}

void Try(int k)
{
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            x_route[k] = i;
            if (k != 0)
            {
                tmp_gap += a[x_route[k - 1]][i];
            }
            visited[i] = 1;

            if (k == n - 1)
            {
                int curr_gap = tmp_gap + a[i][x_route[0]];
                if (curr_gap < gap)
                {
                    gap = curr_gap;
                    cnt = 0;
                }
                if (curr_gap == gap)
                {
                    add_route(cnt);
                    cnt++;
                }
            }
            else
            {
                if (tmp_gap < gap)
                {
                    Try(k + 1);
                }
            }

            if (k != 0)
            {
                tmp_gap -= a[x_route[k - 1]][i];
            }
            visited[i] = 0;
        }
    }
}

void output()
{
    cout << "Min total distance = " << gap << endl;
    for (int i = 0; i < cnt; i++)
    {
        printf("Solution %2d: ", i + 1);
        for (int j = 0; j < n; j++)
        {
            printf("%4d", route[i][j]);
        }
        cout << endl;
    }
}

int main()
{
    freopen("b2.txt", "r", stdin);

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> a[i][j];
        }
        visited[i] = 0;
    }

    Try(0);

    output();
    return 0;
}