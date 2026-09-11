#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& digits) {
        unordered_set<int> st;
        int n = digits.size();

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                for (int k = 0; k < n; k++) {

                    // Cannot use the same digit index twice
                    if (i == j || j == k || i == k) {
                        continue;
                    }

                    int num = digits[i] * 100
                            + digits[j] * 10
                            + digits[k];

                    // Three-digit and even number
                    if (num >= 100 && num % 2 == 0) {
                        st.insert(num);
                    }
                }
            }
        }

        vector<int> result(begin(st), end(st));

        sort(begin(result), end(result));

        return result;
    }
};

int main() {
    Solution solution;

    vector<int> digits = {2, 1, 3, 0};

    vector<int> result = solution.findEvenNumbers(digits);

    cout << "Even 3-digit numbers: ";

    for (int num : result) {
        cout << num << " ";
    }

    cout << endl;

    return 0;
}