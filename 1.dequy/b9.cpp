#include <fstream>
#include <iostream>
#include <math.h>
using namespace std;

int cnt(double nums[], int index)
{
    if (index == -1)
    {
        return 0;
    }
    return (nums[index] > 0)
               ? cnt(nums, index - 1) + 1
               : cnt(nums, index - 1);
}

int main()
{
    freopen("b9.txt", "r", stdin);

    int n;
    cin >> n;
    double nums[n];
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }

    cout << cnt(nums, n-1) << endl;

    return 0;
}