#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int n;

    int solve(vector<int> &nums, int i)
    {
        // Base case
        if(i >= n)
            return 0;

        int take = nums[i] + solve(nums, i + 2);
        int skip = solve(nums, i + 1);

        return max(take, skip);
    }

    int solveMem(vector<int>& nums, int i, vector<int>& dp)
    {
        // Base case
        if(i >= n)
            return 0;

        if(dp[i] != -1)
            return dp[i];

        int take = nums[i] + solveMem(nums, i + 2, dp);
        int skip = solveMem(nums, i + 1, dp);

        return dp[i] = max(take, skip);
    }

    int solveTab(vector<int>& nums)
    {
        vector<int> dp(n + 2, 0);

        for(int i = n - 1; i >= 0; i--)
        {
            int take = nums[i] + dp[i + 2];
            int skip = dp[i + 1];

            dp[i] = max(take, skip);
        }

        return dp[0];
    }

    int solveTabSO(vector<int>& nums)
    {
        int m = nums.size();

        int curr = 0;
        int next1 = 0;
        int next2 = 0;

        for(int i = m - 1; i >= 0; i--)
        {
            int take = nums[i] + next2;
            int skip = next1;

            curr = max(take, skip);

            next2 = next1;
            next1 = curr;
        }

        return curr;
    }

    int rob(vector<int>& nums)
    {
        n = nums.size();

        if(n == 1)
            return nums[0];

        vector<int> first, second;

        for(int i = 0; i < n; i++)
        {
            if(i != 0)
                first.push_back(nums[i]);

            if(i != n - 1)
                second.push_back(nums[i]);
        }

        return max(solveTabSO(first), solveTabSO(second));
    }
};

int main()
{
    int n;

    cout << "Enter number of houses: ";
    cin >> n;

    vector<int> nums(n);

    cout << "Enter money in each house: ";
    for(int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }

    Solution obj;
    int ans = obj.rob(nums);

    cout << "Maximum money that can be robbed: " << ans << endl;

    return 0;
}