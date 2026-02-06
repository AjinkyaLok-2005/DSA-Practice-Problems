#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    int minRemoval(vector<int>& nums, int k) {
        int n = nums.size();

        sort(begin(nums), end(nums));

        int L = 1;
        int maxEl = nums[0];
        int minEl = nums[0];
        int i = 0;
        int j = 0;

        while(j < n)
        {
            minEl = nums[i];
            maxEl = nums[j];

            while(i < j && maxEl > (long long)k*minEl)
            {
                i++;
                minEl = nums[i];
            }

            L = max(L, j-i+1);
            j++;
        }

        return n-L;
    }
};

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    Solution sol;
    cout << sol.minRemoval(nums, k) << endl;

    return 0;
}
