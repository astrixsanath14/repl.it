#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);



/*
 * Complete the 'findMaxProducts' function below.
 *
 * The function is expected to return a LONG_INTEGER.
 * The function accepts INTEGER_ARRAY products as parameter.
 */

map<tuple<int,long long, long long>,long long> dp;

void findMaxProducts(vector<int> products, long long &maxCount, long long currSum, int ind, long long prev) {
    // cout<<"ind:: "<<ind<<" currSum:: " << currSum<<" maxCount:: " <<maxCount<<"\n";
    if(ind < 0)
    {
        maxCount = max(maxCount, currSum);
        return;
    }
    
    if(dp.find({ind,prev,currSum})!=dp.end())
    {
        return;
    }
    
    if(products[ind] < prev)
    {
        findMaxProducts(products, maxCount, currSum + products[ind], ind-1, products[ind]);
    }
    else
    {
        findMaxProducts(products, maxCount, currSum + prev-1, ind-1, prev-1);
        findMaxProducts(products, maxCount, products[ind], ind-1, products[ind]);
    }
    dp[{ind,prev,currSum}] = maxCount;
}

long findMaxProducts(vector<int> products) {
    long long maxCount = -1;
    long long currSum = 0;
    int ind = products.size()-1;
    cout<<ind<<"\n";
    for(int product:products)
    {
        cout<<product<<" ";
    }
    findMaxProducts(products, maxCount, products[ind], ind-1, products[ind]);
    return maxCount;
}

/*
12
34 17 6 32 2 28 37 7 39 18 11 29 6 

Output: 77
Expected: 60

    .   
    .
    .       .
    .       .
    .       .   .
    .   .   .   .
    .   .   .   .
.   .   .   .   .   .
.   .   .   .   .   .

15 = 5 4 3 2 1
16 = 7 4 3 2
*/

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string products_count_temp;
    getline(cin, products_count_temp);

    int products_count = stoi(ltrim(rtrim(products_count_temp)));

    vector<int> products(products_count);

    for (int i = 0; i < products_count; i++) {
        string products_item_temp;
        getline(cin, products_item_temp);

        int products_item = stoi(ltrim(rtrim(products_item_temp)));

        products[i] = products_item;
    }

    long result = findMaxProducts(products);

    fout << result << "\n";

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}
