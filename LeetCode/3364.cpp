#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumSumSubarray(vector<int>& nums, int l, int r) {
        int n = nums.size();

        vector<int> prefSum(n+1, 0);

        for(int i = 1; i < n+1; i++)
        {
            prefSum[i] = prefSum[i-1] + nums[i-1];
        }

        int k = l;
        int mini = INT_MAX;

        while(k <= r)
        {
            for(int i = k; i < n+1; i++)
            {
                int currSum = prefSum[i] - prefSum[i-k];
                if(currSum > 0)
                    mini = min(mini, currSum);
            }
            k++;
        }

        return mini == INT_MAX ? -1 : mini;
    }
};

int main()
{
    int n, l, r;
    cin >> n >> l >> r;

    vector<int> nums(n);
    for(int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }

    Solution obj;
    cout << obj.minimumSumSubarray(nums, l, r) << endl;

    return 0;
}