#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<long long> resultArray(vector<int>& nums, int k) {
        int n = nums.size();

        vector<long long> result(k, 0);
        vector<long long> prevCount(k, 0);

        for (int i = 0; i < n; i++)
        {
            vector<long long> currCount(k, 0);

            // Subarray containing only nums[i]
            int currElementRemainder = nums[i] % k;
            currCount[currElementRemainder]++;

            // Extend all subarrays ending at i-1
            for (int oldRem = 0; oldRem <= k - 1; oldRem++)
            {
                int newRem = ((long long)oldRem * nums[i] % k) % k;

                currCount[newRem] += prevCount[oldRem];
            }

            // currCount becomes prevCount for the next iteration
            prevCount = move(currCount);

            // Add all subarrays ending at i to the final result
            for (int x = 0; x <= k - 1; x++)
            {
                result[x] += prevCount[x];
            }
        }

        return result;
    }
};

int main()
{
    vector<int> nums = {1, 2, 3, 4, 5};
    int k = 3;

    Solution obj;

    vector<long long> result = obj.resultArray(nums, k);

    cout << "Result: [";

    for (int i = 0; i < result.size(); i++)
    {
        cout << result[i];

        if (i != result.size() - 1)
        {
            cout << ", ";
        }
    }

    cout << "]" << endl;

    return 0;
}