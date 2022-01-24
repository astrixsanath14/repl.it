#include<iostream>
#include<vector>
using namespace std;

int main()
{
  int m,n,flowerMood,happiness=0,l,r,sum;
  cin>>m>>n;
  vector<int> prefixSum(m);
  for(int i=0;i<m;i++)
  {
    cin>>flowerMood;
    if(i==0)
    {
      prefixSum[i] = flowerMood;
    }
    else
    {
      prefixSum[i] = prefixSum[i-1] + flowerMood;
    }
  }
  for(int i=0;i<n;i++)
  {
    cin>>l>>r;
    sum = prefixSum[r-1] - (l>1?prefixSum[l-2]:0);
    if(sum>0)
      happiness+=sum;
  }
  cout<<happiness;
  return 0;
}

/*
Renaissance-ProgrammingPathshala/M2/Arrays_and_Dynamic_Arrays/Assignment_1/Alyona_and_flowers.cpp
5 4
1 -2 1 3 -4
1 2
4 5
3 4
1 4
*/