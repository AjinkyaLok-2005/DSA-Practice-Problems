#include<iostream>
#include<string>
using namespace std;

class Solution {
public:
    char findTheDifference(string s, string t) {
        char ans = 0;

        for(char c : s)
        {
            ans = ans ^ c;
        }

        for(char c : t)
        {
            ans = ans ^ c;
        }

        return ans;
    }
};

int main() {
    Solution sol;

    string s, t;
    cin >> s >> t;

    char result = sol.findTheDifference(s, t);
    cout << result << endl;

    return 0;
}
