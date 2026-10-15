#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    int sumCounts(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;

        for (int i = 0; i < n; i++) {
            unordered_set<int> st;

            for (int j = i; j < n; j++) {
                st.insert(nums[j]);
                sum += st.size() * st.size();
            }
        }

        return sum;
    }
};

int main() {
    Solution sol;

    int n;
    cin >> n;

    vector<int> nums(n);

    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    cout << sol.sumCounts(nums) << endl;

    return 0;
}