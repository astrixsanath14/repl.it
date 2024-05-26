#include<iostream>
#include<vector>
#include<limits.h>
using namespace std;


vector<int> getPrefixMaxForP(vector<int>& arr, int p)
{
  vector<int> prefixMaxArr(arr.size());
  prefixMaxArr[0] = p * arr[0];
  for(int i = 1; i < arr.size(); i++)
  {
    prefixMaxArr[i] = max(prefixMaxArr[i-1], p * arr[i]);
  }
  return prefixMaxArr;
}

vector<int> getSuffixMaxForR(vector<int>& arr, int r)
{
  vector<int> suffixMaxArr(arr.size());
  suffixMaxArr[arr.size()-1] = r * arr[arr.size() - 1];
  for(int i = arr.size() - 2; i >=0 ; i--)
  {
    suffixMaxArr[i] = max(r * arr[i], suffixMaxArr[i+1]);
  }
  return suffixMaxArr;
}

void printVectorContents(vector<int>& arr)
{
  for(int val: arr)
  {
    cout<<val<<" ";
  }
  cout<<endl;
}


int main()
{
  char choice;
  while(true)
  {
    int n;
    cout<<"Enter number of elements: \n";
    cin>>n;
    vector<int> arr;
    cout<<"Enter the elements: \n";
    for(int i=0;i<n;i++)
    {
      int t;
      cin>>t;
      arr.push_back(t);
    }
    int p, q, r;
    cout<<"Enter the values of p, q and r: \n";
    cin>>p>>q>>r;

    vector<int> prefixMaxArr = getPrefixMaxForP(arr, p);
    vector<int> suffixMaxArr = getSuffixMaxForR(arr, r);

    // cout<<"\nSuffix Max Array: \n";
    // printVectorContents(suffixMaxArr);
    // cout<<"\nPrefix Max Array: \n";
    // printVectorContents(prefixMaxArr);
    int maxSum = INT_MIN;
    for(int i = 1; i < n-1; i++)
    {
      maxSum = max(maxSum, prefixMaxArr[i-1] + q * arr[i] + suffixMaxArr[i+1]);
    }
    
    cout<<"\nMax Sum: "<<maxSum;
    cout<<"\nDo you want to continue? (y/n)\n";
    cin>>choice;
    if(!(choice == 'y' || choice == 'Y'))
    {
      break;
    }
    cout<<"\n";
  }
  return 0;
}

/*
Renaissance-ProgrammingPathshala/M2/Arrays_and_Dynamic_Arrays/MaximizeTheExpression.cpp
7
4 1 5 2 9 4 1 
3 -2 7
Y
7
4 1 5 -2 9 4 1 
3 -2 7
N

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