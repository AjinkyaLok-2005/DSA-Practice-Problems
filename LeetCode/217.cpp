#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        int n = nums.size();

        bool duplicate = false;
        
        sort(begin(nums), end(nums));

        for(int i = 1; i < n; i++)
        {
            if(nums[i] == nums[i-1])
            {
                duplicate = true;
                break;
            }
        }

        return duplicate;
    }
};

int main() {
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;

    vector<int> nums(n);

    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    Solution obj;
    bool ans = obj.containsDuplicate(nums);

    if (ans)
        cout << "true" << endl;
    else
        cout << "false" << endl;

    return 0;
}