#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;

int n;
vector<long long> appleWeights;
long long totalApplesWieight = 0;

long long splitApples(int pos, long long currSum)
{
    // cout << "pos: " << pos << " currSum: " << currSum << " totalApplesWieight: " << totalApplesWieight << "\n";
    if (pos == n)
    {
        long long sum = totalApplesWieight - currSum;
        long long diff = abs(sum - currSum);
        return diff;
    }

    long long minDiff = min(splitApples(pos + 1, currSum), splitApples(pos + 1, currSum + appleWeights[pos]));
    return minDiff;
}

int main()
{
    cin >> n;
    appleWeights.resize(n);
    for (int i = 0; i < n; i++)
    {
        cin >> appleWeights[i];
        totalApplesWieight += appleWeights[i];
    }
    cout << splitApples(0, 0);
}

/*
Renaissance-ProgrammingPathshala/Live_Class/21_Oct_2022/AppleDivision.cpp
5
3 2 7 4 1

Renaissance-ProgrammingPathshala/Live_Class/21_Oct_2022/AppleDivision.cpp
10
603 324 573 493 659 521 654 70 718 257

*/