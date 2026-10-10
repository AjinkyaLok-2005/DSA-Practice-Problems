
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
        int n = nums1.size();

        vector<int> countDiff(1e5 + 1, 0);

        for (int i = 0; i < n; i++) {
            int d = abs(nums1[i] - nums2[i]);
            countDiff[d]++;
        }

        int K = k1 + k2;

        for (int currDiff = 1e5; currDiff > 0 && K > 0; currDiff--) {
            int countOps = min(countDiff[currDiff], K);

            countDiff[currDiff] -= countOps;
            countDiff[currDiff - 1] += countOps;
            K -= countOps;
        }

        long long result = 0;

        for (long long d = 1; d <= 1e5; d++) {
            result += 1LL * countDiff[d] * d * d;
        }

        return result;
    }
};

int main() {
    Solution sol;

    vector<int> nums1 = {1, 2, 3, 4};
    vector<int> nums2 = {2, 10, 20, 19};

    int k1 = 0;
    int k2 = 1;

    cout << sol.minSumSquareDiff(nums1, nums2, k1, k2) << endl;

    return 0;
}
