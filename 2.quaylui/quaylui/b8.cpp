#include <iostream>
using namespace std;

const int MAX = 100;

int n, cnt = 1;
bool a[MAX], b[MAX * 2], c[MAX * 2];
int res[MAX];

void print_solution()
{
    printf("Solution %2d:", cnt++);
    for (int i = 1; i <= n; i++)
    {
        printf("%4d", res[i]);
    }
    cout << endl;
}

bool is_safe(int row, int col)
{
    return (!a[row] && !b[row + col - n] && !c[n - row + col]);
}

void Try(int col)
{
    for (int row = 1; row <= n; row++)
    {
        if (is_safe(row, col))
        {
            // Đặt hậu
            a[row] = 1;
            res[col] = row;
            b[row + col - n] = 1;
            c[n - row + col] = 1;

            if (col == n)
            {
                print_solution();
            }
            else
            {
                Try(col + 1);
            }
            // Xoá hậu
            a[row] = 0;
            b[row + col - n] = 0;
            c[n - row + col] = 0;
        }
    }
}

int main()
{
    freopen("b8.txt", "r", stdin);

    cin >> n;
    Try(1);

    return 0;
}