#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int getDigitSum(int num) {
        int sum = 0;

        while (num > 0) {
            sum += (num % 10);
            num /= 10;
        }

        return sum;
    }

    int minSwaps(vector<int>& nums) {
        int n = nums.size();

        vector<int> afterSorted(nums);

        auto lambda = [&](int num1, int num2) {
            int dSum1 = getDigitSum(num1);
            int dSum2 = getDigitSum(num2);

            if (dSum1 != dSum2) {
                return dSum1 < dSum2;
            }

            return num1 < num2;
        };

        sort(begin(afterSorted), end(afterSorted), lambda);

        unordered_map<int, int> valToIdx;

        for (int i = 0; i < n; i++) {
            valToIdx[nums[i]] = i;
        }

        int swapCount = 0;

        for (int i = 0; i < n; i++) {
            int expectedVal = afterSorted[i];
            int currVal = nums[i];

            if (expectedVal == currVal)
                continue;

            int idx = valToIdx[expectedVal];

            nums[i] = expectedVal;
            nums[idx] = currVal;

            valToIdx[expectedVal] = i;
            valToIdx[currVal] = idx;

            swapCount++;
        }

        return swapCount;
    }
};

int main() {
    Solution sol;

    int n;
    cout << "Enter the size of the array: ";
    cin >> n;

    vector<int> nums(n);

    cout << "Enter the array elements: ";
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    int result = sol.minSwaps(nums);

    cout << "Minimum swaps required: " << result << endl;

    return 0;
}