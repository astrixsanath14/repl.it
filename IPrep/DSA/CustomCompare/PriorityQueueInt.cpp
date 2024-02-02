/*
IPrep/DSA/CustomCompare/PriorityQueueInt.cpp

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
    bool operator()(int a, int b)
    {
        return a > b;
    }
};

void printMaxHeapPQ(priority_queue<int> pq)
{
    cout << "PQ: \n";
    while (!pq.empty())
    {
        cout << pq.top() << "\n";
        pq.pop();
    }
    cout << "\n";
}
void printMinHeapPQ(priority_queue<int, vector<int>, greater<int> > pq)
{
    cout << "PQ: \n";
    while (!pq.empty())
    {
        cout << pq.top() << "\n";
        pq.pop();
    }
    cout << "\n";
}

int main()
{
    priority_queue<int> maxHeapPQ;
    priority_queue<int, vector<int>, greater<int> > minHeapPQ;
    // priority_queue<int> pq;
    vector<int> vec;
    vec.push_back(2);
    vec.push_back(1);
    vec.push_back(-101);
    vec.push_back(5);
    vec.push_back(3);
    // pushing array sequentially one by one
    for (int i = 0; i < vec.size(); i++)
    {
        maxHeapPQ.push(vec[i]);
        minHeapPQ.push(vec[i]);
    }

    while (true)
    {
        print("\n");
        print("1. Print Max Heap PQ");
        print("\n");
        print("2. Print Min Heap PQ");
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
            printMaxHeapPQ(maxHeapPQ);
            break;
        }

        case 2:
        {
            printMinHeapPQ(minHeapPQ);
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