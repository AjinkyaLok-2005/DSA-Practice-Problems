#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int missingInteger(vector<int>& nums) {
        int n = nums.size();
        int seqSum = nums[0];

        for (int j = 1; j < n; j++) {
            if (nums[j] == nums[j - 1] + 1) {
                seqSum += nums[j];
            } else {
                break;
            }
        }

        unordered_set<int> st(begin(nums), end(nums));

        while (true) {
            if (st.find(seqSum) != st.end()) {
                seqSum++;
            } else {
                return seqSum;
            }
        }
    }
};

int main() {
    Solution sol;

    vector<int> nums1 = {1, 2, 3, 2, 5};
    cout << "Test 1: " << sol.missingInteger(nums1) << " (Expected: 6)" << endl;

    vector<int> nums2 = {3, 4, 5, 1, 12, 14, 13};
    cout << "Test 2: " << sol.missingInteger(nums2) << " (Expected: 15)" << endl;

    // Edge case: single element array
    vector<int> nums3 = {5};
    cout << "Test 3: " << sol.missingInteger(nums3) << " (Expected: 6)" << endl;

    // Edge case: no valid sequential prefix beyond first element
    vector<int> nums4 = {50, 1, 2, 3};
    cout << "Test 4: " << sol.missingInteger(nums4) << " (Expected: 1... let's verify)" << endl;

    return 0;
}