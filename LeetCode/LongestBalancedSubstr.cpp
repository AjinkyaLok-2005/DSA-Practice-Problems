#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    bool checkBalanced(vector<int>& freq)
    {
        int common = 0;
        for(int i = 0; i < 26; i++)
        {
            if(freq[i] == 0)
                continue;
            if(common == 0)
                common = freq[i];
            else if(freq[i] != common)
                return false;
        }

        return true;
    }

    int longestBalanced(string s) {
        int n = s.length();

        int maxi = 0;

        for(int i = 0; i < n; i++)
        {
            vector<int> freq(26, 0);

            for(int j = i; j < n; j++)
            {
                freq[s[j] - 'a']++;

                if(checkBalanced(freq))
                {
                    maxi = max(maxi, j-i+1);
                }
            }
        }
        return maxi;
    }
};

int main()
{
    string s;
    cin >> s;

    Solution obj;
    cout << obj.longestBalanced(s);

    return 0;
}