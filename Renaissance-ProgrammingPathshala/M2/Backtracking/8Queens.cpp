#include <iostream>
#include <tuple>
#include <vector>
#include <map>
#include <limits.h>
using namespace std;

tuple<int, int, bool> getDiagonal(int row, int col, int &n, bool isLeftDiagnonal)
{
    // cout << row << " " << col << " " << isLeftDiagnonal << " ";
    while (row != 0)
    {
        if ((isLeftDiagnonal && col == 0) || (!isLeftDiagnonal && col == n - 1))
        {
            break;
        }
        row--;
        if (isLeftDiagnonal)
        {
            col--;
        }
        else
        {
            col++;
        }
    }
    // cout << "row: " << row << " col: " << col << "\n";
    return make_tuple(row, col, isLeftDiagnonal);
}

tuple<int, int, bool> getLeftDiagonal(int &row, int &col, int &n)
{
    return getDiagonal(row, col, n, true);
}

tuple<int, int, bool> getRightDiagonal(int &row, int &col, int &n)
{
    return getDiagonal(row, col, n, false);
}

bool isSafe(int &row, int &col, int &n, vector<int> &verticalMatrix, map<tuple<int, int, bool>, int> &diagonalMatrix)
{
    int verticalSafe = verticalMatrix[col] == 0;
    int leftDiagonalSafe = diagonalMatrix[getLeftDiagonal(row, col, n)] == 0;
    int rightDiagonalSafe = diagonalMatrix[getRightDiagonal(row, col, n)] == 0;
    // cout << "Safe " << row << " " << col << " " << verticalSafe << " " << leftDiagonalSafe << " " << rightDiagonalSafe << "\n";
    if (verticalSafe && leftDiagonalSafe && rightDiagonalSafe)
    {
        return true;
    }
    return false;
}

void mark(int &row, int &col, int &n, vector<int> &verticalMatrix, map<tuple<int, int, bool>, int> &diagonalMatrix, int isOccupied)
{

    verticalMatrix[col] = isOccupied;
    diagonalMatrix[getLeftDiagonal(row, col, n)] = isOccupied;
    diagonalMatrix[getRightDiagonal(row, col, n)] = isOccupied;
    // cout << "mark " << row << " " << col << " " << isOccupied << " " << verticalMatrix[col] << " " << diagonalMatrix[getLeftDiagonal(row, col, n)] << " " << diagonalMatrix[getRightDiagonal(row, col, n)] << "\n";
}

void nQueens(int row, int &n, vector<vector<int> > &board, vector<vector<vector<int> > > &combos, vector<int> &verticalMatrix, map<tuple<int, int, bool>, int> &diagonalMatrix)
{
    if (row == n)
    {
        combos.push_back(board);
        return;
    }
    // cout << "row: " << row << "\n";
    for (int col = 0; col < n; col++)
    {
        if (isSafe(row, col, n, verticalMatrix, diagonalMatrix))
        {
            board[row][col] = 1;
            // cout << "mark row " << row << " " << col << "\n";
            mark(row, col, n, verticalMatrix, diagonalMatrix, 1);
            nQueens(row + 1, n, board, combos, verticalMatrix, diagonalMatrix);
            mark(row, col, n, verticalMatrix, diagonalMatrix, 0);
            board[row][col] = 0;
            // cout << "unmark row " << row << " " << col << "\n";
        }
    }
}

void printCombos(vector<vector<vector<int> > > &combos)
{
    int count = 1;
    for (vector<vector<int> > board : combos)
    {
        cout << "\n----- Board " << count << " -----\n";
        for (int row = 0; row < board.size(); row++)
        {
            for (int col = 0; col < board.size(); col++)
            {
                cout << board[row][col] << " ";
            }
            cout << "\n";
        }

        count++;
    }
}

void initHorizontalPositions(vector<vector<vector<int> > > &combos, vector<vector<int> > &nQueensHorizontalPosMatrix)
{
    for (vector<vector<int> > board : combos)
    {
        vector<int> horizontalPositions;
        for (int col = 0; col < board.size(); col++)
        {
            for (int row = 0; row < board.size(); row++)
            {
                // cout << board[row][col] << " ";
                if (board[row][col])
                {
                    horizontalPositions.push_back(row);
                }
            }

            // cout << "Found at row: " << horizontalPositions[horizontalPositions.size() - 1] << " col: " << col << "\n";
            // cout << "\n";
        }
        nQueensHorizontalPosMatrix.push_back(horizontalPositions);
    }
}

int getMinChanges(vector<vector<int> > &nQueensHorizontalPosMatrix, vector<int> &horizontalPositions)
{
    int minChanges = INT_MAX, count = 1;
    for (vector<int> nQueensHorizontalPositions : nQueensHorizontalPosMatrix)
    {
        // cout << nQueensHorizontalPositions.size() << "\n";
        int changes = 0;

        for (int col = 0; col < nQueensHorizontalPositions.size(); col++)
        {
            // cout << horizontalPositions[col] << " " << nQueensHorizontalPositions[col] << "\n";
            if (horizontalPositions[col] - 1 != nQueensHorizontalPositions[col])
                changes++;
        }
        // cout << "Board: " << count++ << ": " << changes << "\n";
        minChanges = min(minChanges, changes);
    }
    return minChanges;
}

int main()
{
    int n = 8;
    vector<vector<int> > board(n, vector<int>(n, 0)), nQueensHorizontalPosMatrix;
    vector<vector<vector<int> > > combos;
    vector<int> verticalMatrix(n, 0);
    map<tuple<int, int, bool>, int> diagonalMatrix;
    nQueens(0, n, board, combos, verticalMatrix, diagonalMatrix);
    initHorizontalPositions(combos, nQueensHorizontalPosMatrix);
    // printCombos(combos);
    int caseNo = 1;
    vector<int> horizontalPositions(n);
    while (cin >> horizontalPositions[0])
    {
        for (int col = 1; col < 8; col++)
        {
            cin >> horizontalPositions[col];
        }
        cout << "Case " << caseNo++ << ": " << getMinChanges(nQueensHorizontalPosMatrix, horizontalPositions) << "\n";
    }
    return 0;
}

/*
Renaissance-ProgrammingPathshala/M2/Backtracking/8Queens.cpp
2 1 3 4 5 6 7 8

Renaissance-ProgrammingPathshala/M2/Backtracking/8Queens.cpp
2 1 3 4 5 6 7 8
1 1 1 1 1 1 1 1
2 7 3 6 8 5 1 4

Renaissance-ProgrammingPathshala/M2/Backtracking/8Queens.cpp
2 7 3 6 8 5 1 4
*/