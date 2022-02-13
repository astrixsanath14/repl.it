#include<bits/stdc++.h>
#define MAX_STAR_COUNT 100
using namespace std;

class NumMatrix {
  public:
    vector<vector<long long>>prefixMatrix;
    
    NumMatrix(vector<vector<int>>& matrix) 
    {
      int m = matrix.size();
      int n = matrix[0].size();
      prefixMatrix.resize(m);
      for (int i = 0; i < m; ++i)
      {
        prefixMatrix[i].resize(n);
        for(int j=0;j<n;j++)
        {
          prefixMatrix[i][j]=matrix[i][j];
          if(j>0)
            prefixMatrix[i][j]+=prefixMatrix[i][j-1];
        }
      }
      for(int i=0;i<n;i++)
      {
        for(int j=1;j<m;j++)
        {
          prefixMatrix[j][i]+=prefixMatrix[j-1][i];
        }
      }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
      long long sum = prefixMatrix[row2][col2];
      if(row1>0)
      {
        //Cutting top portion
        sum-=prefixMatrix[row1-1][col2];
      }
      if(col1>0)
      {
        //Cutting left portion
        sum-=prefixMatrix[row2][col1-1];
      }
      if(row1>0 && col1>0)
      {
        //adding back extra cut portion
        sum+=prefixMatrix[row1-1][col1-1];
      }
      return sum;
    }
};


void printAllSkyMoments(vector<NumMatrix> &skyAtMoments, int topLeftX, int topLeftY, int bottomRightX, int bottomRightY)
{
  int momentNumber = 0;
  for(NumMatrix skyAtMoment:skyAtMoments)
  {
    cout<<"prefix sum: "<<momentNumber++<<"\n";
    for(int i=topLeftX;i<=bottomRightX;i++)
    {
      for(int j=topLeftY;j>=bottomRightY;j--)
      {
        cout<<"("<<i<<","<<j<<")"<<skyAtMoment.prefixMatrix[i][j]<<" ";
      }
      cout<<"\n";
    }
    cout<<"\n";
  }
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n, q, c;
  cin>>n>>q>>c;
  vector<vector<vector<int>>> sky = vector(c+1, vector(MAX_STAR_COUNT + 1, vector<int>(MAX_STAR_COUNT+1,0)));
  int pos[n][2];
  int topLeftX = INT_MAX, topLeftY = INT_MIN, bottomRightX = INT_MIN, bottomRightY = INT_MAX;
  int prevX, prevY;
  for(int i=0;i<n;i++)
  {
    int x,y,s;
    cin>>x>>y>>s;
    for(int moment=0;moment<=c;moment++)
    {
      sky[moment][x][y] += (s+moment)%(c+1);
    }
    topLeftX = min(topLeftX, x);
    topLeftY = max(topLeftY, y);
    bottomRightX = max(bottomRightX, x);
    bottomRightY = min(bottomRightY, y);
    pos[i][0]=x;
    pos[i][1]=y;
  }

  vector<NumMatrix> skyAtMoments;
  for(int moment=0;moment<=c;moment++)
  {
    skyAtMoments.push_back(NumMatrix(sky[moment]));
  }
  // printAllSkyMoments(skyAtMoments, topLeftX, topLeftY, bottomRightX, bottomRightY);
  for(int qq=0;qq<q;qq++)
  {
    long t,x1,y1,x2,y2;
    cin>>t>>x1>>y1>>x2>>y2;
    int moment = t%(c+1);
    cout<<skyAtMoments[moment].sumRegion(x1, y1, x2, y2)<<"\n";
  }
  return 0;
}

/*
Input 0:
Renaissance-ProgrammingPathshala/M2/Arrays_and_Dynamic_Arrays/HomeWork_2/StarSky_Alternate_CF.cpp
3 5 2
1 1 0
1 1 1
100 100 0
0 1 1 1 1 
1 1 1 1 1 
2 1 1 1 1 
3 1 1 1 1 
2 1 1 100 100

Input 1:
Renaissance-ProgrammingPathshala/M2/Arrays_and_Dynamic_Arrays/HomeWork_2/StarSky_Alternate_CF.cpp
2 3 3
1 1 1
3 2 0
2 1 1 2 2
0 2 1 4 5
5 1 1 5 5

Output 1:
3
0
3

Input 2:
Renaissance-ProgrammingPathshala/M2/Arrays_and_Dynamic_Arrays/HomeWork_2/StarSky_Alternate_CF.cpp
3 4 5
1 1 2
2 3 0
3 3 1
0 1 1 100 100
1 2 2 4 4
2 2 1 4 7
1 50 50 51 51


Output 2:
3
3
5
0

Input 3:
Renaissance-ProgrammingPathshala/M2/Arrays_and_Dynamic_Arrays/HomeWork_2/StarSky_Alternate_CF.cpp
1 8 5
100 100 1
0 1 1 100 100
1 1 1 100 100
2 1 1 100 100
3 1 1 100 100
4 1 1 100 100
5 1 1 100 100
6 1 1 100 100
7 100 100 100 100 

Failing Input:
Renaissance-ProgrammingPathshala/M2/Arrays_and_Dynamic_Arrays/HomeWork_2/StarSky_Alternate_CF.cpp
55 1 4
8 3 1
99 63 1
43 1 2
24 77 0
78 41 1
25 88 0
2 82 0
19 56 4
79 8 4
42 38 1
42 32 3
70 5 0
33 47 0
61 35 1
4 37 1
24 72 1
90 40 0
59 90 3
81 97 1
92 5 3
2 46 4
74 97 1
77 24 4
90 38 4
83 100 1
29 39 1
35 33 0
88 34 4
18 47 2
9 2 1
89 58 4
67 29 1
30 44 0
44 20 2
84 85 3
57 81 2
66 21 1
58 68 2
74 87 0
18 29 3
32 92 0
34 80 4
73 16 0
71 53 4
98 64 0
24 39 1
89 45 0
43 31 0
3 17 0
58 98 4
87 91 2
55 27 2
54 87 4
25 69 2
14 75 4
81 48 2
0 1 1 1 1
*/