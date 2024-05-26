/*
CPP/Sort.cpp

*/

#include <iostream>
#include <vector>
using namespace std;

void print(vector<int> &arr)
{
    for (int num : arr)
        cout << num << "\n";
}

bool descendingCompare(int a, int b)
{
    return a > b;
}

int main()
{
    vector<int> arr = {1, 2, 3, 4, 5, 4};
    sort(arr.begin(), arr.end());

    cout << arr.size() << "\n";
    cout << "Default sort\n";
    print(arr);

    cout << "descendingCompare sort\n";
    sort(arr.begin(), arr.end(), descendingCompare);
    print(arr);
}