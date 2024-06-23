#include <fstream>
#include <iostream>
using namespace std;

void input(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        cin >> arr[i];
}

void print_arr(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int partition(int arr[], int start, int end)
{
    int pivot = arr[end];
    int i = start - 1;

    for (int j = start; j <= end; j++)
    {
        if (arr[j] > pivot)
        {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[end]);
    return i + 1;
}

void quick_sort(int arr[], int start, int end)
{
    if (start >= end)
        return;

    int index_pivot = partition(arr, start, end);
    quick_sort(arr, start, index_pivot - 1);
    quick_sort(arr, index_pivot + 1, end);
}

int main()
{
    freopen("b7.txt", "r", stdin);
    int n;
    cin >> n;
    int arr[n];

    input(arr, n);
    quick_sort(arr, 0, n - 1);
    print_arr(arr, n);

    return 0;
}