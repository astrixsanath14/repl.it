#include <bits/stdc++.h>
using namespace std;
#define MAX_LIMIT 1000000 + 5
long long spf[MAX_LIMIT];

void sieve(long long sieveMaxLimit)
{
    // cout << "Creating Sieve of Eratosthens for array size " << sieveMaxLimit << " "<< "\n";
    memset(spf, 0, sizeof(spf));
    spf[0] = 1;
    spf[1] = 1;
    for (long long i = 2; i <= sieveMaxLimit; i++)
    {
        if (spf[i] == 0)
        {
            spf[i] = i;
            for (long long j = i; i * j <= sieveMaxLimit; j++)
            {
                if (spf[i * j] == 0)
                    spf[i * j] = i;
            }
        }
    }
    // cout << "Completed creating Sieve of Eratosthens for array size " << sieveMaxLimit << " "<< "\n";
}

void printUniquePrimeCount(int a)
{
    int primeFactor = spf[a], uniquePrimeFactorCount = spf[a] != 1;
    while (spf[a] != 1)
    {
        // cout << spf[a] << " ";
        if (primeFactor != spf[a])
        {
            primeFactor = spf[a];
            uniquePrimeFactorCount++;
        }
        a = a / spf[a];
    }
    // cout << "\n";
    cout << uniquePrimeFactorCount << " ";
}

int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);
    sieve(MAX_LIMIT);
    int t;
    cin >> t;
    while (t--)
    {
        int n, a;
        cin >> n;
        while (n--)
        {
            cin >> a;
            printUniquePrimeCount(a);
        }
        cout << "\n";
    }
    return 0;
}

/*
Renaissance-ProgrammingPathshala/M2/Mathematics/Assignment_2/CountOfDivisorsForMultipleQueries.cpp
1
3
10 12 1000001
*/