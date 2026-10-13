
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int MOD = 1e9 + 7;

    int maxSum(vector<int>& nums, int k) {
        vector<int> count(32, 0);

        for (int &num : nums) {
            for (int b = 0; b < 32; b++) {
                if (num & (1 << b)) {
                    count[b]++;
                }
            }
        }

        long long result = 0;

        while (k--) {
            long long curr = 0;

            for (int b = 0; b < 32; b++) {
                if (count[b] > 0) {
                    count[b]--;
                    curr = (curr | (1LL << b));
                }
            }

            result = (result + curr * curr) % MOD;
        }

        return result;
    }
};

int main() {
    Solution sol;

    int n, k;
    cout << "Enter size of array and k: ";
    cin >> n >> k;

    vector<int> nums(n);
    cout << "Enter array elements: ";

    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    cout << "Maximum sum: " << sol.maxSum(nums, k) << endl;

    return 0;
}
