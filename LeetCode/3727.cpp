
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        int n = nums.size();

        for (int i = 0; i < n; i++) {
            nums[i] = nums[i] * nums[i];
        }

        sort(begin(nums), end(nums));

        long long maxSum = 0;

        int i = 0;
        int j = n - 1;

        while (i <= j) {
            if (i == j) {
                maxSum += nums[j];
                break;
            }

            maxSum += nums[j] - nums[i];
            i++;
            j--;
        }

        return maxSum;
    }
};

int main() {
    Solution sol;

    vector<int> nums = {1, 2, 3};

    cout << sol.maxAlternatingSum(nums) << endl;

    return 0;
}
