#include <iostream>
#include <vector>
using namespace std;

int getLCM(int a, int b)
{
    int i;
    for (i = max(a, b);; i++)
    {
        if (i % a == 0 && i % b == 0)
            break;
    }
    return i;
}

int main()
{
    long n, t;
    cin >> n >> t;
    vector<vector<double> > pyramid(n + 1, vector<double>(n + 1, 0));
    int fullCups = 0;
    pyramid[0][0] = t;
    for (int row = 0; row < n; row++)
    {
        // cout << "row " << row << "\n";
        for (int cup = 0; cup <= row; cup++)
        {
            if (pyramid[row][cup] >= 1)
            {
                fullCups++;
                pyramid[row][cup]--;
                if (pyramid[row][cup] > 0)
                {

                    pyramid[row + 1][cup] += pyramid[row][cup] / 2;
                    pyramid[row + 1][cup + 1] += pyramid[row][cup] / 2;
                }
                // cout << row << " " << cup << " " << pyramid[row][cup] << "\n";
            }
        }
    }
    cout << fullCups;
    return 0;
}

/*
Renaissance-ProgrammingPathshala/Recursion/HomeWork_1/PyramidOfGlasses.cpp
3 5

Renaissance-ProgrammingPathshala/Recursion/HomeWork_1/PyramidOfGlasses.cpp
4 8

Renaissance-ProgrammingPathshala/Recursion/HomeWork_1/PyramidOfGlasses.cpp
10 1022

Renaissance-ProgrammingPathshala/Recursion/HomeWork_1/PyramidOfGlasses.cpp
7 128

*/