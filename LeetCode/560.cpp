#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        int count = 0;

        unordered_map<int, int> freq;
        int sum = 0;
        freq[0] = 1;

        for(int i = 0; i < n; i++)
        {
            sum += nums[i];

            if(freq.find(sum - k) != freq.end())
            {
                count += freq[sum - k];
            }

            freq[sum]++;
        }

        return count;
    }
};

int main() {
    Solution sol;

    vector<int> nums = {1, 1, 1};
    int k = 2;

    int result = sol.subarraySum(nums, k);

    cout << "Number of subarrays: " << result << endl;

    return 0;
}