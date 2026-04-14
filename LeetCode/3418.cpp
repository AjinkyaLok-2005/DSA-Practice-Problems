#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int m;
    int n;

    // int solve(vector<vector<int>>& coins, int i, int j, int neu)
    // {
    //     //base case
    //     if(i >= m || j >= n)
    //         return INT_MIN;

    //     if(i == m-1 && j == n-1)
    //     {
    //         if(coins[i][j] < 0 && neu > 0)
    //             return 0; //neutralised

    //         return coins[i][j];
    //     }

    //     //Take
    //     int take = INT_MIN;
    //     int takeDown = solve(coins, i+1, j, neu);
    //     int takeRight = solve(coins, i, j+1, neu);

    //     int maxi = max(takeDown, takeRight);

    //     if(maxi != INT_MIN)
    //         take = coins[i][j] + maxi;

    //     //Skip
    //     int skip = INT_MIN;
    //     if(coins[i][j] < 0 && neu > 0)
    //     {
    //         int skipDown = solve(coins, i+1, j, neu-1);
    //         int skipRight = solve(coins, i, j+1, neu-1);

    //         skip = max(skipDown, skipRight);
    //     }


    //     return max(take, skip);
    // }

    int solveMem(vector<vector<int>>& coins, int i, int j, int neu, vector<vector<vector<int>>>& dp)
    {
        //base case
        if(i >= m || j >= n)
            return INT_MIN;

        if(i == m-1 && j == n-1)
        {
            if(coins[i][j] < 0 && neu > 0)
                return 0; //neutralised

            return coins[i][j];
        }

        if(dp[i][j][neu] != INT_MIN)
            return dp[i][j][neu];

        //Take
        int take = INT_MIN;
        int takeDown = solveMem(coins, i+1, j, neu, dp);
        int takeRight = solveMem(coins, i, j+1, neu, dp);

        int maxi = max(takeDown, takeRight);

        if(maxi != INT_MIN)
            take = coins[i][j] + maxi;

        //Skip
        int skip = INT_MIN;
        if(coins[i][j] < 0 && neu > 0)
        {
            int skipDown = solveMem(coins, i+1, j, neu-1, dp);
            int skipRight = solveMem(coins, i, j+1, neu-1, dp);

            skip = max(skipDown, skipRight);
        }

        return dp[i][j][neu] = max(take, skip);
    }

    int maximumAmount(vector<vector<int>>& coins) {
        m = coins.size();
        n = coins[0].size();

        // return solve(coins, 0, 0, 2);

        vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(3, INT_MIN)));

        return solveMem(coins, 0, 0, 2, dp);
    }
};

int main()
{
    Solution obj;

    int m, n;
    cout << "Enter rows and columns: ";
    cin >> m >> n;

    vector<vector<int>> coins(m, vector<int>(n));

    cout << "Enter the grid values:\n";
    for(int i = 0; i < m; i++)
    {
        for(int j = 0; j < n; j++)
        {
            cin >> coins[i][j];
        }
    }

    int result = obj.maximumAmount(coins);

    cout << "Maximum Amount: " << result << endl;

    return 0;
}