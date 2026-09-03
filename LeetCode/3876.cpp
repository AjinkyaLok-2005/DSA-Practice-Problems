#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int minEl = *min_element(nums1.begin(), nums1.end());

        if (minEl % 2 == 1)
            return true;

        for (int& num : nums1) {
            if (num % 2 == 1)
                return false;
        }

        return true;
    }
};

int main() {
    Solution solution;

    vector<int> nums1 = {1, 4, 7};

    bool result = solution.uniformArray(nums1);

    cout << boolalpha << result << endl;

    return 0;
}