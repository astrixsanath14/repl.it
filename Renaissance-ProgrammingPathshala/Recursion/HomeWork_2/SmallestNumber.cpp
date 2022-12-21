#include <iostream>
#include <vector>
#define ll long long
using namespace std;

ll getSmallestNumber(vector<ll> &nums, vector<char> &ops, ll opsInd)
{
    if (opsInd == 3)
    {
        return nums[0];
    }
    ll minVal = LLONG_MAX;
    char op = ops[opsInd];
    for (ll i = 0; i < nums.size(); i++)
    {
        for (ll j = i + 1; j < nums.size(); j++)
        {
            vector<ll> tempNums(nums);
            tempNums.erase(tempNums.begin() + j);
            tempNums.erase(tempNums.begin() + i);
            tempNums.push_back(op == '+' ? nums[i] + nums[j] : nums[i] * nums[j]);
            minVal = min(minVal, getSmallestNumber(tempNums, ops, opsInd + 1));
        }
    }
    return minVal;
}

int main()
{
    vector<ll> nums(4);
    vector<char> ops(3);
    for (ll i = 0; i < 4; i++)
    {
        cin >> nums[i];
    }
    for (ll i = 0; i < 3; i++)
    {
        cin >> ops[i];
    }
    ll opsInd = 0;
    cout << getSmallestNumber(nums, ops, opsInd);
    return 0;
}

/*
Renaissance-ProgrammingPathshala/Recursion/HomeWork_2/SmallestNumber.cpp
1 1 1 1
+ + *

Renaissance-ProgrammingPathshala/Recursion/HomeWork_2/SmallestNumber.cpp
2 2 2 2
* * +


*/