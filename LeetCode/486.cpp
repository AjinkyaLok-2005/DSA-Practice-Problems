#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

class Solution {
public:
    // APPROACH - 1

    int solve1(int i, int j, vector<int>& nums)
    {
        //base case
        if(i > j)
            return 0;

        if(i == j)
        {
            return nums[i];
        }

        int take_i = nums[i] + min(solve1(i+2, j, nums), solve1(i+1, j-1, nums));

        int take_j = nums[j] + min(solve1(i+1, j-1, nums), solve1(i, j-2, nums));

        return max(take_i, take_j);
    }

    // APPROACH - 2

    int solve2(vector<int>& nums, int i, int j)
    {
        //base case
        if(i > j)
            return 0;

        if(i == j)
            return nums[i];

        int take_i = nums[i] - solve2(nums, i+1, j);

        int take_j = nums[j] - solve2(nums, i, j-1);

        return max(take_i, take_j);
    }

    int solve2Mem(vector<int>& nums, int i, int j, vector<vector<int>>& dp)
    {
        //base case
        if(i > j)
            return 0;

        if(i == j)
            return nums[i];

        if(dp[i][j] != -1)
        {
            return dp[i][j];
        }

        int take_i = nums[i] - solve2Mem(nums, i+1, j, dp);

        int take_j = nums[j] - solve2Mem(nums, i, j-1, dp);

        return dp[i][j] = max(take_i, take_j);
    }

    int solve2Tab(vector<int>& nums)
    {
        int n = nums.size();

        vector<vector<int>> dp(n+1, vector<int>(n+1, 0));

        for(int i = n-1; i >= 0; i--)
        {
            dp[i][i] = nums[i];

            for(int j = i+1; j < n; j++)
            {
                int take_i = nums[i] - dp[i+1][j];

                int take_j = nums[j] - dp[i][j-1];

                dp[i][j] = max(take_i, take_j);
            }
        }

        return dp[0][n-1];
    }

    int solve2TabSO(vector<int>& nums)
    {
        int n = nums.size();

        vector<int> dp(n, 0);

        for(int i = n-1; i >= 0; i--)
        {
            dp[i] = nums[i];

            for(int j = i+1; j < n; j++)
            {
                int take_i = nums[i] - dp[j];

                int take_j = nums[j] - dp[j-1];

                dp[j] = max(take_i, take_j);
            }
        }

        return dp[n-1];
    }

    bool predictTheWinner(vector<int>& nums) {
        int n = nums.size();

        // int total_score = accumulate(begin(nums), end(nums), 0);
        // int p1 = solve(0, n-1, nums);
        // int p2 = total_score - p1;
        // return p1 >= p2;


        // return solve2(nums, 0, n-1) >= 0;
        vector<vector<int>> dp(n+1, vector<int>(n+1, -1));
        // return solve2Mem(nums, 0, n-1, dp) >= 0;

        // return solve2Tab(nums) >= 0;

        return solve2TabSO(nums) >= 0;
    }
}; 

int main() {
    Solution obj;

    vector<int> nums = {1, 5, 2};

    bool ans = obj.predictTheWinner(nums);

    if (ans)
        cout << "Player 1 can win (or tie)." << endl;
    else
        cout << "Player 1 cannot win." << endl;

    return 0;
}