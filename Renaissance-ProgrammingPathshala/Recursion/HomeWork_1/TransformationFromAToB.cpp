#include <iostream>
#include <vector>
using namespace std;

void transformFromAToB(long long a, long long &b, vector<long long> &res)
{
    if (a == b)
    {
        res.push_back(a);
        return;
    }
    if (a > b)
        return;
    long long nextA = 2 * a;
    transformFromAToB(nextA, b, res);
    if (res.size() > 0)
    {
        res.insert(res.begin(), a);
        return;
    }

    nextA = a * 10 + 1;
    transformFromAToB(nextA, b, res);
    if (res.size() > 0)
    {
        res.insert(res.begin(), a);
        return;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    long long a, b;
    cin >> a >> b;
    vector<long long> res;
    transformFromAToB(a, b, res);
    if (res.size() == 0)
        cout << "NO";
    else
    {
        cout << "YES\n";
        cout << res.size() << "\n";
        for (long long val : res)
            cout << val << " ";
    }
    return 0;
}

/*
Renaissance-ProgrammingPathshala/Recursion/HomeWork_1/TransformationFromAToB.cpp
2 162

Renaissance-ProgrammingPathshala/Recursion/HomeWork_1/TransformationFromAToB.cpp
4 42

Renaissance-ProgrammingPathshala/Recursion/HomeWork_1/TransformationFromAToB.cpp
100 40021

Renaissance-ProgrammingPathshala/Recursion/HomeWork_1/TransformationFromAToB.cpp
1 1

Renaissance-ProgrammingPathshala/Recursion/HomeWork_1/TransformationFromAToB.cpp
2 8589934592
*/