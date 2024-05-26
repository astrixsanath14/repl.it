#include <bits/stdc++.h>
using namespace std;
int main()
{

    int n;
    cin >> n;
    vector<int> num(n);
    for (int i = 0; i < n; i++)
    {
        cin >> num[i];
    }

    // maxLen stores the max({x1,x2,, xk}).
    int maxLen = 0;
    // cnt stores the current length of the non-decreasing array.
    int cnt = 1;

    for (int i = 1; i < n; i++)
    {
        if (num[i] >= num[i - 1])
        {
            cnt += 1;
        }
        else
        {
            // Update the maxLen and initialize the cnt.
            maxLen = max(maxLen, cnt);
            cnt = 1;
        }
    }
    maxLen = max(maxLen, cnt);

    cout << n - maxLen;

    return 0;
}
