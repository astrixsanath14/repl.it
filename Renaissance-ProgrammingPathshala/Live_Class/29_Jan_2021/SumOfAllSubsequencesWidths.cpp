#include<iostream>
#include <bits/stdc++.h>
using namespace std;
#define ull unsigned long long int
int M = pow(10,9) + 7;

int pow(ull a, ull b, ull m){
    int ans = 1;
    while(b){
        if (b&1) ans = (ans*a) % m;
        b /= 2;
        a = ((ull)a*a) % m;
    }
    return ans;
  }

void solveWithBruteForce(const int n,int arr[])
{
  int totalSum = 0;
  for(int i=0;i<n;i++)
  {
    for(int j=i+1;j<n;j++)
    {
      ull totalCombinationsWithIandJ = pow(2,(j-i-1),M);
      cout<<i<<" "<<j<<" "<<totalCombinationsWithIandJ<<endl;
      totalSum+=((totalCombinationsWithIandJ)*(arr[j]-arr[i]))%M;
    }
  }
  cout<<"totalSum: " <<totalSum <<endl;
}

void solveOptimally(const int n,int arr[])
{
  ull totalSum = 0;
    ull prefixSum[n], ps = 1;
  ull suffixSum[n], ss = n-2;
  prefixSum[0] = arr[0];
  suffixSum[n-1] = arr[n-1];
  for(int i=1;i<n;i++)
  {
    prefixSum[ps] = prefixSum[ps-1] + arr[ps];
    suffixSum[ss] = suffixSum[ss+1] + arr[ss];
    ps++;
    ss--;
  }
  ps = 0;
  ss = n-1;
  ull powers = 1;
  for(int i=0;i<n;i++)
  {
    ull res = ((suffixSum[ss--] - prefixSum[ps++]) * powers)%M;
    powers*=2;
    totalSum=(totalSum+res)%M;
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
  sort(arr, arr + n);
  cout<<"\nsolveWithBruteForce\n";
  solveWithBruteForce(n, arr);

  cout<<"\nsolveOptimally\n";
  solveOptimally(n, arr);
  return 0;
}

/*
Renaissance-ProgrammingPathshala/Live_Class/29_Jan_2021/SumOfAllSubsequencesWidths.cpp
3
2 1 3

Sorted:
1 2 3
SubSequences:
1
1 2
1 3
1 2 3
2
2 3
3

SubSequences starting with 1 and ending with 2:
1 2
SubSequences starting with 1 and ending with 3:
1 3
1 2 3
SubSequences starting with 2 and ending with 3:
2 3
*/