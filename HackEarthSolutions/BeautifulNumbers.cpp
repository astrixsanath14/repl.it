#include<bits/stdc++.h>
using namespace std;
#define MAX_LIMIT 1E6
#define MAX_LIMIT_TO_FIND_HAPPY 405
vector<int> happy(MAX_LIMIT+1, -1);
vector<long long> prefixSum(MAX_LIMIT+1);

long long solve (int l, int r) 
{
   // Your code goes here
   return prefixSum[r] - prefixSum[l-1];
}

int getSumOfSquareOfDigits(int n)
{
  int sum = 0;
  while(n)
  {
    sum += (n%10)*(n%10);
    n/=10;
  }
  return sum;
}

int checkAndSetIfHappy(int i)
{
  if(happy[i] == -1)
  {
    happy[i] = -2;
    int sum = getSumOfSquareOfDigits(i);
    happy[i] = checkAndSetIfHappy(sum);
  }
  else if(happy[i] == -2)
    happy[i] = 0;
  return happy[i];
}

void initializeAllHappyNumbers()
{
  happy[0] = 0;
  happy[1] = 1;
  prefixSum[0] = 0;
  prefixSum[1] = 1;
  for(int i=2;i<=MAX_LIMIT_TO_FIND_HAPPY;i++)
  {
    checkAndSetIfHappy(i);
    // cout<<"After calling checkAndSetIfHappy(i) : ";
    // cout<<i<<" "<<happy[i]<<" "<<prefixSum[i]<<endl;
    prefixSum[i] = prefixSum[i-1] + (happy[i] ? i : 0);
  }
  for(int i = MAX_LIMIT_TO_FIND_HAPPY+1; i<=MAX_LIMIT; i++)
  {
    int sum = getSumOfSquareOfDigits(i);
    happy[i] = happy[sum];
    if(happy[sum]!=0 && happy[sum]!=1)
    {
      cout<<sum<<" not set"<<endl;
      break;
    }
    prefixSum[i] = prefixSum[i-1] + (happy[i] ? i : 0);
  }
}

void printHappyNumbers(int n)
{
  for(int i=1;i<=n;i++)
  {
    cout<<i<<" "<<happy[i]<<" "<<prefixSum[i]<<endl;
  }
}

int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);
    int T;
    cin >> T;
    initializeAllHappyNumbers();
    // printHappyNumbers(50);
    for(int t_i = 0; t_i < T; t_i++)
    {
        int l;
        cin >> l;
        int r;
        cin >> r;

        long long out_;
        out_ = solve(l, r);
        cout << out_;
        cout << "\n";
    }
}
/*
HackEarthSolutions/BeautifulNumbers.cpp
1
1 3

5
1 25
348 400
1 2
33 34
10000 10000 
*/