#include <bits/stdc++.h>
using namespace std;
#define MAX_LIMIT 100000 + 5
long long colorGrid[MAX_LIMIT];

void sieve(long long sieveMaxLimit)
{
    // cout << "Creating Sieve of Eratosthens for array size " << sieveMaxLimit << " "<< "\n";
    memset(colorGrid, 0, sizeof(colorGrid));
    colorGrid[0] = 1;
    colorGrid[1] = 1;
    for (long long i = 2; i <= sieveMaxLimit; i++)
    {
        if (colorGrid[i] == 0)
        {
            colorGrid[i] = 1;
            for (long long j = 2; i * j <= sieveMaxLimit; j++)
            {
                if (colorGrid[i * j] == 0)
                {
                    colorGrid[i * j] = 2;
                }
            }
        }
    }
    // cout << "Completed creating Sieve of Eratosthens for array size " << sieveMaxLimit << " "<< "\n";
}

void printColorGrid(int n)
{
    cout << (n > 3 ? 2 : 1) << "\n";
    for (int i = 2; i <= n; i++)
    {
        cout << colorGrid[i] << " ";
    }
    cout << "\n";
}

int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    sieve(n + 1);
    printColorGrid(n + 1);
    return 0;
}

/*
Input:
Renaissance-ProgrammingPathshala/M2/Mathematics/HomeWork_2/SherlockAndHisGirlfriend.cpp
4

Output:
2
1 1 2 1

Input:
Renaissance-ProgrammingPathshala/M2/Mathematics/HomeWork_2/SherlockAndHisGirlfriend.cpp
1

Output:
1
1

Input:
Renaissance-ProgrammingPathshala/M2/Mathematics/HomeWork_2/SherlockAndHisGirlfriend.cpp
2

Output:
1
1 1
*/