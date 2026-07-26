#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        int n = nums.size();

        int m1 = INT_MIN, m2 = INT_MIN, m3 = INT_MIN;
        int s1 = INT_MAX, s2 = INT_MAX;

        for(int i = 0; i < n; i++)
        {
            // 3 maximum numbers
            if(nums[i] >= m1)
            {
                m3 = m2;
                m2 = m1;
                m1 = nums[i];
            }
            else if(nums[i] > m2)
            {
                m3 = m2;
                m2 = nums[i];
            }
            else if(nums[i] > m3)
            {
                m3 = nums[i];
            }

            // 2 minimum numbers
            if(nums[i] <= s1)
            {
                s2 = s1;
                s1 = nums[i];
            }
            else if(nums[i] < s2)
            {
                s2 = nums[i];
            }
        }

        return max(m1 * m2 * m3, m1 * s1 * s2);
    }
};

int main()
{
    Solution sol;

    vector<vector<int>> testCases = {
        {1, 2, 3},
        {1, 2, 3, 4},
        {-1, -2, -3},
        {-4, -3, -2, -1, 60},
        {-100, -98, -1, 2, 3, 4},
        {0, 0, 0},
        {1000, 1000, 1000}
    };

    for(auto& nums : testCases)
    {
        cout << "Input: [";
        for(int i = 0; i < (int)nums.size(); i++)
        {
            cout << nums[i];
            if(i != (int)nums.size() - 1) cout << ", ";
        }
        cout << "] -> Max Product: " << sol.maximumProduct(nums) << endl;
    }

    return 0;
}