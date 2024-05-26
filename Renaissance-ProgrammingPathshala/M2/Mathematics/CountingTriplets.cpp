#include <bits/stdc++.h>
using namespace std;

int nc3(int n)
{
    return (n * (n - 1) * (n - 2)) / 6;
}

int nc2(int n)
{
    return (n * (n - 1)) / 2;
}

int getDivisibleTriplets(vector<int> &a, int m)
{
    vector<int> reminderFreq(m, 0);
    for (int i : a)
    {
        reminderFreq[i % m]++;
    }
    int pairsDivisibleByK = nc3(reminderFreq[0]);
    for (int i = 1; i < m; i++)
    {
        for (int j = i; j < m; j++)
        {
            int k;
            if ((i + j) % m == 0)
            {
                k = 0;
            }
            else
            {
                k = m - ((i + j) % m);
            }
            if (k < j)
            {
                continue;
            }
            // i <= j <= k

            cout << "i " << i << " j " << j << " k " << k << "\n";

            if (i == j && j == k)
            {
                pairsDivisibleByK += nc3(reminderFreq[i]);
            }
            else if (i == j)
            {
                pairsDivisibleByK += (nc2(reminderFreq[i]) * reminderFreq[k]);
            }
            else if (j == k)
            {
                pairsDivisibleByK += (nc2(reminderFreq[j]) * reminderFreq[i]);
            }
            else
            {
                pairsDivisibleByK += reminderFreq[i] * reminderFreq[j] * reminderFreq[k];
            }
            // i == k will only occur when j == i && j == k which is already handled
        }
    }

    return pairsDivisibleByK;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        int m;
        cin >> m;
        cout << getDivisibleTriplets(a, m) << "\n";
    }
    return 0;
}

/*
Renaissance-ProgrammingPathshala/M2/Mathematics/CountingTriplets.cpp
1
5
2 2 1 7 5
5

freq[1] = 1
freq[2] = 2
freq[5] = 1
freq[7] = 1

m = 5
1 2 2
1 2 7
*/