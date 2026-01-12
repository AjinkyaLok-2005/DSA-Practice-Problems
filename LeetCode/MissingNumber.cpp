#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        // int n = nums.size();
        // int expected = n*(n+1)/2;

        // int curr = 0;

        // for(int i = 0; i < n; i++)
        // {
        //     curr += nums[i];
        // }

        // return expected - curr;


        //2nd Approach - XOR

        int x1 = 0;
        int x2 = 0;
        int n = nums.size();
        
        for(int i = 0; i < n; i++)
        {
            x1 = x1 ^ nums[i];
        }

        for(int j = 0; j <= n; j++)
        {
            x2 = x2 ^ j;
        }

        return x1 ^ x2;
    }
};

int main() {
    Solution sol;

    int n;
    cin >> n;              // size of array (n numbers, from 0 to n with one missing)

    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    int ans = sol.missingNumber(nums);
    cout << ans << endl;

    return 0;
}
