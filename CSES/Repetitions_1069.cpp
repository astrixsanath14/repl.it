#include <iostream>
#include <string>
using namespace std;

int main()
{
    string s;
    cin >> s;
    long maxRepetition = 0, prevCount = 0;
    char prev = 'a' - 1;
    for (char c : s)
    {
        prevCount = prev == c ? prevCount + 1 : 1;
        maxRepetition = max(maxRepetition, prevCount);
        prev = c;
    }
    cout << maxRepetition << "\n";
    return 0;
}

/*
CSES/Repetitions_1069.cpp
A
*/