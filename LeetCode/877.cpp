#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int solve(vector<int>& piles, int i, int j)
    {
        //base case
        if(i > j)
            return 0;

        if(i == j)
            return piles[i];

        int take_i = piles[i] - solve(piles, i+1, j);

        int take_j = piles[j] - solve(piles, i, j-1);

        return max(take_i, take_j);
    }

    int solveMem(vector<int>& piles, int i, int j, vector<vector<int>>& dp)
    {
        //base case
        if(i > j)
            return 0;

        if(i == j)
            return piles[i];

        if(dp[i][j] != -1)
            return dp[i][j];

        int take_i = piles[i] - solveMem(piles, i+1, j, dp);

        int take_j = piles[j] - solveMem(piles, i, j-1, dp);

        return dp[i][j] = max(take_i, take_j);
    }

    int solveTab(vector<int>& piles)
    {
        int n = piles.size();

        vector<vector<int>> dp(n+1, vector<int>(n+1, 0));

        for(int i = n-1; i >= 0; i--)
        {
            dp[i][i] = piles[i];

            for(int j = i+1; j < n; j++)
            {
                int take_i = piles[i] - dp[i+1][j];

                int take_j = piles[j] - dp[i][j-1];

                dp[i][j] = max(take_i, take_j);
            }
        }

        return dp[0][n-1];

    }

    int solveTabSO(vector<int>& piles)
    {
        int n = piles.size();

        vector<int> dp(n, 0);

        for(int i = n-1; i >= 0; i--)
        {
            dp[i] = piles[i];

            for(int j = i+1; j < n; j++)
            {
                int take_i = piles[i] - dp[j];

                int take_j = piles[j] - dp[j-1];

                dp[j] = max(take_i, take_j);
            }
        }

        return dp[n-1];

    }

    bool stoneGame(vector<int>& piles) {
        int n = piles.size();

        // return solve(piles, 0, n-1) >= 0;

        vector<vector<int>> dp(n+1, vector<int>(n+1, -1));

        // return solveMem(piles, 0, n-1, dp) >= 0;

        // return solveTab(piles) >= 0;

        return solveTabSO(piles) >= 0;
    }
};

int main() {
    Solution obj;

    int n;
    cout << "Enter number of piles: ";
    cin >> n;

    vector<int> piles(n);

    cout << "Enter the pile values: ";
    for (int i = 0; i < n; i++) {
        cin >> piles[i];
    }

    bool ans = obj.stoneGame(piles);

    if (ans)
        cout << "Alice wins." << endl;
    else
        cout << "Bob wins." << endl;

    return 0;
}