#include <bits/stdc++.h>
using namespace std;
#define MAX (int)(1e5 + 1)
vector<int> spf(MAX);

void sieve()
{
    for (int i = 0; i < MAX; i++)
    {
        spf[i] = i;
    }
    for (int i = 2; i * i < MAX; i++)
    {
        if (spf[i] == i)
        {
            for (int j = i; i * j < MAX; j++)
            {
                if (spf[i * j] == i * j)
                {
                    spf[i * j] = i;
                }
            }
        }
    }
}

long getSumOfDivisorsIfNumHasQuatroDivisorsUsingSieve(int num)
{
    if (num < 6) // 2*3 is the smallest num having QuatroDivisors
        return 0;
    int temp = num;
    int spf1 = spf[temp];
    temp /= spf1;
    int spf2 = spf[temp];
    if (spf1 * spf2 == num && spf1 != spf2 && spf2 != 1)
        return (long)(1 + spf1 + spf2 + num);
    return 0;
}

long getSumOfDivisorsIfNumHasQuatroDivisorsUsingBruteForce(int num)
{
    int sum = 0;
    int count = 0;
    for (int i = 1; i * i <= num; i++)
    {
        if (num % i == 0)
        {
            count += 2;
            sum += i + num / i;
            if (i == num / i)
            {
                count--;
                sum -= i;
            }
        }
    }
    return count == 4 ? sum : 0;
}

void compareResultsBetweenSieveAndBruteForce(int num)
{
    int resultFromBruteForce = getSumOfDivisorsIfNumHasQuatroDivisorsUsingBruteForce(num);
    int resultFromSieve = getSumOfDivisorsIfNumHasQuatroDivisorsUsingSieve(num);
    if (resultFromBruteForce != resultFromSieve)
    {
        cout << "Mismatch found for num: " << num << " resultFromBruteForce: " << resultFromBruteForce << " resultFromSieve: " << resultFromSieve;
        exit(0);
    }
}

int main()
{
    sieve();
    for (int num = 1; num < MAX; num++)
    {
        compareResultsBetweenSieveAndBruteForce(num);
    }
    return 0;
}

/*
GoSelect/PP/October_2022/November_2022/QuatroDivisorsSum.cpp
*/