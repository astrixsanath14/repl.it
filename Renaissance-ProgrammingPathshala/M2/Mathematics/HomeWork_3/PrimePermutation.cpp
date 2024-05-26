#define MOD (int)(1e9 + 7)
#define LIMIT 100
#include <iostream>
bool isPrime[LIMIT + 1];
int primeCount[LIMIT + 1] = {0};
using namespace std;

void sieve()
{
    for (int i = 0; i <= LIMIT; i++)
        isPrime[i] = 1;
    isPrime[0] = 0;
    isPrime[1] = 0;
    for (int i = 2; i <= LIMIT; i++)
    {
        if (isPrime[i])
        {
            // cout<<i<<" is prime \n";
            for (int j = i; i * j <= LIMIT; j++)
            {
                if (isPrime[i * j])
                {
                    isPrime[i * j] = 0;
                }
            }
        }
    }
    for (int i = 1; i <= LIMIT; i++)
    {
        primeCount[i] = primeCount[i - 1] + isPrime[i];
    }
}

long long factorial(int n)
{
    if (n <= 1)
        return 1;
    long long fact = n;
    while (--n)
    {
        fact = (fact * n) % MOD;
    }
    return fact;
}

using namespace std;
int main()
{
    // your code goes here
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    sieve();

    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int pc = primeCount[n];
        // cout<<n<<" "<<pc<<"\n";
        cout << (factorial(pc) * factorial(n - pc)) % MOD << "\n";
    }

    return 0;
}

/*

Sample Input
1
5

Sample Output
12
*/