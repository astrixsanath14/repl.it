#include <iostream>
using namespace std;

long getFactorial(int n)
{
    long fact = 1;
    while (n > 0)
        fact *= n--;
    return fact;
}

void rotateArray(string &arr, int startInd, int endInd)
{
    // cout << "Before: " << arr << "\n";
    char endElement = arr[endInd];
    for (int i = endInd; i > startInd; i--)
    {
        arr[i] = arr[i - 1];
    }
    arr[startInd] = endElement;
    // cout << "After: " << arr << "\n";
}

class Solution
{
public:
    string getPermutation(int n, int k)
    {
        k--;
        string ans = "";
        for (int i = 1; i <= n; i++)
        {
            ans += to_string(i);
        }
        // cout << "n: " << n << " ans: " << ans << "\n";
        long fact = getFactorial(n - 1);
        for (int pos = 0; pos < n - 1; pos++)
        {
            int segment = k / fact;
            int rotateInd = pos + segment;
            // cout << "k: " << k << "\n";
            // cout << "segment: " << segment << "\n";
            // cout << "fact: " << fact << "\n";
            // cout << "pos: " << pos << "\n";
            // cout << "rotateInd: " << rotateInd << "\n";
            rotateArray(ans, pos, rotateInd);
            k = k - segment * fact;
            if (pos < n - 1)
            {
                fact /= (n - 1 - pos);
            }
        }
        return ans;
    }
};

int main()
{
    Solution s;
    int n, k;
    cin >> n >> k;
    cout << s.getPermutation(n, k) << "\n";
}

/*
Input:
Renaissance-ProgrammingPathshala/Live_Class/05_Mar_2022/FindKthPermutation.cpp
3
3

Output:
213

Input:
Renaissance-ProgrammingPathshala/Live_Class/05_Mar_2022/FindKthPermutation.cpp
4
9

Output:
2314


Segment - 0
1 2 3 - 0
1 3 2 - 1

Segment - 1
2 1 3 - 2
2 3 1 - 3

Segment - 2
3 1 2 - 4
3 2 1 - 5
*/