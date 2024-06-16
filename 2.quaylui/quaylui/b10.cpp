#include <iostream>
using namespace std;
const int MAX = 110;

int n, m, y, x, tmp_x, tmp_y, res = 1;
int a[MAX][MAX];
int dx[] = {-1, 0, 1, 0}, dy[] = {0, 1, 0, -1};

bool is_safe(int ty, int tx)
{
    return (1 <= ty && ty <= n && 1 <= tx && tx <= m);
}

void Try(int ty, int tx)
{
    for (int i = 0; i < 4; i++)
    {
        tmp_y = ty + dy[i];
        tmp_x = tx + dx[i];

        if (is_safe(tmp_y, tmp_x) && !a[tmp_y][tmp_x])
        {
            res++;
            a[tmp_y][tmp_x] = 1;
            Try(tmp_y, tmp_x);
        }
    }
}

int main()
{
    freopen("b10.txt", "r", stdin);

    cin >> n >> m >> y >> x;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> a[i][j];

    a[y][x] = 1;
    Try(y, x);

    cout << res;

    return 0;
}