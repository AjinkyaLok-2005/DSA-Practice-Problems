#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {

        if(s.length() != t.length())
            return false;

        int freq[26] = {0};

        for(char ch : s)
        {
            freq[ch - 'a']++;
        }

        for(char ch : t)
        {
            if(freq[ch - 'a'] == 0)
                return false;

            freq[ch - 'a']--;
        }

        return true;
    }
};

int main() {

    Solution obj;

    string s, t;

    cout << "Enter first string: ";
    cin >> s;

    cout << "Enter second string: ";
    cin >> t;

    if(obj.isAnagram(s, t))
        cout << "The strings are anagrams." << endl;
    else
        cout << "The strings are not anagrams." << endl;

    return 0;
}