#include<iostream>
using namespace std;

int main()
{
  int n, q, c;
  cin>>n>>q>>c;
  int pos[n][2], s[n];
  for(int i=0;i<n;i++)
  {
    cin>>pos[i][0]>>pos[i][1]>>s[i];
  }
  // cout<<"q: "<<q<<endl;
  for(int qq=0;qq<q;qq++)
  {
    int t,x1,y1,x2,y2;
    cin>>t>>x1>>y1>>x2>>y2;
    int brightness = 0;
    for(int i=0;i<n;i++)
    {
      if(pos[i][0]>=x1 && pos[i][0]<=x2 && pos[i][1]>=y1 && pos[i][1]<=y2)
        brightness+=(s[i]+t)%(c+1);
    }
    cout<<brightness<<"\n";
  }
  return 0;
}

/*
Input 1:
Renaissance-ProgrammingPathshala/M2/Arrays_and_Dynamic_Arrays/HomeWork_2/StarSky_CF.cpp
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
Renaissance-ProgrammingPathshala/M2/Arrays_and_Dynamic_Arrays/HomeWork_2/StarSky_CF.cpp
3 4 5
1 1 2
2 3 0
100 100 1
0 1 1 100 100
1 2 2 4 4
2 2 1 4 7
1 50 50 51 51


Output 2:
3
3
5
0

*/