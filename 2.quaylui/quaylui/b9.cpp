#include <iostream>
using namespace std;

const int MAX = 20;
const int N = 8;

int x, y;
bool a[MAX], b[MAX * 2], c[MAX * 2];
int res[MAX];

void print_solution()
{
    for (int i = 1; i <= N; i++)
    {
        cout << res[i] << " ";
    }
    cout << endl;
}

bool is_safe(int row, int col)
{
    return (!a[row] && !b[row + col - N] && !c[N - row + col]);
}

void Try(int col)
{
    if (col == N + 1)
    {
        print_solution();
    }
    else if (col == x)
    {
        Try(col + 1);
    }
    else
    {
        for (int row = 1; row <= N; row++)
        {
            if (is_safe(row, col))
            {
                // Đặt hậu
                a[row] = 1;
                res[col] = row;
                b[row + col - N] = 1;
                c[N - row + col] = 1;

                Try(col + 1);

                // Xoá hậu
                a[row] = 0;
                b[row + col - N] = 0;
                c[N - row + col] = 0;
            }
        }
    }
}

int main()
{
    freopen("b9.txt", "r", stdin);

    cin >> x >> y;
    // Đặt hậu
    a[y] = 1;
    res[x] = y;
    b[y + x - N] = 1;
    c[N - y + x] = 1;

    Try(1);

    return 0;
}