#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        int n = nums.size();

        vector<int> ans;

        int count = 0;
        int index = 0;

        for (int i = 0; i < n; i++) {
            if (nums[i] == target) {
                count++;
            }

            if (nums[i] < target) {
                index++;
            }
        }

        for (int i = 0; i < count; i++) {
            ans.push_back(index);
            index++;
        }

        return ans;
    }
};

int main() {
    Solution sol;

    vector<int> nums = {1, 2, 5, 2, 3};
    int target = 2;

    vector<int> ans = sol.targetIndices(nums, target);

    cout << "Target indices: ";
    for (int index : ans) {
        cout << index << " ";
    }
    cout << endl;

    return 0;
}