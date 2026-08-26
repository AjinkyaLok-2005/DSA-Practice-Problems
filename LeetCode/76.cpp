#include <iostream>
#include <string>
#include <unordered_map>
#include <climits>
using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.length();

        if(t.length() > n)
            return "";

        unordered_map<char, int> mp;

        for(char& ch : t)
        {
            mp[ch]++;
        }

        int reqCount = t.length();
        int left = 0;
        int right = 0;

        int minLen = INT_MAX;
        int startIdx = 0;

        while(right < n)
        {
            char ch = s[right];

            if(mp[ch] > 0)
                reqCount--;

            mp[ch]--;

            while(reqCount == 0)
            {
                int currLen = right - left + 1;

                if(currLen < minLen)
                {
                    minLen = currLen;
                    startIdx = left;
                }

                char lch = s[left];
                mp[lch]++;

                if(mp[lch] > 0)
                {
                    reqCount++;
                }

                left++;
            }

            right++;
        }

        if(minLen == INT_MAX)
        {
            return "";
        }
        else
        {
            return s.substr(startIdx, minLen);
        }
    }
};

int main() {
    Solution obj;

    string s, t;

    cout << "Enter string s: ";
    getline(cin, s);

    cout << "Enter string t: ";
    getline(cin, t);

    string result = obj.minWindow(s, t);

    cout << "Minimum window substring: " << result << endl;

    return 0;
}