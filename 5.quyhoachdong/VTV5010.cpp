#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
using namespace std;

#define MAX_INT 2147483647
#define MIN_INT -2147483648

void parseToArr(string s, int A[]);

void solve(int a[], int n)
{
    int L[n + 2], T[n + 1];
    // L[i]: độ dài dãy con tăng dài nhất bắt đầu tại a[i]
    // T[i]: là vị trí của phần tử đứng sau a[i] trong dãy con tăng dài nhất

    // Thêm 2 phần tử a[0], a[n+1] vào mảng
    a[0] = MIN_INT;
    a[n + 1] = MAX_INT;

    L[n + 1] = 1; // Cơ sở quy hoạch động: L[n+1] = 1, dãy con bắt đầu từ a[n+1] có độ dài là 1 vì nó chỉ chứa a[n+1]
    printf("L[%d]=%d\n", n + 1, 1);

    // Duyệt ngược từ cuối mảng về đầu mảng
    for (int i = n; i >= 0; i--)
    {
        int j_max = n + 1;
        printf("jmax=n+1=%d+1=%d\n", n, j_max);

        // Duyệt tất cả các phần tử sau a[i]
        for (int j = i + 1; j <= n + 1; j++)
        {
            // Nếu a[j] > a[i] và L[j] > L[j_max], cập nhật j_max
            if ((a[j] > a[i]) && (L[j] > L[j_max]))
            {
                printf("i=%d,j=%d,jmax=%d,a[%d]>a[%d] &&L[%d]>L[%d]:\n", i, j, j_max, j, i, j, j_max);

                j_max = j;
                printf("jmax=j=%d\n", j);
            }
        }

        L[i] = L[j_max] + 1; // Lưu độ dài dãy con tăng dài nhất bắt đầu tại a[i]
        printf("L[%d]=L[%d]+1=%d\n", i, j_max, L[i]);

        T[i] = j_max; // Lưu vết: phần tử đứng sau a[i] trong dãy con tăng dài nhất là a[j_max]
        printf("T[%d]=jmax=%d\n", i, j_max);
    }

    // in kết quả cuối cùng
    printf("%d\n", L[0] - 2);
    int i = T[0];
    while (i != n + 1)
    {
        printf("a[%d]=%d;", i, a[i]);
        i = T[i];
    }
    cout << endl;
}

void parseToArr(string s, int A[])
{
    stringstream ss(s);
    int i = 1;
    string word;
    while (ss >> word)
        A[i++] = stoi(word);
}

int main()
{
    freopen("VTV5010.txt", "r", stdin);
    // Khai báo biến và input
    int n;
    cin >> n;
    int a[n + 2];

    string s;
    cin.ignore();
    getline(cin, s);

    // Nếu chuỗi rỗng, sử dụng chuỗi ban đầu
    if (s.empty())
    {
        int tmp[] = {1, 2, 3, 4, 9, 10, 5, 6, 7};
        int index = 0;

        for (int i = 1; i <= n; i++)
            a[i] = tmp[index++];
    }
    else
        parseToArr(s, a);

    // Giải quyết bài toán
    solve(a, n);

    return 0;
}