#include<bits/stdc++.h>
using namespace std;

void solve()
{
  int ind = -1;
  string s,a,b;
  cin>>s;
  char c;
  for(int i=0;i<s.size();i++)
  {
    if(ind ==-1 || s[i]<c)
    {
      c = s[i];
      ind = i;
    }
  }
  a = c;
  for(int i=0;i<s.size();i++)
  {
    if(ind!=i)
      b+=s[i];
  }
  cout<<a<<" "<<b<<"\n";
}

int main()
{
  int t;
  cin>>t;
  while(t--)
  {
    solve();
  }
}

/*
Contests/CodeForces/751_Div2/TwoSubsequences.cpp
3
fc
aaaa
thebrightboiler

c f
a aaa
b therightboiler
*/