#include <fstream>
#include <iostream>
#include <math.h>
using namespace std;

long calc(long nums[], int index)
{
    if (index == -1)
    {
        return 0;
    }
    return (nums[index] % 2 == 0)
               ? nums[index] + calc(nums, index - 1)
               : calc(nums, index - 1);
}

int main()
{
    freopen("b8.txt", "r", stdin);

    int n;
    cin >> n;
    long nums[n];
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }

    cout << calc(nums, n - 1) << endl;

    return 0;
}