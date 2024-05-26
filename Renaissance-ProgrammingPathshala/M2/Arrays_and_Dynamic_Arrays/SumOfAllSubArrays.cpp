#include<iostream>
#include <bits/stdc++.h>
using namespace std;

void solveWithBruteForce(int n,int arr[])
{
  int totalSum = 0;
  for(int i=0;i<n;i++)
  {
    for(int j=i;j<n;j++)
    {
      int sum = 0;
      for(int t=i;t<=j;t++)
      {
        sum+=arr[t];
      }
      totalSum+=sum;
    }
  }
  cout<<"totalSum: " <<totalSum <<endl;
}

void solveWithBruteForceAndPrefixSuffixSum(const int n,int arr[])
{
  int totalSum = 0;
  int prefixSum[n];
  prefixSum[0] = arr[0];
  for(int i=1;i<n;i++)
    prefixSum[i] = prefixSum[i-1] + arr[i];
    
  for(int i=0;i<n;i++)
  {
    for(int j=i;j<n;j++)
    {
      int sum = prefixSum[j] - prefixSum[i-1];
      totalSum+=sum;
    }
  }
  cout<<"totalSum: " <<totalSum <<endl;
}

void solveOptimally(const int n,int arr[])
{
  int totalSum = 0;
  for(int i=0;i<n;i++)
  {
    //starting point of subarrays: 0 to i
    //ending point of subarrays: i to n-1
    int totalOccurrence = arr[i] * (i+1) * (n-i);
    totalSum+=totalOccurrence;
  }
  cout<<"totalSum: " <<totalSum <<endl;
}

int main()
{
  int n;
  cin>>n;
  int arr[n];
  for(int i=0;i<n;i++)
    cin>>arr[i];
  //BruteForce - T: O(N^3) S: O(N)
  cout<<"\nsolveWithBruteForce\n";
  solveWithBruteForce(n, arr);

  //BruteForce - T: O(N^2) S: O(N^2)
  cout<<"\nsolveWithBruteForceAndPrefixSuffixSum\n";
  solveWithBruteForceAndPrefixSuffixSum(n, arr);

  //Optimal Solution - T: O(N) S: O(N)
  cout<<"\nsolveOptimally\n";
  solveOptimally(n, arr);
  
  return 0;
}

/*
Renaissance-ProgrammingPathshala/M2/Arrays_and_Dynamic_Arrays/SumOfAllSubArrays.cpp
3
1 4 3

*/