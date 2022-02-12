#include<bits/stdc++.h>
using namespace std;

class Solution{
public:
	int rowWithMax1s(vector<vector<int>> arr, int n, int m) {
	    // code here
	    int row=0,col=m-1, maxCount = 0, maxRow = -1;
	    while(row<n && col >=0)
	    {
	        while(col>=0 && arr[row][col])
	        {
	            maxRow = row;
	            maxCount++;
	            col--;
	        }
	        if(col==-1)
	            return maxRow;
	        while(row<n && !arr[row][col])
	        {
	            row++;
	        }
	        if(row==n)
	            return maxRow;	        
	    }
	    return maxRow;
	}

};

int main()
{
  int t;
  cin>>t;
  while(t--){
    int n,m;
    cin>>n>>m;
    vector<vector<int>> arr(n, vector<int>(m));
    for(int i=0;i<n;i++)
    {
      for(int j=0;j<n;j++)
      {
        cin>>arr[i][j];
      }
    }
    Solution ob;
    auto ans = ob.rowWithMax1s(arr,n,m);
    cout<<ans<<"\n";
  }
  return 0;
}

/*
Renaissance-ProgrammingPathshala/M2/Arrays_and_Dynamic_Arrays/Assignment_2/RowWithMax1s.cpp
For Input: 
1
4 4
0 1 1 1 0 0 1 1 1 1 1 1 0 0 0 0

Your Output: 
2

Expected Output: 
2
*/