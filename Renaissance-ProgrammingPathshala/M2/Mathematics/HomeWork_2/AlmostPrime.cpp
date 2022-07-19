#include <bits/stdc++.h>
using namespace std;
#define MAX_LIMIT 1000000 + 5
long long uniquePrimeFactorCount[MAX_LIMIT];
long long almostPrimeNumbersCount[MAX_LIMIT];

void sieve(long long sieveMaxLimit)
{
    // cout << "Creating Sieve of Eratosthens for array size " << sieveMaxLimit << " "<< "\n";
    memset(uniquePrimeFactorCount, 0, sizeof(uniquePrimeFactorCount));
    uniquePrimeFactorCount[0] = 1;
    uniquePrimeFactorCount[1] = 1;
    for (long long i = 2; i <= sieveMaxLimit; i++)
    {
        if (uniquePrimeFactorCount[i] == 0)
        {
            uniquePrimeFactorCount[i] = 1;
            for (long long j = 2; i * j <= sieveMaxLimit; j++)
            {
                uniquePrimeFactorCount[i * j]++;
            }
        }
    }
    // cout << "Completed creating Sieve of Eratosthens for array size " << sieveMaxLimit << " "<< "\n";
}

void preComputeAlmostPrimeNumbersCount(int maxLimitForPreComputation)
{
    almostPrimeNumbersCount[0] = 0;
    almostPrimeNumbersCount[1] = 0;
    for (long long i = 2; i <= maxLimitForPreComputation; i++)
    {
        almostPrimeNumbersCount[i] = almostPrimeNumbersCount[i - 1] + (uniquePrimeFactorCount[i] == 2);
    }
}

void printAlmostPrimeNumbersCount(int n)
{
    // int almostPrimeNumberCount = 0;
    // while (n > 1)
    // {
    //     if (uniquePrimeFactorCount[n] == 2)
    //         almostPrimeNumberCount++;
    //     n--;
    // }
    cout << almostPrimeNumbersCount[n] << "\n";
}

int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);
    sieve(MAX_LIMIT);
    preComputeAlmostPrimeNumbersCount(MAX_LIMIT);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        printAlmostPrimeNumbersCount(n);
    }
    return 0;
}

/*
Renaissance-ProgrammingPathshala/M2/Mathematics/HomeWork_2/AlmostPrime.cpp
2
1
10
*/