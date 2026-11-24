#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxLength(vector<int>& nums) {
        int n = nums.size();

        int length = 0;

        for(int i = 0; i < n; i++)
        {
            int prd = 1;
            int lcmResult = 1;
            int gcdResult = 0;

            for(int j = i; j < n; j++)
            {
                prd *= nums[j];
                if(prd > 1e7) break;
                lcmResult = lcm(lcmResult, nums[j]);
                gcdResult = gcd(gcdResult, nums[j]);

                if(prd == (long long)lcmResult * gcdResult)
                {
                    length = max(length, j-i+1);
                }
            }
        }

        return length;
    }
};

int main()
{
    int n;
    cin >> n;

    vector<int> nums(n);
    for(int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }

    Solution obj;
    cout << obj.maxLength(nums) << endl;

    return 0;
}