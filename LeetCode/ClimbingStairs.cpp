#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int solve(int n)
    {
        if(n == 0)
            return 1;

        if(n == 1)
            return 1;

        int ways = solve(n-1) + solve(n-2);

        return ways;
    }

    int solveMem(int n, vector<int>& dp)
    {
        if(n == 0)
            return 1;

        if(n == 1)
            return 1;

        if(dp[n] != -1)
            return dp[n];

        dp[n] = solveMem(n-1, dp) + solveMem(n-2, dp);

        return dp[n];
    }

    int climbStairs(int n) {
        vector<int> dp(n+1, -1);
        return solveMem(n, dp);
    }
    
};



int main()
{
    Solution s;
    int n = 5;
    cout << s.climbStairs(n) << endl;
    return 0;
}