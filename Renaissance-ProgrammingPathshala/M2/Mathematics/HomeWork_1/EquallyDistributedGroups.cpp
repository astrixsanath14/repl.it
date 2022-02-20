#include <iostream>
#include <limits.h>
#include <string.h>
using namespace std;

int getGCD(int a, int b)
{
    int x = max(a, b), y = min(a, b);
    int gcd;
    if (y == 0)
    {
        gcd = x;
    }
    else
    {
        while (x % y != 0)
        {
            x = x % y;
            int temp = y;
            y = min(x, temp);
            x = max(x, temp);
        }
        gcd = y;
    }
    return gcd;
}

int main()
{
    // your code goes here
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int a[n];
        int freq[10001];
        memset(freq, 0, sizeof(freq));
        int minX;
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            freq[a[i]]++;
        }
        minX = freq[a[0]];
        freq[a[0]] = 0;
        for (int i = 1; i < n; i++)
        {
            if (freq[a[i]])
                minX = getGCD(minX, freq[a[i]]);
            freq[a[i]] = 0;
        }
        bool possible = minX == 1 ? false : true;
        cout << boolalpha << possible << "\n";
    }
    return 0;
}

/*
Renaissance-ProgrammingPathshala/M2/Mathematics/HomeWork_1/EquallyDistributedGroups.cpp
3
8
1 2 3 4 4 3 2 1
8
1 1 1 2 2 2 3 3
1
1
*/