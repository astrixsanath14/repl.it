#include<iostream>
using namespace std;

int max_sum(int [], int );

int main()
{
  int t;
  cin>>t;
  while(t--)
  {
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
      cin>>a[i];
    cout<<max_sum(a, n)<<"\n";
  }
}

/*You are required to complete this method*/
int max_sum(int A[],int N)
{
    //Your code here
    int prefixSum[N], suffixSum[N];
    prefixSum[0] = A[0];
    suffixSum[N-1] = A[N-1];
    int sum = 0;
    for(int i=1;i<N;i++)
    {
        prefixSum[i] = prefixSum[i-1] + A[i];
        sum += A[i]*i;
    }
    for(int i=N-2;i>=0;i--)
    {
        suffixSum[i] = suffixSum[i+1] + A[i];
    }
    int maxDiff = 0;
    for(int k=1;k<N;k++)
    {
        int diff = k * (prefixSum[N-k-1]) - (N-k) * suffixSum[N-k];
        maxDiff = max(maxDiff, diff);
    }
    return sum + maxDiff;
}

/*
Renaissance-ProgrammingPathshala/Live_Class/12_Feb_2022/MaxSumInTheConfiguration.cpp
1
4
8 3 1 2

Your Output: 
29

Expected Output: 
29
*/