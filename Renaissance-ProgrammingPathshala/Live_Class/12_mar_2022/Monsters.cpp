// https://cses.fi/problemset/task/1194/
#include <queue>
#include <map>
#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <limits.h>
using namespace std;

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
string direction[] = {"U", "D", "L", "R"};
string reverseDirection[] = {"D", "U", "R", "L"};

bool canPrintOutputInScreen = false;
bool canPrintOutputInFile = false;

ofstream tracesout;
string outname = string("//debug.txt");
template <typename T>

void debug(T s)
{
    if (canPrintOutputInFile)
    {
        tracesout << "\n"
                  << s << "\n";
    }
    if (canPrintOutputInScreen)
    {
        cout << "\n"
             << s << "\n";
    }
}

void printVector(vector<vector<int> > &input)
{
    if (canPrintOutputInScreen)
    {
        int n = input.size();
        int m = input[0].size();
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cout << input[i][j] << " ";
            }
            cout << "\n";
        }
        cout << "\n";
    }
}

string getPath(int i, int j, int &n, int &m, int &yourDist, vector<vector<int> > &yourDistanceGraph)
{
    string path = "";
    while (yourDist)
    {
        // //debug("yourDist: " + to_string(yourDist));
        for (int dir = 0; dir < 4; dir++)
        {
            int newX = i + dx[dir];
            int newY = j + dy[dir];
            if (newX >= 0 && newX < n && newY >= 0 && newY < m)
            {
                if (yourDistanceGraph[newX][newY] == yourDist - 1)
                {
                    path = reverseDirection[dir] + path;
                    i = newX;
                    j = newY;
                    break;
                }
            }
        }
        yourDist--;
    }
    return path;
}

bool checkIfEscaped(vector<vector<int> > &graph, int i, int j, int &n, int &m, vector<vector<int> > &yourDistanceGraph, vector<vector<int> > &monsterDistanceGraph)
{
    // debug("checkIfEscaped i: " + to_string(i) + " j: " + to_string(j));
    if (graph[i][j])
    {
        int yourDist = INT_MAX;
        int monsterDist = INT_MAX;
        // if (yourVisited.find({i, j}) != yourVisited.end())
        // {
        //     yourDist = yourVisited[{i, j}];
        // }
        // if (monsterVisited.find({i, j}) != monsterVisited.end())
        // {
        //     monsterDist = monsterVisited[{i, j}];
        // }
        yourDist = yourDistanceGraph[i][j];
        monsterDist = monsterDistanceGraph[i][j];
        // debug("i: " + to_string(i) + " j: " + to_string(j) + " yourDist: " + to_string(yourDist) + " monsterDist: " + to_string(monsterDist));
        if (yourDist < monsterDist)
        {
            cout << "YES"
                 << "\n";
            cout << yourDist << "\n";
            string path = getPath(i, j, n, m, yourDist, yourDistanceGraph);
            cout << path << "\n";
            // cout << yourVisited[{i, j}].second << "\n";
            // cout << "Escaped " << i << " " << j << " " <<yourDist << " " << yourVisited[{i, j}].second << "\n";
            // debug("Escaped " + to_string(i) + " " + to_string(j) + " " + path);
            return true;
        }
    }
    return false;
}

