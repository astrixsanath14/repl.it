#include<bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minSwap(int arr[], int n, int k) {
        // Complet the function
        int numberOfElementsLessThanK = 0;
        for(int i=0;i<n;i++)
        {
            numberOfElementsLessThanK+=(arr[i]<=k);
        }
        int windowSize = numberOfElementsLessThanK, ind = 0;
        numberOfElementsLessThanK = 0;
        while(ind < windowSize)
            numberOfElementsLessThanK += (arr[ind++]<=k);
        int numberOfSwaps = windowSize - numberOfElementsLessThanK, minNoOfSwaps = numberOfSwaps;
        // cout<<"initial windowSize: " <<windowSize<<endl;
        // cout<<"initial numberOfSwaps: " << numberOfSwaps<<endl;
        for(ind = windowSize; ind < n; ind++)
        {
            numberOfSwaps += (arr[ind-windowSize] <= k) - (arr[ind]<=k);
            minNoOfSwaps = min(minNoOfSwaps, numberOfSwaps);
        }
        return minNoOfSwaps;
    }
};

int main()
{
  int t,n,k;
  cin>>t;
  while(t--)
  {
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
    {
      cin>>arr[i];
    }
    cin>>k;
    Solution ob;
    cout<<ob.minSwap(arr, n, k)<<endl;
  }
}

/*
Renaissance-ProgrammingPathshala/M2/Arrays_and_Dynamic_Arrays/Assignment_2/Minimum_Swaps_And_K_Together.cpp
1
5
2 1 5 6 3
3
*/