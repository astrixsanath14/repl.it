#include <iostream>
#include <vector>
using namespace std;

long gcd(long a, long b)
{
    if (a % b == 0)
        return b;
    return gcd(b, a % b);
}

int main()
{
    int n;
    cin >> n;
    vector<long> prefixGCD(n, -1), arr(n);
    int i = 0;
    while (i < n)
    {
        cin >> arr[i];
        if (i == 0)
            prefixGCD[i] = arr[i];
        else
            prefixGCD[i] = gcd(prefixGCD[i - 1], arr[i]);
        i++;
    }
    long maxGCD = prefixGCD[n - 2], suffixGCD = arr[n - 1];
    for (int i = n - 2; i > 0; i--)
    {
        maxGCD = max(maxGCD, gcd(suffixGCD, prefixGCD[i - 1]));
        suffixGCD = gcd(suffixGCD, arr[i]);
    }
    maxGCD = max(maxGCD, suffixGCD);
    cout << maxGCD << "\n";
}

/*
Renaissance-ProgrammingPathshala/Live_Class/17_Oct_2022/GCDOnBlackboard.cpp
3
7 6 8

Renaissance-ProgrammingPathshala/Live_Class/17_Oct_2022/GCDOnBlackboard.cpp
3
6 8 7

Renaissance-ProgrammingPathshala/Live_Class/17_Oct_2022/GCDOnBlackboard.cpp
3
12 15 18

Renaissance-ProgrammingPathshala/Live_Class/17_Oct_2022/GCDOnBlackboard.cpp
2
1000000000 1000000000

*/