void solve(int &n, int &m)
{
    // Multi source bfs

    vector<vector<int> > graph(n, vector<int>(m));
    vector<vector<int> > monsterDistanceGraph(n, vector<int>(m));
    vector<vector<int> > yourDistanceGraph(n, vector<int>(m));
    // int graph[n][m];
    // int monsterDistanceGraph[n][m];
    // int yourDistanceGraph[n][m];
    queue<pair<int, int> >
        monsterQueue;
    pair<int, int> startPos;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            char c;
            cin >> c;
            graph[i][j] = c == '.' || c == 'A';
            if (c == 'A')
            {
                startPos = {i, j};
            }
            else if (c == 'M')
            {
                monsterQueue.push({i, j});
            }
            monsterDistanceGraph[i][j] = INT_MAX;
            yourDistanceGraph[i][j] = INT_MAX;
        }
    }
    int depth = 1;
    while (!monsterQueue.empty())
    {
        int queueSize = monsterQueue.size();
        // cout << "Queue Size: " << queueSize<< "\n";
        // debug("Queue Size: " + to_string(queueSize));
        for (int i = 0; i < queueSize; i++)
        {
            pair<int, int> pos = monsterQueue.front();
            // cout << "i: " << pos.first << " j: " << pos.second << "\n";
            // debug("i: " + to_string(pos.first) + " j: " + to_string(pos.second));
            monsterQueue.pop();
            for (int dir = 0; dir < 4; dir++)
            {
                int newX = pos.first + dx[dir];
                int newY = pos.second + dy[dir];
                if (newX >= 0 && newX < n && newY >= 0 && newY < m)
                {
                    pair<int, int> newPos(newX, newY);
                    if (graph[newX][newY] && monsterDistanceGraph[newPos.first][newPos.second] == INT_MAX)
                    {
                        monsterDistanceGraph[newPos.first][newPos.second] = depth;
                        monsterQueue.push(newPos);
                    }
                }
            }
        }
        depth++;
    }

    // cout << "Multi Source BFS done"<< "\n";
    // debug("Monster Source BFS done");

    queue<pair<int, int> > yourQueue;
    yourDistanceGraph[startPos.first][startPos.second] = 0;
    yourQueue.push(startPos);
    depth = 1;
    if (startPos.first == 0 || startPos.first == n - 1 || startPos.second == 0 || startPos.second == m - 1)
    {
        cout << "YES"
             << "\n";
        cout << 0 << "\n";
        return;
    }
    while (!yourQueue.empty())
    {
        int queueSize = yourQueue.size();
        for (int i = 0; i < queueSize; i++)
        {
            pair<int, int> pos = yourQueue.front();
            // debug("i: " + to_string(pos.first) + " j: " + to_string(pos.second));
            yourQueue.pop();
            for (int dir = 0; dir < 4; dir++)
            {
                int newX = pos.first + dx[dir];
                int newY = pos.second + dy[dir];
                if (newX >= 0 && newX < n && newY >= 0 && newY < m)
                {
                    pair<int, int> newPos(newX, newY);
                    if (graph[newX][newY] && yourDistanceGraph[newPos.first][newPos.second] == INT_MAX)
                    {
                        yourDistanceGraph[newPos.first][newPos.second] = depth;
                        yourQueue.push(newPos);
                        if (newX == 0 || newX == n - 1 || newY == 0 || newY == m - 1)
                        {
                            if (checkIfEscaped(graph, newX, newY, n, m, yourDistanceGraph, monsterDistanceGraph))
                                return;
                        }
                    }
                }
            }
        }
        depth++;
    }
    // debug("Your Source BFS done");

    // printVector(monsterDistanceGraph);
    // printVector(yourDistanceGraph);
    // for (int i = 0; i < n; i++)
    // {
    //     if (checkIfEscaped(graph, i, 0, n, m, yourDistanceGraph, monsterDistanceGraph))
    //         return;
    //     if (checkIfEscaped(graph, i, m - 1, n, m, yourDistanceGraph, monsterDistanceGraph))
    //         return;
    // }

    // for (int j = 0; j < m; j++)
    // {
    //     if (checkIfEscaped(graph, 0, j, n, m, yourDistanceGraph, monsterDistanceGraph))
    //         return;
    //     if (checkIfEscaped(graph, n - 1, j, n, m, yourDistanceGraph, monsterDistanceGraph))
    //         return;
    // }
    // cout << "isEcaped done."<< "\n";
    cout << "NO"
         << "\n";
}

int main()
{
    if (canPrintOutputInFile)
    {
        tracesout.open(outname.c_str());
    }
    FILE *FP;         // File handler
    char *trace_file; // Variable that holds trace file name;
    FP = fopen(trace_file, "r");
    if (canPrintOutputInFile && FP == NULL)
    {
        // Throw error and exit if fopen() failed
        printf("Error: Unable to open file %s\n", trace_file);
        exit(EXIT_FAILURE);
    }
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, m;
    cin >> n >> m;
    // debug("Input Done.");
    solve(n, m);

    // cout << "Output Done"<< "\n";
    // debug("Output Done.");
    if (canPrintOutputInFile)
    {
        tracesout.close();
    }
    return 0;
}

/*
Input 1:
5 8
########
#M..A..#
#.#.M#.#
#M#..#..
#.######

Output 1:
YES
5
RRDDR

Renaissance-ProgrammingPathshala/Live_Class/12_mar_2022/Monsters.cpp
5 8
########
#M..A..#
#.#.M#.#
#M#..#..
#.######

Input 2:
5 8
########
#M..A..#
#.#.M#.#
#M#..#.#
#.######

Output 2:
NO

Renaissance-ProgrammingPathshala/Live_Class/12_mar_2022/Monsters.cpp
5 8
########
#M..A..#
#.#.M#.#
#M#..#.#
#.######


Input 3:
5 8
########
#M..A..#
#.#.M#.#
#M#..#.#
#.######

Output 3:
NO

Renaissance-ProgrammingPathshala/Live_Class/12_mar_2022/Monsters.cpp
5 8
########
#M..A..#
#.#.M#.#
#M#..#.#
#.####.#

Renaissance-ProgrammingPathshala/Live_Class/12_mar_2022/Monsters.cpp
1 1
A

Renaissance-ProgrammingPathshala/Live_Class/12_mar_2022/Monsters.cpp
3 3
MMM
MAM
MMM

Renaissance-ProgrammingPathshala/Live_Class/12_mar_2022/Monsters.cpp
1 3
##A
*/