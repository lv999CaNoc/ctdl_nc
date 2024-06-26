#include <fstream>
#include <iostream>
using namespace std;

const int MAX = 100005;

void merge(int arr[], int left, int mid, int right)
{
    int length_arr_one = mid - left + 1, length_arr_two = right - mid;
    int arr_one[length_arr_one], arr_two[length_arr_two];

    for (int i = 0; i < length_arr_one; i++)
        arr_one[i] = arr[left + i];
    for (int i = 0; i < length_arr_two; i++)
        arr_two[i] = arr[mid + 1 + i];

    int index = left, index_one = 0, index_two = 0;
    while (index_one < length_arr_one && index_two < length_arr_two)
    {
        if (arr_one[index_one] > arr_two[index_two])
        {
            arr[index] = arr_one[index_one++];
        }
        else
        {
            arr[index] = arr_two[index_two++];
        }
        index++;
    }

    while (index_one < length_arr_one)
    {
        arr[index++] = arr_one[index_one++];
    }

    while (index_two < length_arr_two)
    {
        arr[index++] = arr_two[index_two++];
    }
}

void merge_sort(int arr[], int start, int end)
{
    if (start >= end)
        return;

    int mid = start + (end - start) / 2;
    merge_sort(arr, start, mid);
    merge_sort(arr, mid + 1, end);
    merge(arr, start, mid, end);
}

void solve(int t[], int N)
{
    int res = 1;
    for (int i = 1; i <= N; i++)
    {
        int total_t = i + t[i] + 1;
        if (res < total_t)
        {
            res = total_t;
        }
    }
    cout << res << endl;
}

int main()
{
    freopen("b4.txt", "r", stdin);
    int N;
    int t[MAX];
    cin >> N;
    for (int i = 1; i <= N; i++)
    {
        cin >> t[i];
    }

    // sort descending
    merge_sort(t, 1, N);

    solve(t, N);

    return 0;
}