#include <iostream>
#include <vector>
#include <unordered_map>
#include <climits>
#include <algorithm>

using namespace std;

class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n = nums.size();

        unordered_map<int, int> mp;
        int sum = 0;

        mp[0] = -1;

        // Store prefix sum and its index
        for (int i = 0; i < n; i++) {
            sum += nums[i];
            mp[sum] = i;
        }

        // If total sum is less than x, impossible
        if (sum < x)
            return -1;

        // We need to find the longest subarray
        // whose sum is totalSum - x
        int remainingSum = sum - x;
        int longestSubArray = INT_MIN;

        sum = 0;

        for (int i = 0; i < n; i++) {
            sum += nums[i];

            int findSum = sum - remainingSum;

            if (mp.find(findSum) != mp.end()) {
                int idx = mp[findSum];

                longestSubArray = max(longestSubArray, i - idx);
            }
        }

        return longestSubArray == INT_MIN
                   ? -1
                   : (n - longestSubArray);
    }
};

int main() {
    Solution sol;

    vector<int> nums = {1, 1, 4, 2, 3};
    int x = 5;

    int result = sol.minOperations(nums, x);

    cout << "Minimum operations: " << result << endl;

    return 0;
}