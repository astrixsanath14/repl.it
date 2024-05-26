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

void printPrimeFactorization(long long n)
{
    long long primeFactorCount = 0, primeFactor = spf[n];
    while (spf[n] != 1)
    {
        if (primeFactor != spf[n])
        {
            cout << primeFactor << " " << primeFactorCount << "\n";
            primeFactorCount = 1;
            primeFactor = spf[n];
        }
        else
        {
            primeFactorCount++;
        }
        n = n / spf[n];
    }
    cout << primeFactor << " " << primeFactorCount << "\n";
}

int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);
    sieve(MAX_LIMIT);
    // printSPF(35);
    long long t;
    cin >> t;
    while (t--)
    {
        long long n;
        cin >> n;
        printPrimeFactorization(n);
    }
}

/*
Renaissance-ProgrammingPathshala/M2/Mathematics/Assignment_2/PrimeFactorization_MultipleQueries.cpp
2
100
35

*/