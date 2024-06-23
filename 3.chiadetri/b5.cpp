#include <fstream>
#include <iostream>
using namespace std;

void input(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        cout << " " << arr[i];
    }
}

void print_divide(int arr[], int start, int mid, int end)
{
    printf("\nDivide: %d --> %d and %d --> %d\n", start, mid, mid + 1, end);
    for (int i = start; i <= end; i++)
    {
        cout << arr[i] << " ";
        if (i == mid)
        {
            cout << ":: ";
        }
    }
}

void print_merge(int arr[], int left, int mid, int right)
{
    printf("\nMerge: %d --> %d and %d --> %d\n", left, mid, mid + 1, right);
    for (int i = left; i <= right; i++)
    {
        cout << arr[i] << " ";
    }
    printf("\n");
}

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

    print_merge(arr, left, mid, right);
}

void merge_sort(int arr[], int start, int end)
{
    if (start >= end)
        return;

    int mid = start + (end - start) / 2;
    print_divide(arr, start, mid, end);

    merge_sort(arr, start, mid);
    merge_sort(arr, mid + 1, end);
    merge(arr, start, mid, end);
}

int main()
{
    freopen("b5.txt", "r", stdin);
    int n;
    cin >> n;
    int arr[n];

    input(arr, n);

    merge_sort(arr, 0, n - 1);
    return 0;
}