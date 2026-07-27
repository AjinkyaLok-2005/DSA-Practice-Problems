#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();

        int m1 = INT_MIN;
        int m2 = INT_MIN;

        for(int i = 0; i < n; i++)
        {
            if(nums[i] >= m1)
            {
                m2 = m1;
                m1 = nums[i];
            }
            else if(nums[i] >= m2)
            {
                m2 = nums[i];
            }
        }

        return (m1 - 1) * (m2 - 1);
    }
};

int main() {
    int n;

    cout << "Enter the number of elements: ";
    cin >> n;

    vector<int> nums(n);

    cout << "Enter the elements: ";
    for(int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    Solution obj;
    int ans = obj.maxProduct(nums);

    cout << "Maximum Product = " << ans << endl;

    return 0;
}