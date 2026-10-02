#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<string> result;

    void solve(string& curr, int n, int open, int close)
    {
        // Base case
        if(curr.length() == 2 * n)
        {
            result.push_back(curr);
            return;
        }

        // Add opening bracket
        if(open < n)
        {
            curr.push_back('(');
            solve(curr, n, open + 1, close);
            curr.pop_back();
        }

        // Add closing bracket
        if(close < open)
        {
            curr.push_back(')');
            solve(curr, n, open, close + 1);
            curr.pop_back();
        }
    }

    vector<string> generateParenthesis(int n)
    {
        string curr = "";

        int open = 0;
        int close = 0;

        solve(curr, n, open, close);

        return result;
    }
};

int main()
{
    int n;
    cin >> n;

    Solution sol;

    vector<string> result = sol.generateParenthesis(n);

    for(string str : result)
    {
        cout << str << endl;
    }

    return 0;
}