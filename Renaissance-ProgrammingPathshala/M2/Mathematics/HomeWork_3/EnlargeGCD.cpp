#include <iostream>
#include <map>
#include <set>
#include <vector>
#define LIMIT (int)(1.5e7 + 5)
using namespace std;

long spf[LIMIT];

bool cmp(pair<string, int> &a, pair<string, int> &b)
{
    if (a.second == b.second)
    {
        return a.first < b.first;
    }
    return a.second < b.second;
}

void sieve(long limit)
{
    spf[0] = -1;
    spf[1] = -1;
    for (long i = 2; i <= limit; i++)
    {
        spf[i] = i;
    }
    for (long num = 2; num * num <= limit; num++)
    {
        if (spf[num] == num)
        {
            // cout << "Prime: " << num << "\n";
            for (long j = num; j * num <= limit; j++)
            {
                if (spf[j * num] == j * num)
                {
                    // cout << "Not Prime: " << j * num << "\n";
                    spf[j * num] = num;
                }
            }
        }
    }
}

int getDivisibleElements(vector<int> &elements, int divisor)
{
    int count = 0;
    for (int i = 0; i < elements.size(); i++)
    {
        count += elements[i] % divisor == 0;
    }
    return count;
}

int gcd(int a, int b)
{
    if (a % b == 0)
        return b;
    return gcd(b, a % b);
}

int main()
{
    int t;
    cin >> t;
    sieve(LIMIT);
    while (t--)
    {
        int n;
        cin >> n;
        map<int, int> freq;
        vector<int> nums(n);
        int numsGCD = -1;
        for (int i = 0; i < n; i++)
        {
            cin >> nums[i];
            freq[nums[i]]++;
            if (numsGCD == -1)
                numsGCD = nums[i];
            else if (numsGCD != 1)
                numsGCD = gcd(numsGCD, nums[i]);
        }

        int result = 0;

        if (freq.size() == 1)
        {
            result = -1;
        }
        else
        {
            // code the logic here daa
            //  vector<pair<int,int>> primeFactorsWithFreq;
            //  for (auto& it : primeFactFreqMap) {
            //  	primeFactorsWithFreq.push_back(it);
            //  }

            map<int, int> primeFactFreqMap;
            // set<int> uniqueNums;
            int maxOccurringPrimeFactor = -1;
            // cout<<"numsGCD: "<<numsGCD<<"\n";
            for (int i = 0; i < n; i++)
            {
                int num = nums[i] / numsGCD;
                // uniqueNums.insert(num);
                while (num > 1)
                {
                    int spfOfNum = spf[num];
                    primeFactFreqMap[spfOfNum]++;
                    maxOccurringPrimeFactor = max(maxOccurringPrimeFactor, primeFactFreqMap[spfOfNum]);
                    while (num % spfOfNum == 0)
                    {
                        num /= spfOfNum;
                    }
                }
            }
            result = n - maxOccurringPrimeFactor;
        }
        cout << result << "\n";
    }
    return 0;
}

/*
if 1 is present, all 1s should def. be removed

2 3 4
2 - 2^1
3 - 3^1
4 - 2^2

total prime factorization - 2^3 3^1
if we remove 3^1, we can increase gcd

5 7 25
5 - 5^1
7 - 7^1
25 - 5^2

total prime factorization - 5^3 7^1
*/