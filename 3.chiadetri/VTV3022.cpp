#include <fstream>
#include <iostream>
using namespace std;

// Mô tả bài toán:
// In ra quá trình thực hiện MergeSort
// trong đó nửa trái được sắp xếp trước, nửa phải được sắp xếp sau

void print_divide(int arr[], int start, int mid, int end)
{
    printf("\nDivide: %d --> %d and %d --> %d\n", start, mid, mid + 1, end);
    for (int i = start; i <= end; i++)
    {
        cout << arr[i] << " ";
        if (i == mid)
            cout << ":: ";
    }
}

void print_merge(int arr[], int left, int mid, int right)
{
    printf("\nMerge: %d --> %d and %d --> %d\n", left, mid, mid + 1, right);
    for (int i = left; i <= right; i++)
        cout << arr[i] << " ";

    printf("\n");
}

// Hàm trộn hai mảng con đã được sắp xếp thành một mảng duy nhất
void merge(int arr[], int left, int mid, int right)
{
    // Tính độ dài của hai mảng con
    int length_arr_one = mid - left + 1;
    int length_arr_two = right - mid;

    // Tạo hai mảng con tạm thời
    int arr_one[length_arr_one], arr_two[length_arr_two];

    // Sao chép dữ liệu vào các mảng con tạm thời
    for (int i = 0; i < length_arr_one; i++)
        arr_one[i] = arr[left + i];
    for (int i = 0; i < length_arr_two; i++)
        arr_two[i] = arr[mid + 1 + i];

    // Khởi tạo các chỉ số ban đầu của hai mảng con và mảng chính
    int index = left, index_one = 0, index_two = 0;

    // Trộn các mảng con vào mảng chính theo thứ tự sắp xếp
    while (index_one < length_arr_one && index_two < length_arr_two)
    {
        // Sắp xếp tăng dần
        if (arr_one[index_one] < arr_two[index_two])
            arr[index] = arr_one[index_one++];
        else
            arr[index] = arr_two[index_two++];

        index++;
    }

    // Sao chép các phần tử còn lại của mảng con arr_one (nếu có)
    while (index_one < length_arr_one)
        arr[index++] = arr_one[index_one++];

    // Sao chép các phần tử còn lại của mảng con arr_two (nếu có)
    while (index_two < length_arr_two)
        arr[index++] = arr_two[index_two++];

    print_merge(arr, left, mid, right);
}

// Hàm sắp xếp mảng bằng thuật toán Merge Sort
void merge_sort(int arr[], int start, int end)
{
    // Điều kiện dừng của đệ quy (khi mảng con chỉ còn một phần tử)
    if (start >= end)
        return;

    // Tìm điểm giữa của mảng
    int mid = start + (end - start) / 2;
    print_divide(arr, start, mid, end);

    // Gọi đệ quy để sắp xếp nửa bên trái của mảng trước
    merge_sort(arr, start, mid);

    // Gọi đệ quy để sắp xếp nửa bên phải của mảng sau
    merge_sort(arr, mid + 1, end);

    // Trộn hai nửa mảng đã được sắp xếp
    merge(arr, start, mid, end);
}

int main()
{
    freopen("VTV3022.txt", "r", stdin);
    int n;
    cin >> n;
    int arr[n];

    // input
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        cout << " " << arr[i];
    }

    merge_sort(arr, 0, n - 1);

    return 0;
}