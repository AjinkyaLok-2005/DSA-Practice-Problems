#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {

        unordered_set<int> st;
        st.insert(nums.begin(), nums.end());

        int num = k;

        while(st.find(num) != st.end())
        {
            num += k;
        }

        return num;
    }
};

int main() {

    vector<int> nums = {1, 2, 3, 6, 9, 12, 15};
    int k = 3;

    Solution obj;

    int ans = obj.missingMultiple(nums, k);

    cout << "Missing multiple: " << ans << endl;

    return 0;
}