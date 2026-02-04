#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int minimumCost(vector<int>& nums) {
        int n = nums.size();
        int ans = INT_MAX;

        for(int i = 1; i <= n-2; i++)
        {
            for(int j = i+1; j <= n-1; j++)
            {
                int cost = nums[0] + nums[i] + nums[j];
                ans = min(ans, cost);
            }
        }

        return ans;
    }
};

int main() {
    int n;
    cin >> n;

    vector<int> nums(n);
    for(int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    Solution sol;
    cout << sol.minimumCost(nums) << endl;

    return 0;
}