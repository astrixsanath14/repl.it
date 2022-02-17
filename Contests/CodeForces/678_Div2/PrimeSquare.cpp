#include <iostream>
#include <vector>
#define SOME_PRIME_NUMBER_MINUS_ONE 18
using namespace std;

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        int n;
        scanf("%d", &n);
        vector<vector<int> > arr(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++)
        {
            arr[i][i] = SOME_PRIME_NUMBER_MINUS_ONE;
            arr[i][(i + 1) % n] = 1;
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                printf("%d ", arr[i][j]);
            }
            printf("\n");
        }
    }
}

/*
Contests/CodeForces/678_Div2/PrimeSquare.cpp
2
4
2

*/