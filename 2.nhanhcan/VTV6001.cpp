#include <iostream>
#include <climits>
using namespace std;

// Tóm tắt bài toán:
// Có n thành phố được đánh số từ 0 đến n-1.
// Giữa 2 thành phố i, j có khoảng cách d[i][j] = d[j][i]
// Muốn đi qua tất cả các thành phố, mỗi thành phố một lần duy nhất
// và quay lại thành phố nơi xuất phát. Quảng đường ngắn nhất

// Số lượng thành phố tối đa
const int MAX_CITY = 1000;

// Số lượng thành phố
int n;

// min_gap là khoảng cách ngắn nhất tìm được
// tmp_gap là khoảng cách tạm thời
int min_gap = INT_MAX, tmp_gap = 0;

// Ma trận khoảng cách giữa các thành phố
int d[MAX_CITY][MAX_CITY];

// Mảng đánh dấu các thành phố đã được thăm
bool visited[MAX_CITY];

void Try(int k, int c)
{
    // Duyệt qua tất cả các thành phố
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            // Cập nhật khoảng cách tạm thời với thành phố i
            // Đánh dấu thành phố i đã được thăm
            tmp_gap += d[c][i];
            visited[i] = true;

            // Nếu đã thăm tất cả các thành phố
            if (k == n)
            {
                // Tính khoảng cách tổng khi quay về thành phố xuất phát
                int curr_gap = tmp_gap + d[i][0];

                if (curr_gap < min_gap)
                {
                    // Cập nhật khoảng cách ngắn nhất
                    min_gap = curr_gap;
                }
            }
            else
            {
                // Cắt nhánh
                // Nếu khoảng cách tạm thời nhỏ hơn khoảng cách ngắn nhất hiện tại
                if (tmp_gap < min_gap)
                {
                    // Tiếp tục thử thăm thành phố tiếp theo
                    Try(k + 1, i);
                }
            }

            // Trả lại trạng thái ban đầu để thử các khả năng khác
            tmp_gap -= d[c][i];
            visited[i] = false;
        }
    }
}

int main()
{
    freopen("VTV6001.txt", "r", stdin);

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            cin >> d[i][j];

        visited[i] = false;
    }

    // Bắt đầu từ thành phố đầu tiên
    Try(1, 0);

    cout << min_gap << endl;
    return 0;
}