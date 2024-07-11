#include <iostream>

using namespace std;

#define MAX_INT 2147483640

// Mô tả bài toán:
// Cho dãy A gồm n số nguyên và một số nguyên dương k.
// Tìm một dãy con dài nhất có tổng các số chia hết cho số k.

void print_table(int **f, int n, int k)
{
    cout << " n/t";
    for (int i = 0; i < k; i++)
        printf("%4d", i);
    cout << endl;

    // In từng dòng của bảng phương án
    for (int i = 0; i <= n; i++)
    {
        printf("%4d", i);
        for (int t = 0; t < k; t++)
        {
            // Nếu giá trị là MAX_INT thì in "+00" để biểu thị vô cực
            if (f[i][t] == MAX_INT)
                cout << " +00";
            else
                printf("%4d", f[i][t]);
        }

        cout << endl;
    }
}

// Hàm tính hiệu modulo k của hai số x và y
int sub(int x, int y, int k)
{
    int tmp = (x - y) % k;
    return tmp >= 0 ? tmp : tmp + k;
}

int main()
{

    // freopen("VTV5011.txt", "r", stdin);

    int n, k, sum = 0;
    cin >> n >> k;

    int A[n];
    for (int i = 0; i < n; i++)
    {
        cin >> A[i];
        sum += A[i];
    }

    if (sum % k == 0)
    {
        cout << "Day da cho thoa man yeu cau." << endl
             << "Tong =" << sum;
        return 0;
    }

    // # Bảng phương án
    // f[i, t] là số phần tử tối thiểu phải chọn trong dãy a[1..i] để có tổng chia k dư t.
    // Nếu không có phương án chọn coi f[i, t] = +00
    int **f = new int *[n + 1];
    for (int i = 0; i < n + 1; i++)
        f[i] = new int[k];

    // Cơ sở của quy hoạch động
    // Không chọn phần tử nào thì tổng chia k dư 0
    f[0][0] = 0;
    // Các trường hợp Không chọn phần tử nào mà tổng chia k dư t
    // là không thể đạt được -> +00
    for (int t = 1; t < k; t++)
        f[0][t] = MAX_INT;

    // Tính toán bảng phương án theo quy hoạch động
    for (int i = 1; i <= n; i++)
    {
        for (int t = 1; t < k; t++)
        {
            // Nếu không chọn phần tử a[i-1]
            int option1 = f[i - 1][t];
            // Nếu chọn phần tử a[i-1]
            int option2 = f[i - 1][sub(t, A[i - 1], k)] + 1;

            // Chọn phương án tốt hơn (ít phần tử hơn)
            f[i][t] = (option1 < option2) ? option1 : option2;
        }
    }
    print_table(f, n, k);

    cout << "Chieu dai day con: " << n - f[n][sum % k] << endl;

    // Truy vết để tìm dãy con thỏa mãn yêu cầu
    int t = sum % k;
    sum = 0;
    for (int i = n; i >= 1; i--)
    {
        if (f[i][t] == f[i - 1][t])
        {
            // In ra các phần tử của dãy con
            printf("a[%d]=%d;", i, A[i - 1]);
            sum += A[i - 1];
        }
        else
            t = sub(t, A[i - 1], k);
    }

    cout << endl
         << "Tong =" << sum;

    return 0;
}