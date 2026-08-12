#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> mp;
        int left = 0;
        int maxLen = 0;

        for (int right = 0; right < n; right++)
        {
            mp[nums[right]]++;  // add current element to window

            // shrink from left while window is invalid
            while (mp[nums[right]] > k)
            {
                mp[nums[left]]--;
                left++;
            }

            // window [left, right] is now valid
            maxLen = max(maxLen, right - left + 1);
        }

        return maxLen;
    }
};

int main()
{
    Solution sol;

    // Test case from our dry run
    vector<int> nums1 = {1, 4, 4, 3};
    int k1 = 1;
    cout << "Test 1: " << sol.maxSubarrayLength(nums1, k1) << " (expected 2)" << endl;

    // Example 1 from problem
    vector<int> nums2 = {1, 2, 3, 1, 2, 3, 1, 2};
    int k2 = 2;
    cout << "Test 2: " << sol.maxSubarrayLength(nums2, k2) << " (expected 6)" << endl;

    // Example 2 from problem
    vector<int> nums3 = {1, 2, 1, 2, 1, 2, 1, 2};
    int k3 = 1;
    cout << "Test 3: " << sol.maxSubarrayLength(nums3, k3) << " (expected 2)" << endl;

    // Example 3 from problem
    vector<int> nums4 = {5, 5, 5, 5, 5, 5, 5};
    int k4 = 4;
    cout << "Test 4: " << sol.maxSubarrayLength(nums4, k4) << " (expected 4)" << endl;

    return 0;
}