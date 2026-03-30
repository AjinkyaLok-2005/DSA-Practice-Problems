#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    bool canBeEqual(string s1, string s2) {
        int even[26] = {0};
        int odd[26] = {0};

        for(int i = 0; i < 4; i++)
        {
            if(i % 2 == 0) // even index
            {
                even[s1[i] - 'a']++;
                even[s2[i] - 'a']--;
            }
            else //odd index
            {
                odd[s1[i] - 'a']++;
                odd[s2[i] - 'a']--;
            }
        }

        for(int i = 0; i < 26; i++)
        {
            if(even[i] != 0 || odd[i] != 0)
            {
                return false;
            }
        }
        return true;
    }
};

int main()
{
    Solution sol;
    string s1 = "abcd";
    string s2 = "cdab";

    bool result = sol.canBeEqual(s1, s2);
    cout << (result ? "true" : "false") << endl;

    return 0;
}