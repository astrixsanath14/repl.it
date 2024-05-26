#include <bits/stdc++.h>
using namespace std;
#define MAX_LIMIT 1000000 + 5
long long spf[MAX_LIMIT];
long long primeCountArray[MAX_LIMIT];

void initialisePrimeCountArray(long long sieveMaxLimit)
{
    memset(primeCountArray, 0, sizeof(primeCountArray));
    for (long long i = 2; i <= sieveMaxLimit; i++)
    {
        primeCountArray[i] = primeCountArray[i - 1] + (i == spf[i]);
    }
}

void sieve(long long sieveMaxLimit)
{
    // cout << "Creating Sieve of Eratosthens for array size " << sieveMaxLimit << " " << "\n";
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
    initialisePrimeCountArray(sieveMaxLimit);
}

void printSPF(long long n)
{
    for (long long i = 2; i <= n; i++)
    {
        cout << i << " " << spf[i] << " " << boolalpha << (spf[i] == i) << " " << primeCountArray[i] << "\n";
    }
}

void printNumberOfPrimesWithinRange(long long n)
{
    // cout << "\n";
    cout << primeCountArray[n] << "\n";
}

int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);
    // cout << MAX_LIMIT << "\n";
    sieve(MAX_LIMIT);
    long long t;
    cin >> t;
    while (t--)
    {
        long long n;
        cin >> n;
        printNumberOfPrimesWithinRange(n);
    }
    // printSPF(100);
}

/*
Renaissance-ProgrammingPathshala/M2/Mathematics/Assignment_2/CountingPrimes.cpp
4
1
11
1000000
0
*/