#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

// map<char, int> opVsInd;
// opVsInd['+'] = 0;
// opVsInd['-'] = 1;
// opVsInd['*'] = 2;
// opVsInd['/'] = 3;

vector<char> possibleOps({'+', '-', '*', '/'});
double eps = 0.1;

class Solution
{
public:
    double getVal(double val1, char op, double val2)
    {
        double val;
        switch (op)
        {
        case '+':
            val = val1 + val2;
            break;
        case '-':
            val = val1 - val2;
            break;
        case '*':
            val = val1 * val2;
            break;
        case '/':
            val = val1 / val2;
            break;
        }
        cout << "eval " << val1 << " " << op << " " << val2 << " = " << val << "\n";
        return val;
    }

    bool evaluateAndJudgeForResult(vector<double> cards, vector<char> ops, int &expectedResult)
    {
        if (cards.size() == 1)
        {
            cout << "val: " + to_string(cards[0]) << "\n";
            return abs(cards[0] - expectedResult) <= eps;
        }
        // cout << "cards.size(): " << cards.size() << "\n";
        vector<double> nextCards(cards.size() - 1);
        vector<char> nextOps(nextCards.size() - 1);
        for (int i = 0; i < cards.size() - 1; i++)
        {
            if (!(cards[i + 1] == 0 && ops[i] == '/'))
            {
                double val = getVal(cards[i], ops[i], cards[i + 1]);
                nextCards[i] = val;
                for (int j = i + 2; j < cards.size(); j++)
                {
                    nextCards[j - 1] = cards[j];
                }
                for (int j = i + 1; j < ops.size(); j++)
                {
                    nextOps[j - 1] = ops[j];
                }
                if (evaluateAndJudgeForResult(nextCards, nextOps, expectedResult))
                {
                    return true;
                }
            }

            nextCards[i] = cards[i];
            if (i < nextOps.size())
            {
                nextOps[i] = ops[i];
            }
        }
        // cout<<"done\n";
        return false;
    }

    string getExp(vector<double> &cards, vector<char> &ops)
    {
        string exp = "";
        for (int i = 0; i < cards.size() - 1; i++)
        {
            exp += to_string(cards[i]) + " " + ops[i] + " ";
        }
        exp += to_string(cards[cards.size() - 1]);
        return exp;
    }

    bool generateEquations(vector<int> &cardVals, vector<double> &cards, vector<char> &ops, int ind, int &expectedResult)
    {
        bool isLastInd = ind == cardVals.size() - 1;
        // cout << ind << "\n";
        for (int i = 0; i < cardVals.size(); i++)
        {
            if (cardVals[i] == -1)
            {
                continue;
            }
            cards[ind] = (double)cardVals[i];
            cardVals[i] = -1;
            if (isLastInd)
            {
                cout << "Judging: " << getExp(cards, ops) << "\n";
                if (evaluateAndJudgeForResult(cards, ops, expectedResult))
                {
                    return true;
                }
            }
            else
            {
                for (char op : possibleOps)
                {
                    ops[ind] = op;
                    if (generateEquations(cardVals, cards, ops, ind + 1, expectedResult))
                    {
                        return true;
                    }
                }
            }
            cardVals[i] = cards[ind];
        }
        return false;
    }

    bool judgePoint24(vector<int> &cardVals)
    {
        vector<double> cards(cardVals.size());
        vector<char> ops(cardVals.size() - 1);
        vector<string> equations;
        int ind = 0;
        int expectedResult = 24;
        return generateEquations(cardVals, cards, ops, ind, expectedResult);
    }
};

int main()
{
    int n = 4;
    vector<int> cardVals(n);
    for (int i = 0; i < n; i++)
    {
        cin >> cardVals[i];
    }
    Solution sol;
    ofstream out("Renaissance-ProgrammingPathshala/M2/Backtracking/24Game_debug.txt");
    streambuf *coutbuf = cout.rdbuf(); // save old buf
    cout.rdbuf(out.rdbuf());           // redirect std::cout to out.txt!
    bool res = sol.judgePoint24(cardVals);
    cout.rdbuf(coutbuf);
    cout << "\nSolution: " << res << "\n";
    return 0;
}

/*
Renaissance-ProgrammingPathshala/M2/Backtracking/24Game.cpp
8 1 6 6

Renaissance-ProgrammingPathshala/M2/Backtracking/24Game.cpp
1 2 3 4

Renaissance-ProgrammingPathshala/M2/Backtracking/24Game.cpp
3 3 8 8
*/