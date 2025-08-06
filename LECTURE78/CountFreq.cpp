#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;

int maxFrequencyElements(vector<int>& nums) {
    unordered_map<int, int> count;
    int maxFreq = 0;
    int totalFreq = 0;
    for(int i = 0; i < nums.size(); i++)
    {
        count[nums[i]]++;
        maxFreq = max(maxFreq, count[nums[i]]);
    }    
    unordered_map<int, int> :: iterator it;
    for(it = count.begin(); it != count.end(); it++)
    {
        if(maxFreq == it -> second)
        {
            totalFreq += it -> second;
        }
    }  
    return totalFreq;
}

int main()
{
    vector<int> nums = {1, 2, 2, 3, 1, 4};

    int ans = maxFrequencyElements(nums);

    cout << "Elements with Maximum Frequency is: " << ans << endl;

    //IMP Condition
    // Return the total frequencies of elements in nums such that those elements all have the maximum frequency.

    return 0;
}