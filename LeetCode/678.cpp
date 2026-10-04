#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    // ---------------------------------------------------------
    // APPROACH 1: RECURSION
    // ---------------------------------------------------------
    bool solve(int i, int open, string& s, int n)
    {
        // Base case
        if(i == n)
        {
            return open == 0;
        }

        bool isValid = false;

        if(s[i] == '(')
        {
            isValid |= solve(i + 1, open + 1, s, n);
        }
        else if(s[i] == '*')
        {
            // '*' as '('
            isValid |= solve(i + 1, open + 1, s, n);

            // '*' as empty
            isValid |= solve(i + 1, open, s, n);

            // '*' as ')'
            if(open > 0)
            {
                isValid |= solve(i + 1, open - 1, s, n);
            }
        }
        else
        {
            // s[i] == ')'
            if(open > 0)
            {
                isValid |= solve(i + 1, open - 1, s, n);
            }
        }

        return isValid;
    }


    // ---------------------------------------------------------
    // APPROACH 2: MEMOIZATION
    // ---------------------------------------------------------
    bool solveMem(int i, int open, string& s, int n,
                  vector<vector<int>>& dp)
    {
        // Base case
        if(i == n)
        {
            return open == 0;
        }

        // Already calculated
        if(dp[i][open] != -1)
        {
            return dp[i][open];
        }

        bool isValid = false;

        if(s[i] == '(')
        {
            isValid |= solveMem(i + 1, open + 1, s, n, dp);
        }
        else if(s[i] == '*')
        {
            // '*' as '('
            isValid |= solveMem(i + 1, open + 1, s, n, dp);

            // '*' as empty
            isValid |= solveMem(i + 1, open, s, n, dp);

            // '*' as ')'
            if(open > 0)
            {
                isValid |= solveMem(i + 1, open - 1, s, n, dp);
            }
        }
        else
        {
            // s[i] == ')'
            if(open > 0)
            {
                isValid |= solveMem(i + 1, open - 1, s, n, dp);
            }
        }

        return dp[i][open] = isValid;
    }


    // ---------------------------------------------------------
    // APPROACH 3: TABULATION
    // ---------------------------------------------------------
    bool solveTab(string& s, int n)
    {
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

        // Base case
        // When we reach the end, string is valid only if
        // there are no unmatched opening brackets.
        dp[n][0] = 1;

        for(int i = n - 1; i >= 0; i--)
        {
            for(int open = n - 1; open >= 0; open--)
            {
                bool isValid = false;

                if(s[i] == '(')
                {
                    isValid |= dp[i + 1][open + 1];
                }
                else if(s[i] == '*')
                {
                    // '*' as '('
                    isValid |= dp[i + 1][open + 1];

                    // '*' as empty
                    isValid |= dp[i + 1][open];

                    // '*' as ')'
                    if(open > 0)
                    {
                        isValid |= dp[i + 1][open - 1];
                    }
                }
                else
                {
                    // s[i] == ')'
                    if(open > 0)
                    {
                        isValid |= dp[i + 1][open - 1];
                    }
                }

                dp[i][open] = isValid;
            }
        }

        return dp[0][0];
    }


    // ---------------------------------------------------------
    // MAIN FUNCTION
    // ---------------------------------------------------------
    bool checkValidString(string s)
    {
        int n = s.length();

        // Approach 1: Recursion
        // return solve(0, 0, s, n);

        // Approach 2: Memoization
        // vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
        // return solveMem(0, 0, s, n, dp);

        // Approach 3: Tabulation
        return solveTab(s, n);
    }
};


int main()
{
    Solution obj;

    string s;

    cout << "Enter parentheses string: ";
    cin >> s;

    if(obj.checkValidString(s))
    {
        cout << "Valid String" << endl;
    }
    else
    {
        cout << "Invalid String" << endl;
    }

    return 0;
}