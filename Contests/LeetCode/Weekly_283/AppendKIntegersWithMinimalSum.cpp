#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    long long getSumInRange(long long rangeStart, long long rangeEnd)
    {
        cout << "start " << rangeStart << "\n";
        cout << "end " << rangeEnd << "\n";
        rangeStart--;
        long long sum = (rangeEnd * (rangeEnd + 1)) / 2 - (rangeStart * (rangeStart + 1)) / 2;
        cout << "sum " << sum << "\n";
        return sum;
    }

    long long minimalKSum(vector<int> &nums, int k)
    {
        priority_queue<long long, vector<long long>, greater<long long> > pq(nums.begin(), nums.end());
        long long minElement = 1, sumOfKElements = 0;
        while (k > 0)
        {
            if (pq.empty())
                break;
            long long top = pq.top();
            cout << "minElement: " << minElement << " top: " << top << " k: " << k << "\n";
            if (top != minElement)
            {
                cout << "Yes\n";
                long long noOfElements = min((long long)k - 1, (long long)(top - minElement - 1));
                cout << "noOfElements: " << noOfElements << "\n";
                long long endRange = minElement + noOfElements;
                sumOfKElements += getSumInRange(minElement, endRange);
                k -= noOfElements + 1;
                minElement = endRange + 1;
            }
            else
            {
                while (!pq.empty() && pq.top() == top)
                    pq.pop();
                minElement++;
            }
        }
        if (k > 0)
        {
            long endRange = minElement + k - 1;
            sumOfKElements += getSumInRange(minElement, endRange);
        }
        return sumOfKElements;
    }
};

int main()
{
    Solution s;

    vector<int> input{(int)1E9};
    int k = 1E9;
    // vector<int> input{1};
    // int k = 1E9;
    // vector<int> input{1, 4, 25, 10, 25};
    // int k = 2;
    // vector<int> input{5, 6};
    // int k = 6;
    // vector<int> input{1, 2, 3, 4, 8};
    // int k = 3;
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);
    cout << s.minimalKSum(input, k) << " ";
    return 0;
}

/*
Contests/LeetCode/Weekly_283/AppendKIntegersWithMinimalSum.cpp
[96,44,99,25,61,84,88,18,19,33,60,86,52,19,32,47,35,50,94,17,29,98,22,21,72,100,40,84]
35
*/