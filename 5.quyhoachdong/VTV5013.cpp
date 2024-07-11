#include <iostream>
#include <cstring>

using namespace std;

// Tóm tắt bài toán:
// Chuỗi nguồn có m kí tự X1X2...Xm
// Chuỗi đích có n ki tự F1F2...Fn
// 3 phép biến đổi: INSERT, REPLACE, DELETE
// Tìm số ít nhất các phép biến đổi để biến chuỗi X thành chuỗi F?

// In bảng phương án theo định dạng
void print_table(int **f, int m, int n)
{
    cout << "   F";
    for (int i = 0; i <= n; i++)
        printf("%4d", i);
    cout << endl;

    // In các giá trị của bảng phương án
    for (int i = 0; i <= m; i++)
    {
        printf("%4d", i);
        for (int j = 0; j <= n; j++)
            printf("%4d", f[i][j]);

        cout << endl;
    }
}

// Hàm tìm giá trị nhỏ nhất trong ba giá trị
int min3(int x, int y, int z)
{
    int tmp = x < y ? x : y;
    return z < tmp ? z : tmp;
}

int main()
{
    freopen("VTV5013.txt", "r", stdin);

    // m là số ký tự của chuỗi nguồn
    // n là số ký tự của chuỗi đích
    int m, n;
    cin >> m >> n;

    // X là chuỗi nguồn
    // Y là chuỗi đích
    string X, Y;
    cin >> X >> Y;

    // # BẢNG PHƯƠNG ÁN F[0..m][0..n], chứa các giá trị F(i, j)
    // F[i][j]: Số phép biến đổi tối thiểu
    // để biến xâu gồm i ký tự X[0..i-1] thành xâu gồm j ký tự Y[0..j-1]
    int **f = new int *[m + 1];
    for (int i = 0; i < m + 1; i++)
        f[i] = new int[n + 1];

    // # CƠ SỞ CỦA QHĐ
    // F[O,j] là số phép biến đổi biến xâu rỗng thành xâu gồm j ký tự đầu của Y.
    // Cần tối thiểu j phép chèn --> F[0,j] = j
    for (int j = 0; j <= n; j++)
        f[0][j] = j;

    // F[i, 0] là số phép biến đổi biến xâu gồm i ký tự đầu của X thành xâu rỗng.
    // Cần tối thiểu i phép xoá: F[i, 0] = i
    for (int i = 0; i <= m; i++)
        f[i][0] = i;

    // Tính toán các giá trị trong bảng phương án
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (X[i - 1] == Y[j - 1])
            {
                // Nếu ký tự cuối cùng của X và Y giống nhau
                // không cần phép biến đổi
                f[i][j] = f[i - 1][j - 1];
            }
            else
            {
                // Nếu ký tự cuối cùng khác nhau
                // tính các phép biến đổi và lấy giá trị nhỏ nhất
                f[i][j] = min3(f[i][j - 1] + 1,     // Insert
                               f[i - 1][j - 1] + 1, // Replace
                               f[i - 1][j] + 1      // Delete
                );
            }
        }
    }

    print_table(f, m, n);

    // In số phép biến đổi tối thiểu
    printf("%d\n", f[m][n]);

    // Truy vết, tìm các phép biến đổi được sử dụng
    m = X.length(), n = Y.length();
    while (m >= -1 && n >= -1)
    {
        if (X[m - 1] == Y[n - 1])
        {
            // Nếu ký tự cuối cùng của X và Y giống nhau
            // không cần phép biến đổi
            m--;
            n--;
        }
        else
        {
            if (f[m][n] == f[m][n - 1] + 1)
            {
                // Insertion operation
                // Nếu còn ký tự để chèn
                if (n > 0)
                    printf("Insert(%d,%c)\n", m, Y[n - 1]);

                n--;
            }
            else if (f[m][n] == f[m - 1][n - 1] + 1)
            {
                // Replacement operation
                // Nếu còn ký tự để thay thế
                if (n > 0 && m > 0)
                    printf("Replace(%d,%c)\n", m, Y[n - 1]);

                m--;
                n--;
            }
            else
            {
                // Deletion operation
                // Nếu còn ký tự để xóa
                if (m > 0)
                    printf("Delete(%d)\n", m);

                m--;
            }
        }
    }
    return 0;
}
