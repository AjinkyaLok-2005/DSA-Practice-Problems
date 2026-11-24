#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
using namespace std;

class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int n = nums.size();

        sort(nums.begin(), nums.end());

        int median = nums[n/2];

        int count = 0;

        for(int i = 0; i < n; i++)
        {
            count += abs(nums[i] - median);
        }

        return count;
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
    cout << obj.minMoves2(nums) << endl;

    return 0;
}