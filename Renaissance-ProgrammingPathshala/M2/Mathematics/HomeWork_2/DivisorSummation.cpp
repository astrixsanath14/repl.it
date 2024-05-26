#include <bits/stdc++.h>

using namespace std;
#define MAX_COUNT (long)1E7 + 1
long spf[MAX_COUNT];

void sieve(long limit)
{
    for (long i = 0; i <= limit; i++)
    {
        spf[i] = i;
    }
    for (long num = 2; num * num <= limit; num++)
    {
        if (spf[num] == num)
        {
            // cout << "Prime: " << num << "\n";
            for (long j = num * num; j <= limit; j += num)
            {
                if (spf[j] == j)
                {
                    // cout << "Not Prime: " << j * num << "\n";
                    spf[j] = num;
                }
            }
        }
    }
}

void printSieve(long limit)
{
    cout << "Going to print first " << limit << " spf's \n";
    for (int num = 2; num <= limit; num++)
    {
        cout << "num: " << num << " spf: " << spf[num] << "\n";
    }
}

long getSumOfDivisors(long num)
{
    long long sumOfDivisors = -num, divProduct = spf[num], temp = num;
    while (spf[temp] != 1)
    {
        // cout << divProduct << " ";
        sumOfDivisors += (divProduct + (num / divProduct));
        temp /= spf[temp];
        divProduct *= spf[temp];
    }
    // cout << "\n";
    return max(sumOfDivisors, (long long)0);
}

// long getSumOfDivisorsWihtoutSieve(int num)
// {
//     long sumOfDivisors = 0, divisor = 2, div = divisor;
//     while (num != 1)
//     {
//         while (num % divisor == 0)
//         {
//             sumOfDivisors += (divisor + (num / spf[num]));
//             num = num / divisor;
//             div *= divisor;
//         }
//         divisor++;
//     }
//     return sumOfDivisors;
// }

void solve()
{
    long num;
    cin >> num;
    cout << getSumOfDivisors(num) << "\n";
}

int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);
    sieve(MAX_COUNT);
    // printSieve(10);
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}

/*
Renaissance-ProgrammingPathshala/M2/Mathematics/HomeWork_2/DivisorSummation.cpp
1
20


Renaissance-ProgrammingPathshala/M2/Mathematics/HomeWork_2/DivisorSummation.cpp
3
2
10
20

*/
/*
20 = 2^2 * 5^1
20 - 1,2,4,5,10,20
spf(20) = 2
SPF(10) = 2
spf(5) = 5
spf(1) = 1

16 - 1,2,4,8,16
spf(16) = 2
spf(8) = 2
spf(4) = 2
spf(2) = 2

spf(40) = 2
spf(20) = 2
spf(10) = 2
spf(5) = 5

spf(88) = 2
spf(44) = 2
spf(22) = 2
spdf(11) = 11

*/