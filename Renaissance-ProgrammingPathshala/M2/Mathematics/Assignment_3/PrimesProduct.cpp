#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MAX (int)(1E6 + 7)
#define MOD (long)(1E9 + 7)
vector<bool> isPrime(MAX + 1, 1);
vector<int> spf(MAX + 1);

using namespace std;

void sieve() {
	isPrime[0] = 0;
	spf[0] = -1;
	isPrime[1] = 0;
	spf[1] = -1;
	for (int i = 2; i * i <= MAX; i++) {
		if (isPrime[i]) {
			for (int j = i; j * i <= MAX; j++) {
				isPrime[j * i] = 0;
				spf[j * i] = i;
			}
		}
	}
}

vector<long> getPrimeInRangeUsingSegmentSieve(long l, long r) {
	int n = r - l + 1;
	vector<long> primesInRange;
	vector<bool> isPrimeInRange(n, 1);
  if(l == 1)
      isPrimeInRange[1 - l] = 0;
	for (int i = 2; i * i <= r; i++) {
		if (isPrime[i]) {
            // cout<<i<<" is prime\n";
			long x = ceil(1.0 * l / i);
            if(x == 1)
                x++;
            // cout<<"x is "<<x<<"\n";
			for (long j = x; j * i <= r; j++) {
				isPrimeInRange[j * i - l] = 0;
			}
		}
	}
	for (int i = 0; i < n; i++) {
		if (isPrimeInRange[i]){
			primesInRange.push_back(i + l);
        }
	}
    
	return primesInRange;
}

long getProductOfPrimesWithinRange(long l, long r) {
	long product = 1;
	vector<long> primesInRange = getPrimeInRangeUsingSegmentSieve(l, r);
	for (long prime : primesInRange) {
		product = product % MOD * prime % MOD;
        // cout<<prime<<" ";
	}
	return product;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
	int t;
	cin >> t;
	sieve();
	while (t--) {
		long l, r;
		cin >> l >> r;
		cout << getProductOfPrimesWithinRange(l, r) << "\n";
	}
	return 0;
}

/*
Segmented Sieve

Renaissance-ProgrammingPathshala/M2/Mathematics/Assignment_3/PrimesProduct.cpp
2
1 10
2 20

Renaissance-ProgrammingPathshala/M2/Mathematics/Assignment_3/PrimesProduct.cpp
1
51 100

n = 100 - 50 + 1 == 51
ceil(1.0 * 51/2) = 26
firstMultiple = 26 * 2



*/