#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    bool solve(vector<int>& nums, int n, int idx)
    {
        //base case
        if(idx == n-1)
            return true;

        if(idx >= n-1)
            return false; 

        for(int i = 1; i <= nums[idx]; i++)
        {
            if(solve(nums, n, idx+i) == true)
                return true;
        }

        return false;
    }

    bool solveMem(vector<int>& nums, int n, int idx, vector<int>& dp)
    {
        //base case
        if(idx == n-1)
            return true;

        if(dp[idx] != -1)
            return dp[idx];

        if(idx >= n-1)
            return false; 

        for(int i = 1; i <= nums[idx]; i++)
        {
            if(solveMem(nums, n, idx+i, dp) == true)
                return true;
        }

        return dp[idx] = false;
    }

    bool solveTab(vector<int>& nums, int n)
    {
        vector<int> dp(n+1, 0);
        dp[n-1] = true;

        for(int idx = n-2; idx >= 0; idx--)
        {
            dp[idx] = false;
            for(int i = 1; i <= nums[idx] && idx+1 < n; i++)
            {
                if(dp[idx+i])
                {
                    dp[idx] = true;
                    break;
                }
            }
        }

        return dp[0];
    }

    bool solveTabSO(vector<int>& nums, int n)
    {
        int lastIndex = n-1;

        for(int idx = n-2; idx >= 0; idx--)
        {
            if(idx + nums[idx] >= lastIndex)
            {
                lastIndex = idx;
            }
        }

        return lastIndex == 0;
    }

    bool canJump(vector<int>& nums) {
        int n = nums.size();

        // return solve(nums, n, 0);

        vector<int> dp(n+1, -1);
        // return solveMem(nums, n, 0, dp);

        // return solveTab(nums, n);

        return solveTabSO(nums, n);
    }
};

int main()
{
    vector<vector<int>> testCases = {
        {2, 3, 1, 1, 4},   // expected true
        {3, 2, 1, 0, 4},   // expected false
        {0},               // expected true (already at last index)
        {2, 0, 0},         // expected true
        {1, 0, 1, 0},      // expected false
        {5, 0, 0, 0, 0, 0} // expected true
    };

    Solution sol;

    for(auto& nums : testCases)
    {
        cout << "[";
        for(int i = 0; i < (int)nums.size(); i++)
            cout << nums[i] << (i + 1 < (int)nums.size() ? "," : "");
        cout << "] -> ";

        bool result = sol.canJump(nums);
        cout << (result ? "true" : "false") << endl;
    }

    return 0;
}