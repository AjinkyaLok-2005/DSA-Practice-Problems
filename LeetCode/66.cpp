#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();
        
        for (int i = n - 1; i >= 0; i--) {
            if (digits[i] < 9) {
                digits[i]++;
                return digits;
            }
            digits[i] = 0;
        }
        
        // All digits were 9, so we need an extra digit at the front
        digits.insert(digits.begin(), 1);
        return digits;
    }
};

int main() {
    Solution sol;

    vector<vector<int>> testCases = {
        {1, 2, 3},
        {4, 3, 2, 1},
        {9},
        {9, 9, 9}
    };

    for (auto& digits : testCases) {
        vector<int> result = sol.plusOne(digits);

        cout << "Result: [";
        for (int i = 0; i < result.size(); i++) {
            cout << result[i];
            if (i != result.size() - 1) cout << ", ";
        }
        cout << "]" << endl;
    }

    return 0;
}