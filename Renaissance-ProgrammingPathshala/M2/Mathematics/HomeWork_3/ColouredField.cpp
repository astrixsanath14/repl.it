#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, m, k, t;
    cin >> n >> m >> k >> t;
    vector<string> crops{"Carrots", "Kiwis", "Grapes"};
    vector<vector<int>> wasteCells(k, vector<int>(2));
    map<pair<int, int>, bool> isWasteCell;
    for (int i = 0; i < k; i++)
    {
        cin >> wasteCells[i][0] >> wasteCells[i][1];
        isWasteCell[{wasteCells[i][0], wasteCells[i][1]}] = true;
    }
    while (t--)
    {
        int x, y;
        cin >> x >> y;
        if (isWasteCell[{x, y}])
        {
            cout << "Waste";
        }
        else
        {
            int noOfWasteCells = 0;
            for (int i = 0; i < k; i++)
            {
                if (wasteCells[i][0] < x || (wasteCells[i][0] == x && wasteCells[i][1] < y))
                {
                    noOfWasteCells++;
                }
            }
            int totalCells = (x - 1) * m + y;
            int totalCropCells = totalCells - noOfWasteCells;
            // cout << x << " " << y << " " << totalCells << " " << noOfWasteCells << " " << totalCropCells << " ";
            cout << crops[(totalCropCells - 1) % 3];
        }
        cout << "\n";
    }
    return 0;
}

/*
Renaissance-ProgrammingPathshala/M2/Mathematics/HomeWork_3/ColouredField.cpp
4 5 5 6
4 3
1 3
3 3
2 5
3 2
1 3
1 4
2 3
2 4
1 1
1 1

̧Input
4 5 5 6
4 3
1 3
3 3
2 5
3 2
1 3
1 4
2 3
2 4
1 1
1 1

Output
Waste
Grapes
Carrots
Kiwis
Carrots
Carrots
*/