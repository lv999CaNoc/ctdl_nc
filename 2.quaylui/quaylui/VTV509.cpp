#include <iostream>
using namespace std;

// Tóm tắt bài toán:
// Cho bàn cờ 8x8, đặt 1 quân hậu ở vị trí (x, y)
// In các phương án, số nguyên thứ i là chỉ số cột của con hậu tại dòng thứ i.

const int N = 8;

// #BIỂU DIỄN NGHIỆM
// res[i] là chỉ số cột của con hậu tại dòng thứ i.
int res[N + 1];

// #BIỂU DIỄN VỊ TRÍ (i, j) CÓ AN TOÀN?
// a[1..8] để chỉ cột j đã có quân hậu hay chưa?
bool a[N + 1];

// Đường chéo i+j có tập xác định [2..16]
// b[0..14] để chỉ đường chéo i+j-2 đã có quân hậu hay chưa?
bool b[2 * N];

// Đường chéo i-j có tập xác định [-7..7]
// c[0..14] để chỉ đường chéo i-j+7 đã có quân hậu hay chưa?
bool c[2 * N];

// x: vị trí cột
// y: vị trí dòng
int x, y;

void print_solution()
{
    for (int i = 1; i <= N; i++)
        cout << res[i] << " ";
    cout << endl;
}

bool is_safe(int row, int col)
{
    // An toàn khi không có quân hậu nào khác
    // trên cột, trên 2 đường chéo i+j-2 và i-j+7
    return (!a[col] && !b[row + col - 2] && !c[row - col + 7]);
}

void Try(int row)
{
    if (row == N + 1)
    {
        // Nếu row vượt quá N, đã đặt thành công N quân hậu
        print_solution();
    }
    else if (row == y)
    {
        // Nếu row là dòng đã có quân hậu cố định (đặt từ ban đầu)
        // Bỏ qua dòng này và thử tiếp với dòng tiếp theo
        Try(row + 1);
    }
    else
    {
        // Duyệt qua tất cả các cột từ 1 đến N
        for (int col = 1; col <= N; col++)
        {
            if (is_safe(row, col))
            {
                // Đặt hậu
                res[row] = col;

                a[col] = true;
                b[row + col - 2] = true;
                c[row - col + 7] = true;

                // Đệ quy thử đặt quân hậu ở hàng tiếp theo
                Try(row + 1);

                // Xoá quân hậu, quay lại trạng thái trước đó để thử các vị trí khác
                a[col] = false;
                b[row + col - 2] = false;
                c[row - col + 7] = false;
            }
        }
    }
}

int main()
{
    freopen("VTV509.txt", "r", stdin);

    cin >> y >> x;

    // Đặt hậu
    res[y] = x;

    a[x] = true;
    b[y + x - 2] = true;
    c[y - x + 7] = true;

    // Duyệt qua từng dòng, tìm cách đặt quân hậu vào cột
    // Thử với dòng 1
    Try(1);

    return 0;
}