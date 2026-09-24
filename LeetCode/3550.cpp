#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int smallestIndex(vector<int>& nums) {
        for(int i = 0; i < nums.size(); i++)
        {
            int num = nums[i];
            int sum = 0;

            while(num > 0)
            {
                sum += num % 10;
                num /= 10;
            }

            if(sum == i)
                return i;
        }

        return -1;
    }
};

int main()
{
    vector<int> nums = {1, 3, 2};

    Solution obj;

    int result = obj.smallestIndex(nums);

    cout << "Smallest index: " << result << endl;

    return 0;
}