/*
IPrep/DSA/CustomCompare/PriorityQueue.cpp

*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
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

class Compare
{
public:
    bool operator()(pair<int, int> a, pair<int, int> b)
    {
        if (a.first == b.first)
            return a.second > b.second;
        return a.first > b.first;
    }
};

void printPriorityQueue(priority_queue<pair<int, int>, vector<pair<int, int> >, Compare> pq)
{
    cout << "PQ: \n";
    while (!pq.empty())
    {
        cout << pq.top().first << ' ' << pq.top().second << "\n";
        pq.pop();
    }
    cout << "\n";
}

int main()
{
    priority_queue<pair<int, int>, vector<pair<int, int> >, Compare> pq;
    vector<pair<int, int> > vec;
    vec.push_back({0, 2});
    vec.push_back({0, 1});
    vec.push_back({0, -10});
    vec.push_back({3, 1});
    vec.push_back({1, 1});
    vec.push_back({1, 1});
    // pushing array sequentially one by one
    for (int i = 0; i < vec.size(); i++)
    {
        pq.push(vec[i]);
    }

    while (true)
    {
        print("\n");
        print("1. Pop");
        print("\n");
        print("2. Print Queue");
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
            cout << "Top of PQ: " << pq.top().first << " " << pq.top().second;
            break;
        }

        case 2:
        {
            printPriorityQueue(pq);
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