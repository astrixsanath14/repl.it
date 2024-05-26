#include <iostream>
#include <vector>
#include <numeric>
#include <math.h>

#define ull long long
using namespace std;

ull isSetAtPos(ull n, ull pos, ull len)
{
    // cout << n << " " << pos << " " << len << " \n";
    if (n == 1)
    {
        return 1;
    }
    ull nextLen = len / 2;
    if ((nextLen + 1) == pos)
    {
        return n & 1;
    }
    ull nextPos = (pos > nextLen) ? (pos - nextLen - 1) : pos;
    // cout << n << " " << nextPos << " " << nextLen << "\n---\n";
    return isSetAtPos(n / 2, nextPos, nextLen);
}

ull getLen(ull n)
{
    int noOfBits = n == 2 ? 2 : ceil(log2(n));
    return pow(2, noOfBits) - 1;
}

ull getLen2(ull n)
{
    ull len = 1;
    while (len < n)
    {
        len = len * 2 + 1;
    }
    return len;
}

ull solve(ull &n, ull &l, ull &r)
{
    ull count = 0;
    if (n <= 1)
    {
        return n;
    }
    ull len = getLen2(n);

    for (ull pos = l; pos <= r; pos++)
    {
        if (pos % 2)
        {
            count++;
            continue;
        }
        int isSet = isSetAtPos(n, pos, len);
        // cout << "pos:: " << pos << " isSet:: " << isSet << "\n";
        count += isSet;
    }
    return count;
}

ull solve(ull n, ull &l, ull &r, ull &ind)
{
    if (n == 1)
    {
        int res = ind >= l && ind <= r;
        ind++;
        return res;
    }
    if (!n)
    {
        // cout << ind++ << " " << n << "\n";
        ind++;
        return 0;
    }
    int count1 = solve(n / 2, l, r, ind);
    int count2 = solve(n % 2, l, r, ind);
    int count3 = solve(n / 2, l, r, ind);
    return count1 + count2 + count3;
}

int main()
{
    ull n, l, r;
    cin >> n >> l >> r;
    // ull ind = 1;
    // cout << solve(n, l, r, ind);

    cout << solve(n, l, r) << "\n";
    return 0;
}

/*
Renaissance-ProgrammingPathshala/Recursion/HomeWork_2/CodeFor1.cpp
7 2 5

Renaissance-ProgrammingPathshala/Recursion/HomeWork_2/CodeFor1.cpp
10 3 10

Renaissance-ProgrammingPathshala/Recursion/HomeWork_2/CodeFor1.cpp
1 0 1

Renaissance-ProgrammingPathshala/Recursion/HomeWork_2/CodeFor1.cpp
2 2 2

Renaissance-ProgrammingPathshala/Recursion/HomeWork_2/CodeFor1.cpp
4 2 2

10 -> 5 0 5 -> 1 0 1 1 1 0 1 0 1 0 1 1 1 0 1
5 -> 2 1 2  -> 1 0 1 1 1 0 1
2 -> 1 0 1  -> 1 0 1
pos === 1   2   3   4   5   6   7   8   9   10  11  12  13  14  15
10  === 1   0   1   1   1   0   1   0   1   0   1   1   1   0   1

Renaissance-ProgrammingPathshala/Recursion/HomeWork_2/CodeFor1.cpp
903316762502 354723010040 354723105411

1 -> 1      -> 1                                1 len -> 1 (1 bit)
2 -> 1 0 1  -> 1 0 1                            3 len -> 10 (2 bits)
3 -> 1 1 1  -> 1 1 1                            3 len -> 11 (2 bits)
4 -> 2 0 2  -> 1 0 1 0 1 0 1                    7 len -> 100 (3 bits)
5 -> 2 1 2  -> 1 0 1 1 1 0 1                    7 len -> 101 (3 bits)
6 -> 3 0 3  -> 1 1 1 0 1 1 1                    7 len -> 110 (3 bits)
7 -> 3 1 3  -> 1 1 1 1 1 1 1                    7 len -> 111 (3 bits)
8 -> 4 0 4  -> 1 0 1 0 1 0 1 0 1 0 1 0 1 0 1    15 len -> 1000 (4 bits)
9 -> 4 1 4  -> 1 0 1 0 1 0 1 1 1 0 1 0 1 0 1    15 len -> 1001 (4 bits)
10 -> 5 0 5 -> 1 0 1 1 1 0 1 0 1 0 1 1 1 0 1    15 len -> 1010 (4 bits)
11 -> 5 1 5 -> 1 0 1 1 1 0 1 1 1 0 1 1 1 0 1    15 len -> 1011 (4 bits)
12 -> 6 0 6 -> 1 1 1 0 1 1 1 0 1 1 1 0 1 1 1    15 len -> 1100 (4 bits)
13 -> 6 1 6 -> 1 1 1 0 1 1 1 1 1 1 1 0 1 1 1    15 len -> 1101 (4 bits)
14 -> 7 0 7 -> 1 1 1 1 1 1 1 0 1 1 1 1 1 1 1    15 len -> 1110 (4 bits)
15 -> 7 1 7 -> 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1    15 len -> 1111 (4 bits)
*/