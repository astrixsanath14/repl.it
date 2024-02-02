/*
CPP/CustomCompare/UpperAndLowerBound.cpp
10
1 2 3 4 5 5 6 7 8 9
1

CPP/CustomCompare/UpperAndLowerBound.cpp
10
1 2 3 4 5 5 6 7 8 9
2

CPP/CustomCompare/UpperAndLowerBound.cpp
10
1 2 3 4 5 5 6 7 8 9
5

*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#define readVector(n, vec)      \
    for (int i = 0; i < n; i++) \
        cin >> vec[i];
#define printVector(vec)                 \
    for (int i = 0; i < vec.size(); i++) \
        cout << vec[i] << " ";
#define read(val) cin >> val
#define print(val) cout << val
using namespace std;

int main()
{
    int n;
    print("Enter n:\n");
    read(n);
    vector<int> vp(n);
    print("Enter vector:\n");
    readVector(n, vp);
    print("Array is\n");
    printVector(vp);
    print("\n");
    while (true)
    {
        print("\n");
        print("1. Find Upper Bound");
        print("\n");
        print("2. Find Lower Bound");
        print("\n");
        print("3. Exit");
        print("\n");
        print("Choice? ");
        int choice;
        read(choice);
        bool end = false;
        switch (choice)
        {
        case 1:
        {
            int findUpperBound;
            print("Enter value to find upper bound: ");
            read(findUpperBound);
            auto ub = upper_bound(vp.begin(), vp.end(), findUpperBound, [](const int &element, int value)
                                  { cout <<"Compare:: "<<element << " "<< value<<"\n"; return element > value; });
            print("Upper bound of " + to_string(findUpperBound) + " is " + to_string(*ub) + " pos: " + to_string(ub - vp.begin()));
            break;
        }

        case 2:
        {
            int findLowerBound;
            print("Enter value to find lower bound: ");
            read(findLowerBound);
            auto lb = lower_bound(vp.begin(), vp.end(), findLowerBound);
            print("Lower bound of " + to_string(findLowerBound) + " is " + to_string(*lb) + " pos: " + to_string(lb - vp.begin()));
            break;
        }
        case 3:
            end = true;
            break;
        default:
            print("Invalid choice! Hence, quitting!");
            print("\n");
            end = true;
        }
        if (end)
        {
            break;
        }
    }
    print("GOOD BYE!");
    return 0;
}