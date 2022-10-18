#include <iostream>
#include <limits.h>
using namespace std;

bool isPossibleToCompleteInTime(long long &n, long long &products, long long times[], long long timeAvailable)
{
    long long productsCompleted = 0;
    for (long long i = 0; i < n; i++)
    {
        productsCompleted += timeAvailable / times[i];
        if (productsCompleted >= products)
        {
            return true;
        }
    }
    return false;
}

int main()
{
    long long n, products;
    cin >> n >> products;
    long long times[n];
    long long minTime = LLONG_MAX;
    for (long i = 0; i < n; i++)
    {
        cin >> times[i];
        minTime = min(minTime, times[i]);
    }

    long long start = minTime;
    long long end = minTime * products;
    long long minTimeToComleteAllProducts = end;

    while (start <= end)
    {
        long long mid = (start + end) / 2;
        // cout << "mid: " << mid << "\n";
        if (isPossibleToCompleteInTime(n, products, times, mid))
        {
            minTimeToComleteAllProducts = mid;
            end = mid - 1;
        }
        else
        {
            start = mid + 1;
        }
    }
    cout << minTimeToComleteAllProducts << "\n";

    return 0;
}

/*
CSES/FactoryMachines_1620.cpp
3 7
3 2 5

CSES/FactoryMachines_1620.cpp
2 6
2 14
*/