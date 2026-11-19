#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimizeSum(vector<int>& nums) {
        int n = nums.size();

        sort(nums.begin(), nums.end());

        return min({
            nums[n-3] - nums[0],
            nums[n-1] - nums[2],
            nums[n-2] - nums[1]
        });
    }
};

int main() {
    Solution obj;

    vector<int> nums = {1, 4, 7, 8, 5};

    int result = obj.minimizeSum(nums);

    cout << "Minimum possible difference: " << result << endl;

    return 0;
}