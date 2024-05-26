#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

int findWeakInd(vector<int> nums, int n)
{
    int low = 0, high = n - 1;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (nums[mid] == 1)
        {
            low = mid + 1;
        }
        else
        {
            if (mid > 0 && nums[mid - 1] == 1)
            {
                return mid;
            }
            high = mid - 1;
        }
    }
    return low;
}

int main()
{
    int r, c;
    cin >> r >> c;
    vector<vector<int> > nums(r, vector<int>(c));
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            cin >> nums[i][j];
        }
    }
    vector<pair<int, int> > weakInd(r);
    for (int i = 0; i < r; i++)
    {
        weakInd[i] = {findWeakInd(nums[i], c), i};
    }
    sort(weakInd.begin(), weakInd.end(), [](const pair<int, int> &a, const pair<int, int> &b) -> bool
         { return a.first < b.first || (a.first == b.first && a.second < b.second); });
    for (int i = 0; i < r; i++)
    {
        cout << weakInd[i].second << " ";
    }
    return 0;
}