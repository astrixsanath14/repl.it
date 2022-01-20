#include<iostream>
#include<vector>
using namespace std;

vector<int> getSuffixMax(vector<int>& arr)
{
  vector<int> suffixMaxArr(arr.size());
  suffixMaxArr[arr.size()-1] = arr[arr.size() - 1];
  for(int i = arr.size() - 2; i >=0 ; i--)
  {
    suffixMaxArr[i] = max(arr[i], suffixMaxArr[i+1]);
  }
  return suffixMaxArr;
}


vector<int> getPrefixMax(vector<int>& arr)
{
  vector<int> prefixMaxArr(arr.size());
  prefixMaxArr[0] = arr[0];
  for(int i = 1; i < arr.size(); i++)
  {
    prefixMaxArr[i] = max(prefixMaxArr[i-1], arr[i]);
  }
  return prefixMaxArr;
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
  int n;
  cout<<"Enter number of elements: ";
  cin>>n;
  vector<int> arr;
  for(int i=0;i<n;i++)
  {
    int t;
    cin>>t;
    arr.push_back(t);
  }
  vector<int> suffixMaxArr = getSuffixMax(arr);
  vector<int> prefixMaxArr = getPrefixMax(arr);

  cout<<"\nSuffix Max Array: \n";
  printVectorContents(suffixMaxArr);
  cout<<"\nPrefix Max Array: \n";
  printVectorContents(prefixMaxArr);
}

/*
Renaissance-ProgrammingPathshala/M2/Arrays_and_Dynamic_Arrays/PrefixMaxSuffixMap.cpp
7
4 1 5 2 9 4 1 
*/