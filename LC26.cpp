// Online C++ compiler to run C++ program online
#include <iostream>
#include <vector>
using namespace std;

int removeDuplicates(vector<int>& nums) 
    {
        int insertIndex = 1;

        for(int i = 1; i < nums.size(); i++)
        {
            if(nums[i-1] != nums[i])
            {
                nums[insertIndex] = nums[i];
                insertIndex++;
            }
        }    
        return insertIndex;
    }

int main() {
    // Write C++ code here
    vector<int> nums = {0,0,1,1,1,2,2,3,3,4};
    removeDuplicates(nums);
    
    for(int i = 0; i < nums.size(); i++)
    {
        cout << nums[i] << " ";
    }
    cout << endl;
    return 0;
}