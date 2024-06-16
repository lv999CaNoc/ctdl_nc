#include <fstream>
#include <iostream>
using namespace std;

bool check(double nums[], int index)
{
    if (index == -1)
    {
        return true;
    }
    return (nums[index] < 0) ? check(nums, index - 1) : false;
}

int main()
{
    freopen("b12.txt", "r", stdin);

    int t;
    cin >> t;
    long n;
    for (int i = 0; i < t; i++)
    {
        cin >> n;
        double nums[n];
        for (int j = 0; j < n; j++)
        {
            cin >> nums[j];
        }

        check(nums, n - 1) ? cout << "Yes" : cout << "No";
        cout << endl;
    }

    return 0;
}