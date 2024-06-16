#include <fstream>
#include <iostream>
using namespace std;

int cnt[10];

int max_e(unsigned long n)
{
    if (n < 10)
    {
        cnt[n]++;
        return n;
    }

    int last_e = n % 10;
    cnt[last_e]++;

    int max_e_rest = max_e(n / 10);
    return (max_e_rest > last_e) ? max_e_rest : last_e;
}

void reset()
{
    for (int i = 0; i < 10; i++)
    {
        cnt[i] = 0;
    }
}

int main()
{
    freopen("b3.txt", "r", stdin);

    int n;
    cin >> n;
    unsigned long num;
    for (int i = 0; i < n; i++)
    {
        cin >> num;
        reset();

        printf("%10lu: %d\n", num, cnt[max_e(num)]);
    }

    return 0;
}