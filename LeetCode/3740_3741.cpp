#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        int n = nums.size();

        unordered_map<int, vector<int>> mp;

        int result = INT_MAX;

        for(int k = 0; k < n; k++)
        {
            mp[nums[k]].push_back(k);

            if(mp[nums[k]].size() >= 3)
            {
                //i, j, k
                //2*(k-i)
                vector<int> &vec = mp[nums[k]];
                int size = vec.size();

                int i = vec[size - 3];

                result = min(result, (k-i));
            }
        }

        return result == INT_MAX ? -1 : 2* result;
    }
};

int main() {
    Solution obj;

    int n;
    cout << "Enter size: ";
    cin >> n;

    vector<int> nums(n);
    cout << "Enter elements: ";
    for(int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    int result = obj.minimumDistance(nums);

    if(result == -1)
        cout << "No valid triplet found" << endl;
    else
        cout << "Minimum Distance: " << result << endl;

    return 0;
}