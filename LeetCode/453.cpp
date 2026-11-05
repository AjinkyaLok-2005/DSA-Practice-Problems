#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minMoves(vector<int>& nums) {
        int n = nums.size();

        long long sum = 0;
        int min_el = INT_MAX;

        for(int i = 0; i < n; i++)
        {
            sum += nums[i];
            min_el = min(min_el, nums[i]);
        }

        return sum - (long long)n * min_el;
    }
};

int main() {
    vector<int> nums = {1, 2, 3};

    Solution obj;

    int result = obj.minMoves(nums);

    cout << "Minimum Moves: " << result << endl;

    return 0;
}