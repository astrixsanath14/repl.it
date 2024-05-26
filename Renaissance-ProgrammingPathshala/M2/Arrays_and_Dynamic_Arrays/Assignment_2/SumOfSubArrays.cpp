#include<iostream>
using namespace std;
#define MOD (int)1E9+7
class Solution{   
public:
    long long subarraySum(long long a[], long long n)
    {
        // Your code goes here
        long ans = 0;
        for(int i=0;i<n;i++)
        {
            ans += (i+1) * (n-i) * a[i];
            ans %= MOD;
        }
        return ans;
    }
};

int main()
{
  int t;
  cin>>t;
  while(t--)
  {
    long n;
    cin>>n;
    long long a[n];
    for(int i=0;i<n;i++)
    {
      cin>>a[i];
    }
    Solution ob;
    cout<<ob.subarraySum(a, n)<<endl;
  }
  return 0;
}
/*
Renaissance-ProgrammingPathshala/M2/Arrays_and_Dynamic_Arrays/Assignment_2/SumOfSubArrays.cpp
1
3
1 2 3
*/