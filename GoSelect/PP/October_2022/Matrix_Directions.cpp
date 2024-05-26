#include <bits/stdc++.h>
using namespace std;

map<string, int> dx, dy;

int main() {
	dx["RIGHT"] = 0;
	dx["LEFT"] = 0;
	dx["UP"] = -1;
	dx["DOWN"] = 1;
	dy["RIGHT"] = 1;
	dy["LEFT"] = -1;
	dy["UP"] = 0;
	dy["DOWN"] = 0;

	int m;
	cin >> m;
	int arr[m][m];
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
		}
	}
	int j;
	cin >> j;
	int posX = 0, posY = 0;
	for (int i = 0; i < j; i++) {
		string direction;
		cin >> direction;
		posX += dx[direction];
		posY += dy[direction];
		if (posX < 0 || posY < 0 || posX >= m || posY >= m) {
			posX -= dx[direction];
			posY -= dy[direction];
		}
	}
	cout << arr[posX][posY];
	return 0;
}

/*
GoSelect/PP/October_2022/Matrix_Directions.cpp
4
1 2 3 4
5 6 7 8
9 10 11 12
13 14 15 16
6
RIGHT
DOWN
RIGHT
DOWN
LEFT
UP

*/