#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maximumLengthSubstring(string s) {
        int n = s.size();

        unordered_map<char, int> mp;

        int left = 0;
        int maxLen = INT_MIN;

        for(int right = 0; right < n; right++)
        {
            mp[s[right]]++;

            while(mp[s[right]] > 2)
            {
                mp[s[left]]--;
                left++;
            }

            maxLen = max(maxLen, right - left + 1);
        }

        return maxLen;
    }
};

int main()
{
    Solution sol;

    string s1 = "bcbbbcba";
    cout << "Input: " << s1 << " -> Output: " << sol.maximumLengthSubstring(s1) << endl;

    string s2 = "aaaa";
    cout << "Input: " << s2 << " -> Output: " << sol.maximumLengthSubstring(s2) << endl;

    // custom test
    string s3;
    cout << "Enter a string: ";
    cin >> s3;
    cout << "Output: " << sol.maximumLengthSubstring(s3) << endl;

    return 0;
}