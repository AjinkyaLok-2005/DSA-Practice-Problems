#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int n = nums.size();

        int count = 0;
        int ans = 0;

        for(int i = 0; i < n; i++)
        {
            if(nums[i] == 1)
            {
                count += 1;
            }
            else
            {
                count = 0;
            }

            ans = max(ans, count);
        }

        return ans;
    }
};

int main()
{
    vector<int> nums = {1, 1, 0, 1, 1, 1};

    Solution obj;

    cout << obj.findMaxConsecutiveOnes(nums) << endl;

    return 0;
}