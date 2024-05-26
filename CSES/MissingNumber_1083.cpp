#include <iostream>
using namespace std;

int main()
{
    long n;
    cin >> n;
    long sum = n * (n + 1) / 2;
    // cout << "sum: " << sum << "\n";
    while (--n)
    {
        long a;
        cin >> a;
        sum -= a;
    }
    cout << sum;
}

/*
CSES/MissingNumber_1083.cpp
2
2
*/