#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int n;

    int findMethod(vector<int>& nums, int start, int target)
    {
        int j = lower_bound(begin(nums) + start, end(nums), target) - begin(nums);

        if(j < n && nums[j] == target)
        {
            return j;
        }

        return -1;
    }

    int solve(int i, int inc, vector<int>& nums)
    {
        int currVal = nums[i] + inc;
        int len = 1;

        int j = findMethod(nums, i+1, currVal + 1);
        if(j != -1)
        {
            len = max(len, 1 + solve(j, 0, nums));
        }

        j = findMethod(nums, i+1, currVal);
        if(j != -1)
        {
            len = max(len, 1 + solve(j, 1, nums));
        }

        return len;
    }

    int solveMem(int i, int inc, vector<int>& nums, vector<vector<int>>& dp)
    {
        if(dp[i][inc] != -1)
            return dp[i][inc];

        int currVal = nums[i] + inc;
        int len = 1;

        int j = findMethod(nums, i+1, currVal + 1);
        if(j != -1)
        {
            len = max(len, 1 + solveMem(j, 0, nums, dp));
        }

        j = findMethod(nums, i+1, currVal);
        if(j != -1)
        {
            len = max(len, 1 + solveMem(j, 1, nums, dp));
        }

        return dp[i][inc] = len;
    }

    int solveTab(vector<int>& nums)
    {
        int result = 1;
        vector<vector<int>> dp(n+1, vector<int>(2, 0));

        for(int i = n-1; i >= 0; i--)
        {
            for(int inc = 0; inc < 2; inc++)
            {
                int currVal = nums[i] + inc;
                int len = 1;

                int j = findMethod(nums, i+1, currVal + 1);
                if(j != -1)
                {
                    len = max(len, 1 + dp[j][0]);
                }

                j = findMethod(nums, i+1, currVal);
                if(j != -1)
                {
                    len = max(len, 1 + dp[j][1]);
                }

                dp[i][inc] = len;
                result = max(result, dp[i][inc]);
            }
        }

        return result;
    }

    int maxSelectedElements(vector<int>& nums) {
        n = nums.size();
        sort(nums.begin(), nums.end());

        // Tabulation (no loop needed, the table covers all i)
        return solveTab(nums);
    }
};

int main()
{
    int n;
    cin >> n;

    vector<int> nums(n);
    for(int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }

    Solution obj;
    cout << obj.maxSelectedElements(nums) << endl;

    return 0;
}