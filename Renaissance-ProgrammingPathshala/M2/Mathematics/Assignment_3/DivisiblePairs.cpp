#include <bits/stdc++.h>
using namespace std;

int nc2(int n) {
	return (n * (n - 1)) / 2;
}

int getDivisiblePairs(vector<int> &a, int m) {
	vector<int> reminderFreq(m,0);
	for (int i : a) {
		reminderFreq[i % m]++;
	}
	int pairsDivisibleByK = nc2(reminderFreq[0]);
	for (int i = 1; i < (m / 2) + m % 2; i++) {
		pairsDivisibleByK += reminderFreq[i] * reminderFreq[m - i];
	}
	if (m % 2 == 0) {
		pairsDivisibleByK += nc2(reminderFreq[m / 2]);
	}

	return pairsDivisibleByK;
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		vector<int> a(n);
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}
		cout << getDivisiblePairs(a, 4) << "\n";
	}
	return 0;
}

/*
Rule: (a+b)%m == (a%m + b%m)%m ...... (Rule_1)

(8+4)%4 == 0
(8+4)%4 = (8%4 + 4%4)
		= (0 + 0)

(1+3)%4 == 0
(1+3)%4 = (1%4 + 3%4)%4
		= (1 + 3)%4

(11+5)%4 == 0
(11+5)%4 = (11%4 + 5%4)%4
		 = (1 + 3)%4

If, (a+b)%m == 0
a%m lies in the range 0...m-1
b%m lies in the range 0...m-1
Therefore, range of (a%m + b%m) is 0....(2m-2)
In this range, sum must be equal to 0 or m for the sum (a%m + b%m) to be
divisible by m

Poosibilities for divisible pair by m:
1. a%m == b%m == 0
  therefore, count = (count[0] * count[0]-1)/2
2. say, a%m == x, then b%m == (m-x)
  therefore, count = c[x] * c[m-x]

Special case, when m is even, say m = 6, reminder frequency:
0 1 2 3 4 5
here, (3+3)%6 == 0, is a case that needs to be handled based on m.

Renaissance-ProgrammingPathshala/M2/Mathematics/Assignment_3/DivisiblePairs.cpp
1
5
2 2 1 7 5

*/