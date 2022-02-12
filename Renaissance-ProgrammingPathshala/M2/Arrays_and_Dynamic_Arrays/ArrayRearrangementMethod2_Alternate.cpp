#include<iostream>
using namespace std;

// A simple method to rearrange
// 'arr[0..n-1]' so that 'arr[j]'
// becomes 'i' if 'arr[i]' is 'j'
void rearrange(int arr[], int n)
{
    for (int i = 0; i < n; i++) {
 
        // retrieving old value and
        // storing with the new one
        arr[arr[i] % n] += i * n;
    }
 
    for (int i = 0; i < n; i++) {
 
        // retrieving new value
        arr[i] /= n;
    }
}

void solve(int arr[], int n)
{
  for(int i=0;i<n;i++){
    int newPos = arr[i]%n;
    int newVal = i;
    int oldVal = arr[newPos];
    arr[newPos] = n*newVal + oldVal;
    // cout<<"newPos: "<<newPos<<"\n";
    // cout<<"newVal: "<<newVal<<"\n";
    // cout<<"oldVal: "<<oldVal<<"\n";
    // cout<<"n*newVal + oldVal: "<<n*newVal + oldVal<<"\n";
  }
  // cout<<"-----------\n";

  for(int i=0;i<n;i++){
    int newVal = arr[i]/n;
    arr[i] = newVal;
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
    rearrange(arr,n);
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
Renaissance-ProgrammingPathshala/M2/Arrays_and_Dynamic_Arrays/ArrayRearrangementMethod2_Alternate.cpp
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

Input:
Renaissance-ProgrammingPathshala/M2/Arrays_and_Dynamic_Arrays/ArrayRearrangementMethod2_Alternate.cpp
1
4
1 2 0 3

Output:
2 0 1 3
*/