#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        
        int n = nums.size();
        int left = 0;
        int sum = 0;

        int minLen = INT_MAX;

        for(int right = 0; right < n; right++)
        {
            sum += nums[right];

            while(sum >= target)
            {
                minLen = min(minLen, right - left + 1);

                sum -= nums[left];
                left++;
            }
        }

        return minLen == INT_MAX ? 0 : minLen;
    }
};

int main() {

    Solution obj;

    int target = 7;
    vector<int> nums = {2, 3, 1, 2, 4, 3};

    int result = obj.minSubArrayLen(target, nums);

    cout << "Minimum subarray length: " << result << endl;

    return 0;
}