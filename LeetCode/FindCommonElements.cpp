#include<iostream>
#include<unordered_set>
#include<vector>
using namespace std;

vector<int> findIntersectionValues(vector<int>& nums1, vector<int>& nums2) 
{
    unordered_set<int> s1(nums1.begin(), nums1.end());
    unordered_set<int> s2(nums2.begin(), nums2.end());

    int count1 = 0;
    
    for(int num : nums1)
    {
        if(s2.count(num))
        {
            count1++;
        }
    }

    int count2 = 0;
    
    for(int num : nums2)
    {
        if(s1.count(num))
        {
            count2++;
        }
    }
    
    return {count1, count2};
}

int main()
{
    vector<int> nums1 = {1, 2, 3, 4, 5};
    vector<int> nums2 = {2, 4, 6, 8};

    vector<int> ans = findIntersectionValues(nums1, nums2);

    cout << "Count1: " << ans[0] << endl;
    cout << "Count2: " << ans[1] << endl;

    return 0;
}
