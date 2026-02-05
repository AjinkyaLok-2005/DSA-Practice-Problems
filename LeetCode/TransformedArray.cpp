#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<int> constructTransformedArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> result(n);

        for(int i = 0; i < n; i++)
        {
            int newIndex = ((i + nums[i]) % n + n) % n;
            result[i] = nums[newIndex];
        }

        return result;
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
    vector<int> transformedArray = sol.constructTransformedArray(nums);

    for(int i = 0; i < transformedArray.size(); i++) {
        cout << transformedArray[i] << " ";
    }
    cout << endl;

    return 0;
}