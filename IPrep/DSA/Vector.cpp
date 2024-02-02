// CPP/Vector.cpp

#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<int> v;
    v.push_back(10);
    v.push_back(20);
    v.push_back(30);
    v.push_back(40);

    v.insert(v.begin(), 50);

    v.pop_back();
    return 0;
}