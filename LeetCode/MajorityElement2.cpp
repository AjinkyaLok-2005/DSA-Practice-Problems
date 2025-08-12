#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

vector<int> majorityElement(vector<int>& nums) 
{
    unordered_map<int, int> mp;
    for(int i = 0; i < nums.size(); i++)
    {
        mp[nums[i]]++;
    }
    vector<int> ans;
    unordered_map<int, int> :: iterator it;
    for(it = mp.begin(); it != mp.end(); it++)
    {
        if(it -> second > nums.size()/3)
        {
            ans.push_back(it -> first);
        }
    }
    return ans;
}

int main()
{
    // vector<int> nums = {3, 2, 3};
    vector<int> nums = {1, 2};

    vector<int> ans = majorityElement(nums);

    cout << "Majority Occuring Elements are: " << endl;

    for(int x : ans)
    {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}