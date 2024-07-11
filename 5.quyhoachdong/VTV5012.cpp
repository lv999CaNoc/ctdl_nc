#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

// Tóm tắt bài toán:
// Có n gói đồ vật, gói thứ i có khối lượng là A[i], giá trị là C[i]
// Khối lượng tối đa là M.
// Lấy những gói nào để có thể mang được tổng giá trị của các đồ vật là lớn nhất?

#define MAX_N 1000

// n là số lượng gói hàng
// M là khối lượng tối đa của túi
int n, M;

// A[i] là khối lượng của đồ vật thứ i.
// C[i] là giá trị của đồ vật thứ i.
int A[MAX_N], C[MAX_N];

// In bảng phương án theo định dạng
void print_table(const vector<vector<int>> &F)
{
    printf("   C   A i/v");
    for (int i = 0; i <= M; i++)
        printf("%4d", i);
    printf("\n");

    // In các giá trị của bảng phương án
    for (int i = 0; i <= n; i++)
    {
        if (i == 0)
            printf("           0");
        else
            printf("%4d%4d%4d", C[i], A[i], i);

        for (int j = 0; j <= M; j++)
            printf("%4d", F[i][j]);

        printf("\n");
    }
}

// Truy vết các gói hàng đã chọn
void trace_back(const vector<vector<int>> &F)
{
    int v = M;

    // Lưu lại các gói được chọn
    vector<int> selected_items;

    // Truy vết ngược lại từ F[n][M] để tìm các gói đã chọn
    for (int i = n; i > 0; i--)
    {
        if (F[i][v] != F[i - 1][v])
        {
            // Gói thứ i được chọn
            selected_items.push_back(i);
            v = v - A[i];
        }
    }

    // In ra các gói đã chọn
    for (int i = selected_items.size() - 1; i >= 0; i--)
        printf("%d(%d,%d) ", selected_items[i], A[selected_items[i]], C[selected_items[i]]);
}

void solve(int A[], int C[])
{
    // F[0..n][0..M]: Bảng phương án, chứa các giá trị F(i, v)
    vector<vector<int>> F(n + 1, vector<int>(M + 1));

    // Cơ sở của QHĐ
    for (int i = 0; i < M + 1; i++)
        F[0][i] = 0;

    // Tính toán các giá trị trong bảng phương án
    for (int i = 1; i <= n; i++)
    {
        for (int v = 0; v <= M; v++)
        {
            // Không chọn gói thứ i
            F[i][v] = F[i - 1][v];

            // Chọn gói thứ i nếu tối ưu hơn
            if (A[i] <= v && F[i][v] < F[i - 1][v - A[i]] + C[i])
                F[i][v] = F[i - 1][v - A[i]] + C[i];
        }
    }

    print_table(F);

    printf("%d\n", F[n][M]);

    trace_back(F);
}

int main()
{
    freopen("VTV5012.txt", "r", stdin);

    cin >> n >> M;

    // Nhập vào mảng A[] và C[]
    for (int i = 1; i <= n; i++)
        cin >> A[i];
    for (int i = 1; i <= n; i++)
        cin >> C[i];

    solve(A, C);
}