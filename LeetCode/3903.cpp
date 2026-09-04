#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();

        vector<int> minFromIndex(n);

        int minEl = INT_MAX;

        // Store minimum element from index i to the end
        for (int i = n - 1; i >= 0; i--) {
            minEl = min(minEl, nums[i]);
            minFromIndex[i] = minEl;
        }

        int maxEl = INT_MIN;

        // Find the first stable index
        for (int i = 0; i < n; i++) {
            maxEl = max(maxEl, nums[i]);

            if (maxEl - minFromIndex[i] <= k)
                return i;
        }

        return -1;
    }
};

int main() {
    Solution sol;

    vector<int> nums = {1, 5, 3, 8, 2, 6};
    int k = 6;

    int result = sol.firstStableIndex(nums, k);

    cout << "First stable index: " << result << endl;

    return 0;
}