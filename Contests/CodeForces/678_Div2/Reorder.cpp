#include<bits/stdc++.h>
#define ll long long
using namespace std;

void solve()
{
  ll n,m;
  cin>>n>>m;
  ll a, sum = 0;
  for(ll i=0;i<n;i++)
  {
    cin>>a;
    sum+=a;
  }
  if(sum==m)
    cout<<"YES";
  else
    cout<<"NO";
}

int main(){
  ll t;
  cin>>t;
  while(t--)
  {
    solve();
    cout<<"\n";
  }
}

/*
Contests/CodeForces/678_Div2/Reorder.cpp
2
3 8
2 5 1
4 4
0 1 2 3


*/