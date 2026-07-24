#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int i, int j, int m, int n)
    {
        //base case
        if(i > m-1 || j > n-1)
        {
            return 0;
        }

        if(i == m-1 && j == n-1)
        {
            //reached
            return 1;
        }

        int right = solve(i, j+1, m, n);
        
        int down = solve(i+1, j, m, n);

        return right + down;
    }

    int solveMem(int i, int j, int m, int n, vector<vector<int>>& dp)
    {
        //base case
        if(i > m-1 || j > n-1)
        {
            return 0;
        }

        if(dp[i][j] != -1)
        {
            return dp[i][j];
        }

        if(i == m-1 && j == n-1)
        {
            //reached
            return 1;
        }

        int right = solveMem(i, j+1, m, n, dp);
        
        int down = solveMem(i+1, j, m, n, dp);

        return dp[i][j] = right + down;
    }

    int solveTab(int i, int j, int m, int n)
    {
        vector<vector<int>> dp(m+1, vector<int> (n+1, 0));

        for(int i = m-1; i >= 0; i--)
        {
            for(int j = n-1; j >= 0; j--)
            {
                if(i == m-1 && j == n-1)
                {
                    dp[m-1][n-1] = 1;
                    continue;
                }

                int right = dp[i][j+1];
        
                int down = dp[i+1][j];

                dp[i][j] = right + down;
            }
        }

        return dp[0][0];
    }

    int solveTabSO(int i, int j, int m, int n)
    {
        vector<int> next(n+1, 0);

        for(int i = m-1; i >= 0; i--)
        {
            for(int j = n-1; j >= 0; j--)
            {
                if(i == m-1 && j == n-1)
                {
                    next[j] = 1;
                    continue;
                }

                int right = next[j+1];
        
                int down = next[j];

                next[j] = right + down;
            }
        }

        return next[0];
    }

    int uniquePaths(int m, int n) {
        // return solve(0, 0, m, n);

        vector<vector<int>> dp(m+1, vector<int>(n+1, -1));
        // return solveMem(0, 0, m, n, dp);

        // return solveTab(0, 0, m, n);

        return solveTabSO(0, 0, m, n);
    }
};

int main()
{
    Solution sol;

    // Test case 1
    int m1 = 3, n1 = 7;
    cout << "m=3, n=7 -> " << sol.uniquePaths(m1, n1) << " (expected 28)" << endl;

    // Test case 2
    int m2 = 3, n2 = 2;
    cout << "m=3, n=2 -> " << sol.uniquePaths(m2, n2) << " (expected 3)" << endl;

    // Test case 3 (edge case: single row)
    int m3 = 1, n3 = 5;
    cout << "m=1, n=5 -> " << sol.uniquePaths(m3, n3) << " (expected 1)" << endl;

    // Test case 4 (edge case: single cell)
    int m4 = 1, n4 = 1;
    cout << "m=1, n=1 -> " << sol.uniquePaths(m4, n4) << " (expected 1)" << endl;

    // Test case 5
    int m5 = 3, n5 = 3;
    cout << "m=3, n=3 -> " << sol.uniquePaths(m5, n5) << " (expected 6)" << endl;

    return 0;
}