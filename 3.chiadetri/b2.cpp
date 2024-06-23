#include <fstream>
#include <iostream>
using namespace std;

void print_arr(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
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

int interpolation_search(int arr[], int left, int right, int target)
{
    while (left <= right && target >= arr[left] && target <= arr[right])
    {
        int search_index = left + (right - left) * (target - arr[left]) / (arr[right] - arr[left]);

        if (arr[search_index] == target)
            return search_index;

        if (arr[search_index] > target)
            right = search_index - 1;
        else
            left = search_index + 1;
    }
    return -1;
}

int main()
{
    freopen("b2.txt", "r", stdin);
    int d, n, x;
    cin >> d;
    int arr[d];
    for (int i = 0; i < d; i++)
    {
        cin >> arr[i];
    }

    merge_sort(arr, 0, d - 1);
    print_arr(arr, d);

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        cout << interpolation_search(arr, 0, d - 1, x) << endl;
    }

    return 0;
}