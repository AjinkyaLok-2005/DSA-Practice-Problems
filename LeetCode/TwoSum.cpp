#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

vector<int> twoSum(vector<int>& nums, int target) 
{
    unordered_map<int, int> m;

    for(int i = 0; i < nums.size(); i++)
    {
        int second = target - nums[i];
        if(m.find(second) != m.end())
        {
            return {m[second], i};
        }
        m[nums[i]] = i;
    }
    return {};
}

int main()
{   
    vector<int> nums = {2, 7, 11, 15};
    int target = 9;

    vector<int> ans = twoSum(nums, target);

    cout << "The indices of the two numbers are: ";
    for(int index : ans) {
        cout << index << " ";
    }
    cout << endl;

    return 0;
}