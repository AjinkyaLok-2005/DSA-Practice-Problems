#include<iostream>
#include<vector>
#include<climits>
#include<algorithm>
using namespace std;

class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        int n = nums.size();

        int maxi = INT_MIN;
        int mini = INT_MAX;

        for(int i = 0; i < n; i++)
        {
            maxi = max(maxi, nums[i]);
            mini = min(mini, nums[i]);
        }

        return 1LL * k * (maxi - mini);
    }
};

int main() {
    int n, k;

    cout << "Enter size of array: ";
    cin >> n;

    vector<int> nums(n);

    cout << "Enter array elements: ";
    for(int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    cout << "Enter k: ";
    cin >> k;

    Solution obj;
    long long result = obj.maxTotalValue(nums, k);

    cout << "Maximum Total Value = " << result << endl;

    return 0;
}