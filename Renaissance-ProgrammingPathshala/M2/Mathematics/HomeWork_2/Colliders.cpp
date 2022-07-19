#include<bits/stdc++.h>
using namespace std;

int gcd(int a,int b)
{
    if(b==0)
        return a;
    return gcd(b,a%b);
}

int checkForCollision(set<int> activated, int colliderNo)
{
    for(int i:activated)
        if(gcd(i, colliderNo) != 1)
            return i;
    return -1;
}

int checkForCollision(vector<set<int>>& primeFact, int colliderNo)
{
  int num = colliderNo;
  for(int divisor = 2; divisor*divisor<=colliderNo; divisor++)
  {
    if(colliderNo%divisor == 0 && primeFact[divisor].size()>0)
      return *(primeFact[divisor].begin());
    while(colliderNo%divisor==0)
    {
      colliderNo/=divisor;
    }
  }
  if(colliderNo>1)
  {
    if(primeFact[colliderNo].size()>0)
      return *(primeFact[colliderNo].begin());
  }
  return -1;
}

void updatePrimeFact(vector<set<int>>& primeFact, int colliderNo, bool isAdd)
{
  int num = colliderNo;
  for(int divisor = 2; divisor*divisor<=colliderNo; divisor++)
  {
    if(colliderNo%divisor == 0)
    {
      if(isAdd)
        primeFact[divisor].insert(num);
      else
        primeFact[divisor].erase(num);
    }
    while(colliderNo%divisor==0)
    {
      colliderNo/=divisor;
    }
  }

  if(colliderNo>1)
  {
    if(isAdd)
        primeFact[colliderNo].insert(num);
      else
        primeFact[colliderNo].erase(num);
  }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n,m;
    cin>>n>>m;
    set<int> activated;
    vector<set<int>> primeFact(n+1);

    while(m--)
    {
        char sign;
        int colliderNo;
        cin>>sign>>colliderNo;
        if(sign == '+')
        {
           if(activated.find(colliderNo) != activated.end())
                cout<<"Already on"<<"\n";
            else 
            {
                int collisionColliderNo = checkForCollision(primeFact, colliderNo);
                if(collisionColliderNo == -1)
                {
                    activated.insert(colliderNo);
                    cout<<"Success"<<"\n";
                    updatePrimeFact(primeFact, colliderNo, true);
                }
                else
                {
                    cout<<"Conflict with "<<collisionColliderNo<<"\n";
                }
            }
        }
        else if(sign == '-')
        {
            if(activated.find(colliderNo) == activated.end())
                cout<<"Already off"<<"\n";
            else
            {
                updatePrimeFact(primeFact, colliderNo, false);
                activated.erase(colliderNo);
                cout<<"Success"<<"\n";
            }
        }
      else
        {
          exit(0);
        }
    }
}

/*
Renaissance-ProgrammingPathshala/M2/Mathematics/HomeWork_2/Colliders.cpp
10 10
+ 6
+ 10
+ 5
- 10
- 5
- 6
+ 10
+ 3
+ 6
+ 3

Output:
Success
Conflict with 6
Success
Already off
Success
Success
Success
Success
Conflict with 10
Already on


Renaissance-ProgrammingPathshala/M2/Mathematics/HomeWork_2/Colliders.cpp
7 5
+ 7
+ 6
+ 4
+ 3
- 7

Output:
Success
Success
Conflict with 6
Conflict with 6
Success
*/