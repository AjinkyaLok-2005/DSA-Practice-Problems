#include<iostream>
#include<vector>
using namespace std;

int removeElement(vector<int> & nums, int val)
{
    int i = 0;
    int j = nums.size() - 1;

    while(i < j)
    {
        if(nums[i] == val)
        {
            if(nums[j] == val)
            {
                j--;
            }
            else
            {
                swap(nums[i], nums[j]);
                i++;
            }
        }
        else
        {
            i++;
        }
    }

    int count = 0;

    for(int k = 0; k < nums.size(); k++)
    {
        if(nums[k] != val)
        {
            count++;
        }
        else
        {
            break;
        }
    }

    return count;
}

int main()
{
    vector<int> nums = {0, 1, 2, 2, 3, 0, 4, 2};
    int val = 2;

    int ans = removeElement(nums, val);
    
    cout << "The number of elements in nums which are not equal to val is: " << ans << endl;

    return 0;
}