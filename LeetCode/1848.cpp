#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int getMinDistance(vector<int>& nums, int target, int start) {
        int n = nums.size();
        int mini = INT_MAX;
        int val = 0;

        for(int i = 0; i < n; i++)
        {
            if(nums[i] == target)
            {
                val = abs(i - start);
                mini = min(mini, val);
            }
        }

        return mini;
    }
};

int main() {
    Solution obj;

    // Example input
    vector<int> nums = {1, 2, 3, 4, 5, 3};
    int target = 3;
    int start = 2;

    int result = obj.getMinDistance(nums, target, start);

    cout << "Minimum Distance: " << result << endl;

    return 0;
}