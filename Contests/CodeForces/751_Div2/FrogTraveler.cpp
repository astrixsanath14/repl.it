#include<bits/stdc++.h>
using namespace std;

vector<int> depthMap(300001, -2);

void printPath(vector<int>& path)
{
  cout<<"Path: "<<"\n";
  for(auto pathVal:path)
    cout<<pathVal<<" ";
  cout<<"\n";
}

bool solve(int a[], int b[], int depth, vector<int> &path, int maxDepth)
{
  printPath(path);
  cout<<"depth: "<<depth<<"\n";
  if(depth<=0)
    return true;
  
  int slippedDepth = depth + b[depth];
  cout<<"slippedDepth: "<<slippedDepth<<"\n";
  if(depthMap[slippedDepth] == -1)
  {
    depthMap[slippedDepth] = 0;
    return false;
  }
  else if(depthMap[slippedDepth] != -2)
  {
    return depthMap[slippedDepth];
  }
  depthMap[slippedDepth] = -1;
  bool result = false;
  path.push_back(depth);
  for(int i=1;i<=a[slippedDepth];i++)
  {
    result = result | solve(a,b,slippedDepth - i,path,maxDepth);
    depthMap[slippedDepth] = 1;
    if(result)
    {
      //Found a way to reach top
      return true;
    }
  }
  
  //Didn't find a way to reach top, hence cannot reach from current path
  path.pop_back();
  return result == 1;
}

int main()
{
  int n;
  cin>>n;
  int a[n], b[n];
  for(int i=0;i<n;i++)
    cin>>a[i];
  for(int i=0;i<n;i++)
    cin>>b[i];
  vector<int> path;
  bool ans = solve(a, b, n, path, n);
  if(ans)
  {
    cout<<path.size()<<"\n";
    for(auto pathVal:path)
      cout<<pathVal<<" ";
    cout<<"\n";
  }
  else
  {
    cout<<"-1"<<"\n";
  }
  return 0;
}

/*
Contests/CodeForces/751_Div2/FrogTraveler.cpp
3
0 2 2
1 1 0


*/