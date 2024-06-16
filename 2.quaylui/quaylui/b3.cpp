#include <iostream>
using namespace std;

const long MAX = 100000;

int n;
int arr[MAX];
bool used[MAX] = {};

void print_arr()
{
    for (int i = 0; i < n; i++)
    {
        cout << "  " << arr[i];
    }
    cout << endl;
}

void Try(int k)
{
    if (k == n)
    {
        print_arr();
        return;
    }

    for (int i = n; i >= 1; i--)
    {
        if (!used[i])
        {
            arr[k] = i;
            used[i] = true;

            Try(k + 1);

            used[i] = false;
        }
    }
}

int main()
{

    freopen("b3.txt", "r", stdin);

    cin >> n;
    Try(0);

    return 0;
}