#include <iostream>
#include <string>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();

        int left = 0;
        int maxLen = 0;

        unordered_map<char, int> mp;

        for(int right = 0; right < n; right++)
        {
            mp[s[right]]++;

            while(mp[s[right]] > 1)
            {
                mp[s[left]]--;
                left++;
            }

            maxLen = max(maxLen, right - left + 1);
        }
        
        return maxLen;
    }
};

int main() {
    Solution obj;

    string s;
    cin >> s;

    int ans = obj.lengthOfLongestSubstring(s);

    cout << ans << endl;

    return 0;
}