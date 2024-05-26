#include <iostream>
#define MAX (int)(5 * 1e2 + 5)
#define MOD (long)(1e9 + 7)
#define ull long
using namespace std;

ull cnt[MAX];
// cnt[500] = 591137401
void catalan()
{
    cnt[0] = 1;
    cnt[1] = 1;
    cnt[2] = 2;
    for (int i = 3; i < MAX; i++)
    {
        for (int j = 0; j < i; j++)
        {
            // cnt[i] += cnt[j]*cnt[i-1-j];
            cnt[i] = (cnt[i] + cnt[j] * cnt[i - 1 - j]) % MOD;
        }
        // cout<<i<<" "<<cnt[i]<<"\n";
    }
    // cout<<cnt[MAX-1];
}

int main()
{
    catalan();
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        if (n % 2 == 0)
        {
            ull res = (cnt[n / 2]) % MOD;
            cout << res << "\n";
        }
        else
            cout << "-1\n";
    }
    return 0;
}