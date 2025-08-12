#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

int majorityElement(vector<int>& nums) 
{
    unordered_map<int, int> mp;
    for(int i = 0; i < nums.size(); i++)
    {
        mp[nums[i]]++;
    }
    int majority = 0;
    int occ = 0;
    unordered_map<int, int> :: iterator it;
    for(it = mp.begin(); it != mp.end(); it++)
    {
        if(it -> second >= occ)
        {
            majority = it -> first;
            occ = it -> second;
        }
    }
    return majority;
}

int main()
{
    vector<int> nums = {2, 2, 1, 1, 1, 2, 2};

    int ans = majorityElement(nums);

    cout << "Majority Element occuring is: " << ans;

    return 0;
}