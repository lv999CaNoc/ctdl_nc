#include <fstream>
#include <iostream>
using namespace std;

// Mô tả bài toán:
// Sắp xếp phân đoạn (QuickSort) tăng dần
// Phần tử chốt là phần tử bên trái cùng của đoạn
// Nửa trái là các phần tử nhỏ hơn hoặc bằng chốt, nửa phải gồm các phần tử lớn hơn chốt.
// In ra trạng thái ban đầu và các trạng thái mỗi khi có một sự hoán đổi 2 phần tử

void print_arr(int arr[], int begin, int end)
{
    for (int i = begin; i <= end; i++)
        cout << arr[i] << " ";
    cout << endl;
}

// Hàm phân đoạn và trả về chỉ số của điểm pivot
int partition(int arr[], int left, int right)
{
    // In ra thông tin phân đoạn hiện tại
    printf("\nPartitioning: left=%d, right=%d\n", left, right);
    print_arr(arr, left, right);

    // Phần tử chốt là phần tử bên trái cùng của đoạn
    int pivot = arr[left];

    // Khởi tạo các chỉ số i và j
    int i = left + 1, j = right;

    while (1)
    {
        // Di chuyển i sang phải cho đến khi tìm thấy phần tử lớn hơn pivot
        while (i <= j && arr[i] <= pivot)
            i++;

        // Di chuyển j sang trái cho đến khi tìm thấy phần tử nhỏ hơn hoặc bằng pivot
        while (i <= j && arr[j] > pivot)
            j--;

        // Nếu i và j gặp nhau hoặc vượt qua nhau, thoát khỏi vòng lặp
        if (i >= j)
            break;

        // Đổi chỗ arr[i] và arr[j]
        swap(arr[i], arr[j]);
        print_arr(arr, left, right);
    }

    // Đổi chỗ pivot với phần tử tại vị trí j
    // Vị trí j chính là chỉ số cuối cùng của phần mảng có giá trị nhỏ hơn hoặc bằng pivot.
    swap(arr[j], arr[left]);
    print_arr(arr, left, right);

    // Trả về chỉ số của điểm pivot sau khi phân đoạn
    return j;
}

// Hàm sắp xếp mảng bằng thuật toán Quick Sort
void quick_sort(int arr[], int left, int right)
{
    // Nếu chỉ số bên trái nhỏ hơn chỉ số bên phải, tiếp tục phân đoạn và sắp xếp
    if (left < right)
    {
        // Phân đoạn mảng và lấy chỉ số của điểm pivot
        int index_pivot = partition(arr, left, right);

        // Đệ quy sắp xếp nửa bên trái của pivot
        quick_sort(arr, left, index_pivot - 1);

        // Đệ quy sắp xếp nửa bên phải của pivot
        quick_sort(arr, index_pivot + 1, right);
    }
}

int main()
{
    freopen("VTV3025.txt", "r", stdin);
    int n;
    cin >> n;
    int arr[n];

    // input
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    print_arr(arr, 0, n - 1);

    quick_sort(arr, 0, n - 1);

    print_arr(arr, 0, n - 1);

    return 0;
}