/*
CPP/PriorityQueue.cpp
10
1 2 3 4 5 5 6 7 8 9
1

CPP/PriorityQueue.cpp
10
1 2 3 4 5 5 6 7 8 9
2

CPP/PriorityQueue.cpp
10
1 2 3 4 5 5 6 7 8 9
5

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

void printPriorityQueue(priority_queue<int> pq)
{
    while (!pq.empty())
    {
        cout << pq.top() << ' ';
        pq.pop();
    }
}

int main()
{
    priority_queue<int> pq;

    vector<int> vec{10, 2, 4, 8, 6, 9};
    // pushing array sequentially one by one
    for (int i = 0; i < vec.size(); i++)
    {
        pq.push(vec[i]);
    }

    while (true)
    {
        print("\n");
        print("1. Insert into Queue");
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
            int value;
            print("Enter value to be inserted: ");
            read(value);
            pq.push(value);
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