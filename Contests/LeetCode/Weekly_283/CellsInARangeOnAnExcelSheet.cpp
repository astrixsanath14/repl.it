#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<string> cellsInRange(string s)
    {
        vector<string> cells;
        char startCol = s[0], endCol = s[3];
        int startRow = s[1] - '0', endRow = s[4] - '0';
        for (int i = startCol; i <= endCol; i++)
        {
            for (int j = startRow; j <= endRow; j++)
            {
                string cell = (char)i + to_string(j);
                cells.push_back(cell);
            }
        }
        return cells;
    }
};

int main()
{
    Solution s;
    string ss;
    cin >> ss;
    vector<string> cells = s.cellsInRange(ss);
    for (string cell : cells)
    {
        cout << cell << " ";
    }
    cout << "\n";
    return 0;
}

/*
Contests/LeetCode/CellsInARangeOnAnExcelSheet.cpp
A1:F1
*/