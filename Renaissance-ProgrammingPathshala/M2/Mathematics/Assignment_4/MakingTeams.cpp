#include <bits/stdc++.h>
#define BOYS_LIMIT 30
#define GIRLS_LIMIT 30
#define MIN_BOYS_LIMIT 4
#define MIN_GIRLS_LIMIT 1
#define LIMIT BOYS_LIMIT + GIRLS_LIMIT
long long pascal[LIMIT + 1][LIMIT + 1];

using namespace std;

long factorial(int n)
{
    long fact = 1;
    for (int i = 2; i <= n; i++)
    {
        fact *= i;
    }
    return fact;
}

long ncr(int n, int r)
{
    long nFact = factorial(n);
    long rFact = factorial(r);
    long nMinusRFact = factorial(n - r);
    return nFact / (rFact * nMinusRFact);
}

void pascalTriangle()
{
    for (int i = 0; i <= LIMIT; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            if (i == 0 || j == 0 || j == i)
            {
                pascal[i][j] = 1;
            }
            else
            {
                pascal[i][j] = pascal[i - 1][j - 1] + pascal[i - 1][j];
            }
        }
    }
}

void solve()
{
    int m, n, t;
    cin >> m >> n >> t;
    long long noOfWays = pascal[m + n][t];
    // cout << noOfWays << "\n";
    for (int boy = 0; boy < MIN_BOYS_LIMIT; boy++)
    {
        int girl = t - boy;
        if (girl > n)
        {
            continue;
        }
        noOfWays -= pascal[m][boy] * pascal[n][girl];
    }

    for (int girl = 0; girl < MIN_GIRLS_LIMIT; girl++)
    {
        int boy = t - girl;
        if (boy > m)
        {
            continue;
        }
        noOfWays -= pascal[m][boy] * pascal[n][girl];
    }
    cout << noOfWays << "\n";
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    pascalTriangle();
    long t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}

/*

Renaissance-ProgrammingPathshala/M2/Mathematics/Assignment_4/MakingTeams.cpp
1
5 2 5


Out of M+N students, total ways of selecting T students = (M+N)cT
lets say, we don't want the combination where no. of boys = 2 & no. of girls = 1

No. of ways of choosing 2 boys = Mc2
No. of ways of choosing 1 boys = Nc1
Therefore,
No. of ways of choosing 2 boys & 1 girl = Mc2 * Nc1

Therefore no. of ways of selcting T students excluding the combintation (B=2, G=1) is
-> (M+N)cT - (Mc2 * Nc1)

Similarly we are given the below constraints:
B>=4
G>=1
T=B+G

therefore, we would want to exclude the combinations where,
1. G=0 (B = T-0 = T) -> (B=T, G=0)
2. B=0 (G = T-0 = T) -> (B=0, G=T)
3. B=1 (G = T-1) -> (B=1, G=T-1)
4. B=2 (G = T-2) -> (B=2, G=T-2)
5. B=3 (G = T-3) -> (B=3, G=T-3)

No. of ways of choosing:
1. (B=T, G=0) -> McT * Nc0
2. (B=0, G=T) -> Mc0 * NcT
3. (B=1, G=T-1) -> Mc1 * Nc(T-1)
4. (B=2, G=T-2) -> Mc2 * Nc(T-2)
5. (B=3, G=T-3) -> Mc3 * Nc(T-3)
*/