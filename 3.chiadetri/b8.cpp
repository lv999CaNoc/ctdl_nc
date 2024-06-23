#include <fstream>
#include <iostream>
using namespace std;

void input(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        cin >> arr[i];
}

void print_arr(int arr[], int begin, int end)
{
    for (int i = begin; i <= end; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int partition(int arr[], int left, int right)
{
    printf("\nPartitioning: left=%d, right=%d\n", left, right);
    print_arr(arr, left, right);

    int pivot = arr[left];
    int i = left + 1, j = right;

    while (1)
    {
        while (i <= j && arr[i] <= pivot)
            i++;
        while (i <= j && arr[j] > pivot)
            j--;
        if (i >= j)
            break;
        swap(arr[i], arr[j]);
        print_arr(arr, left, right);
    }
    swap(arr[i - 1], arr[left]);
    print_arr(arr, left, right);
    return j;
}

void quick_sort(int arr[], int left, int right)
{
    if (left < right)
    {
        int index_pivot = partition(arr, left, right);
        quick_sort(arr, left, index_pivot - 1);
        quick_sort(arr, index_pivot + 1, right);
    }
}

int main()
{
    freopen("b8.txt", "r", stdin);
    int n;
    cin >> n;
    int arr[n];

    input(arr, n);
    print_arr(arr, 0, n - 1);

    quick_sort(arr, 0, n - 1);

    print_arr(arr, 0, n - 1);

    return 0;
}