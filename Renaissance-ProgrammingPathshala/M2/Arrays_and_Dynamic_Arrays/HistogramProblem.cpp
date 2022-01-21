#include<iostream>
#include<vector>
using namespace std;


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
    cout<<"Enter number of pillars: \n";
    cin>>n;
    vector<int> pillarHeights;
    cout<<"Enter the heights of pillars: \n";
    for(int i=0;i<n;i++)
    {
      int t;
      cin>>t;
      pillarHeights.push_back(t);
    }
    vector<int> suffixMaxArr = getSuffixMax(pillarHeights);
    vector<int> prefixMaxArr = getPrefixMax(pillarHeights);

    cout<<"\nSuffix Max Array: \n";
    printVectorContents(suffixMaxArr);
    cout<<"\nPrefix Max Array: \n";
    printVectorContents(prefixMaxArr);

    int waterAccumulatedHeight = 0;

    for(int i = 1; i < n-1; i++)
    {
      int currentPillarHeight = pillarHeights[i];
      int maxPillarHeightOnLeft = prefixMaxArr[i-1];
      int maxPillarHeightOnRight = suffixMaxArr[i+1];
      int decidingPillarHeight = min(maxPillarHeightOnLeft, maxPillarHeightOnRight);

      if(decidingPillarHeight > currentPillarHeight)
      {
        waterAccumulatedHeight += decidingPillarHeight;
        cout<<"\nWater will be accumulated over pillar: " <<i+1<< " of height: "<<currentPillarHeight<<" waterHeight: " <<decidingPillarHeight;
      }
      else
      {
        cout<<"\nNo water will be accumulated over pillar: " <<i+1<< " of height: "<<currentPillarHeight;
      }
    }

    cout<<"\nCumulative Water Height: "<<waterAccumulatedHeight<<endl;
    
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
Renaissance-ProgrammingPathshala/M2/Arrays_and_Dynamic_Arrays/HistogramProblem.cpp
7
4 1 5 2 9 4 1 
Y
7
1 2 3 4 5 6 7
N


Objective:
  Given the heights of N pillars, find the cumulative sum of height of water accumulated when rain falls.
  Note - Rain falls on all pillars equally

Intuition:
  Find the height of water accumulated over each pillar and sum them.
*/