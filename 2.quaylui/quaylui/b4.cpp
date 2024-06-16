#include <iostream>
using namespace std;

const long MAX = 1000;

int n;
int values[MAX];
int config[MAX];
bool used[MAX];

void swap(int *a, int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void sort()
{
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            if (values[i] > values[j])
            {
                swap(values[i], values[j]);
            }
        }
    }
}

void print_values()
{
    for (int i = 0; i < n; i++)
    {
        cout << "  " << values[config[i]];
    }
    cout << endl;
}

void Try(int k)
{
    for (int i = 0; i < n; i++)
    {
        if (!used[i])
        {
            config[k] = i;
            used[i] = true;

            if (k == n - 1)
            {
                print_values();
            }
            else
            {
                Try(k + 1);
            }

            used[i] = false;
        }
    }
}

int main()
{

    freopen("b4.txt", "r", stdin);

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> values[i];
    }

    sort();

    Try(0);

    return 0;
}