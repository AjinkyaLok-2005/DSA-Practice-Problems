#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    int reverseDegree(string s) {
        int deg = 0;

        for (int i = 0; i < s.length(); i++) {
            int rev = 26 - (s[i] - 'a');

            deg += (i + 1) * rev;
        }

        return deg;
    }
};

int main() {
    string s;

    cout << "Enter the string: ";
    cin >> s;

    Solution obj;

    int result = obj.reverseDegree(s);

    cout << "Reverse Degree: " << result << endl;

    return 0;
}