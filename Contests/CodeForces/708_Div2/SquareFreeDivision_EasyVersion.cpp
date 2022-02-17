#include <bits/stdc++.h>
using namespace std;

vector<int> getPrimeFactors(int n)
{
  int c = 2;
  vector<int> primes;
  while (n > 1)
  {
    if (n % c == 0)
    {
      // cout << c << " ";
      n /= c;
      primes.push_back(c);
    }
    else
      c++;
  }
  // cout << "\n";
  return primes;
}

int getProductOfUnpairedPrimes(int val)
{
  map<int, int> counterOfPrimes;
  int prime = 2;

  long long product = 1;

  while (val > 1)
  {
    if (val % prime == 0)
    {
      // cout << prime << " ";
      val /= prime;
      counterOfPrimes[prime]++;
      if (counterOfPrimes[prime] % 2 == 0)
      {
        product = product / prime;
      }
      else
      {
        product = product * prime;
      }
    }
    else
      prime++;
  }
  return product;
}

void solve()
{
  int n, k;
  cin >> n >> k;
  int val;
  map<int, bool> primeCountersForSegments;
  int noOfSegments = 1;
  for (int i = 0; i < n; i++)
  {
    cin >> val;
    int product = getProductOfUnpairedPrimes(val);
    // cout << a[i] << " " << product << "\n";
    if (primeCountersForSegments[product])
    {
      // cout << "Segment found \n";
      noOfSegments++;
      primeCountersForSegments = map<int, bool>();
    }
    else
      primeCountersForSegments[product] = true;
  }

  cout << noOfSegments << "\n";
}

int main()
{
  int t;
  cin >> t;
  while (t--)
  {
    solve();
  }
  return 0;
}

/*
Contests/CodeForces/708_Div2/SquareFreeDivision_EasyVersion.cpp
3
5 0
18 6 2 4 1
5 0
6 8 1 24 8
1 0
1

*/
