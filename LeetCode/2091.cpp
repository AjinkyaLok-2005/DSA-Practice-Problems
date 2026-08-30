#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size();

        int minIdx = 0;
        int maxIdx = 0;

        for(int i = 0; i < n; i++)
        {
            if(nums[i] < nums[minIdx])
            {
                minIdx = i;
            }

            if(nums[i] > nums[maxIdx])
            {
                maxIdx = i;
            }
        }

        int left = min(minIdx, maxIdx);
        int right = max(minIdx, maxIdx);

        int bothFront = right + 1;
        int bothBack = n - left;
        int split = (left + 1) + (n - right);

        return min({bothFront, bothBack, split});
    }
};

int main() {
    Solution sol;

    vector<int> nums = {2, 10, 7, 5, 4, 1, 8, 6};

    int result = sol.minimumDeletions(nums);

    cout << "Minimum deletions: " << result << endl;

    return 0;
}