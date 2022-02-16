#include <iostream>
using namespace std;

long long getGCD(long a, long b)
{
	long x = max(a,b), y = min(a,b);
	long gcd;
	if (y == 0)
	{
		gcd = x;
	}
	else
	{
		while(x%y!=0)
		{
			x = x%y;
			long temp = y;
			y = min(x, temp);
			x = max(x, temp);
		}
		gcd = y;
	}
	return gcd;
}


int main() 
{
	int t;
	cin>>t;
	while(t--)
	{
		long long n,a,b,k;
		cin>>n>>a>>b>>k;
		long long gcd = getGCD(a,b);
		long long lcm = (a*b)/gcd ;
		long long commonMultipleCount = n/lcm;
		cout<<(((n/a)-commonMultipleCount + (n/b)-commonMultipleCount) >= k ? "Win":"Lose")<<"\n";
	}
	return 0;
}

/*
Renaissance-ProgrammingPathshala/M2/Mathematics/Assignment_1/SpecialContest.cpp
1
6 2 3 3


*/