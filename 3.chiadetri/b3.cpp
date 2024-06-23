#include <fstream>
#include <iostream>
using namespace std;

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
        if (arr_one[index_one] < arr_two[index_two])
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

void print_arr(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main()
{
    freopen("b3.txt", "r", stdin);
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    merge_sort(arr, 0, n - 1);

    print_arr(arr, n);
    return 0;
}