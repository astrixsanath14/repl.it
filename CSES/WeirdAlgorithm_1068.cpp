#include <iostream>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    long n;
    cin >> n;
    while (n != 1)
    {
        cout << n << " ";
        n = !(n % 2) ? n / 2 : n * 3 + 1;
    }
    cout << 1;
}

/*
CSES/WeirdAlgorithm_1068.cpp
3
*/