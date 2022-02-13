#include<iostream>
using namespace std;

void solve(int arr[], int n)
{
  for(int i=0;i<n;i++)
  {
    if(arr[i]>=0)
    {
      int pos = i, copyPos = arr[i], temp;
      while(copyPos!=i)
      {
        temp = arr[copyPos];
        arr[copyPos] = -(pos + 1);
        pos = copyPos;
        copyPos = temp;
      }
      arr[copyPos] = -(pos + 1);
    }
  }
  for(int i=0;i<n;i++)
  {
    arr[i] = -1 - arr[i];
  }
}

int main()
{
  int t;
  cin>>t;
  while(t--)
  {
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
      cin>>arr[i];
    solve(arr,n);
    for(int i=0;i<n;i++)
    {
      cout<<arr[i]<<" ";
    }
    cout<<"\n";
  }
  return 0;
}

/*
Input:
Renaissance-ProgrammingPathshala/M2/Arrays_and_Dynamic_Arrays/ArrayRearrangementMethod1.cpp
5
4
1 2 0 3
4
1 3 0 2
6
2 0 1 4 5 3
4
0 1 2 3
4
3 2 1 0

Output:
2 0 1 3 
2 0 3 1 
1 2 0 5 3 4 
0 1 2 3 
3 2 1 0 
*/