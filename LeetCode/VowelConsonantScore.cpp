#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int vowelConsonantScore(string s) {
        int v = 0;
        int c = 0;

        for(char ch : s)
        {
            if(ch >= 'a' && ch <= 'z')
            {
                if(ch == 'a' || ch == 'e'|| ch == 'i' || ch == 'o' || ch == 'u')
                {
                    v++;
                }
                else
                {
                    c++;
                }
            }
        }

        if(c > 0)
        {
            return v / c;
        }
        return 0;
    }
};

int main() {
    Solution sol;

    string s;
    getline(cin, s);   // read full line including spaces

    int result = sol.vowelConsonantScore(s);
    cout << result << endl;

    return 0;
}