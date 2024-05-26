#include<iostream>
#include<vector>
#include<limits.h>
using namespace std;

int main()
{
  long long int n, p, q, r;
  // cout<<"Enter number of elements: \n";
  // cout<<"Enter the values of p, q and r: \n";
  cin>>n>>p>>q>>r;
  vector<long long int> arr(n);
  // cout<<"Enter the elements: \n";
  for(long long int i=0;i<n;i++)
  {
    cin>>arr[i];
  }

  vector<long long int> prefixMaxArr(n);
  prefixMaxArr[0] = p * arr[0];
  for(long long int i = 1; i < arr.size(); i++)
  {
    prefixMaxArr[i] = max(prefixMaxArr[i-1], p * arr[i]);
  }

  vector<long long int> suffixMaxArr(n);
  suffixMaxArr[arr.size()-1] = r * arr[arr.size() - 1];
  for(long long int i = arr.size() - 2; i >=0 ; i--)
  {
    suffixMaxArr[i] = max(r * arr[i], suffixMaxArr[i+1]);
  }
  long long int maxSum = prefixMaxArr[0] + q * arr[0] + suffixMaxArr[0];
  for(long long int i = 1; i < n; i++)
  {
    maxSum = max(maxSum, prefixMaxArr[i] + q * arr[i] + suffixMaxArr[i]);
  }
  
  cout<<maxSum;
  return 0;
}

/*
Renaissance-ProgrammingPathshala/M2/Arrays_and_Dynamic_Arrays/Assignment_1/Marvolo_Gaunts_Ring.cpp
5 1 2 3
1 2 3 4 5

Renaissance-ProgrammingPathshala/M2/Arrays_and_Dynamic_Arrays/Assignment_1/Marvolo_Gaunts_Ring.cpp
5 1 2 -3
-1 -2 -3 -4 -5


Renaissance-ProgrammingPathshala/M2/Arrays_and_Dynamic_Arrays/Assignment_1/Marvolo_Gaunts_Ring.cpp
1 1000000000 1000000000 1000000000
1000000000 

Renaissance-ProgrammingPathshala/M2/Arrays_and_Dynamic_Arrays/Assignment_1/Marvolo_Gaunts_Ring.cpp
1 0 0 0 
0

Objective:
  Maximise:
    Sum(a[i],a[j],a[k])
Constraints:
  0<=i<j<k<N
  For all 0<=i<N:
    a[i] can be positive, negative or zero.
  p,q,r can be positive, negative or zero.

Intuition:
  Find the prefixMax and suffixMax such that they maximize 
  a[i]*p and a[k]*r, iterate over each element at index i and for every element obtain 
  sum(prefixMax before i, suffixMax after i, a[i]) and obtain max sum.

Time Complexity:
  O(N)
*/