#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    string addBinary(string a, string b) {
        int i = a.size() - 1;
        int j = b.size() - 1;
        int carry = 0;
        string result = "";

        while (i >= 0 || j >= 0 || carry) {
            int sum = carry;
            if (i >= 0) sum += (a[i] - '0');
            if (j >= 0) sum += (b[j] - '0');

            result += (sum % 2) + '0';   // current bit
            carry = sum / 2;             // carry for next bit

            i--;
            j--;
        }

        reverse(result.begin(), result.end());
        return result;
    }
};

int main() {
    Solution sol;

    string a1 = "11", b1 = "1";
    cout << "Input: a = \"" << a1 << "\", b = \"" << b1 << "\"" << endl;
    cout << "Output: " << sol.addBinary(a1, b1) << endl << endl;

    string a2 = "1010", b2 = "1011";
    cout << "Input: a = \"" << a2 << "\", b = \"" << b2 << "\"" << endl;
    cout << "Output: " << sol.addBinary(a2, b2) << endl << endl;

    // Extra test case
    string a3 = "0", b3 = "0";
    cout << "Input: a = \"" << a3 << "\", b = \"" << b3 << "\"" << endl;
    cout << "Output: " << sol.addBinary(a3, b3) << endl;

    return 0;
}