#include<iostream>
using namespace std;

class Solution {
public:
    int numSteps(string s) {
        int steps = 0;
        int carry = 0;

        for(int i = s.size() - 1; i > 0; i--) {
            if((s[i] - '0' + carry) % 2 == 0) {
                // even
                steps += 1;
            } else {
                // odd
                steps += 2;
                carry = 1;
            }
        }

        return steps + carry;
    }
};

int main() {
    Solution sol;
    string s = "1101";
    cout << sol.numSteps(s) << endl; // Output: 6
    return 0;
}