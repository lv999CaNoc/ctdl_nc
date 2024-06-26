#include <fstream>
#include <iostream>
using namespace std;

const int MAX_INT = 2147483647;

int main()
{
    freopen("b5.txt", "r", stdin);

    int n;
    cin >> n;
    int d[n + 1][n + 1], route[n + 1];
    bool visited[n + 1];
    //  input
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            cin >> d[i][j];

    // solve
    int curr_city = 1, total_d = 0;
    route[0] = curr_city;
    visited[curr_city] = true;

    for (int i = 2; i <= n; i++)
        visited[i] = false;

    for (int i = 1; i < n; i++)
    {
        int min_d = MAX_INT;
        for (int j = 2; j <= n; j++)
        {
            if (!visited[j] && min_d > d[curr_city][j])
            {
                min_d = d[curr_city][j];
                route[i] = j;
            }
        }
        total_d += min_d;
        visited[route[i]] = true;
        curr_city = route[i];
    }
    route[n] = 1;
    total_d += d[route[n - 1]][1];

    // output
    printf("Tong chi phi=%d\n", total_d);
    printf("%d", route[0]);
    for (int i = 1; i <= n; i++)
        printf("->%d(%d)", route[i], d[route[i - 1]][route[i]]);
    return 0;
}