#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>

using namespace std;

class Solution {
public:
    int n;
    unordered_set<string> st;

    bool solve(int idx, string& s)
    {
        // Base case
        if(idx == n)
        {
            return true;
        }

        if(st.find(s) != st.end())
        {
            return true;
        }

        for(int l = 1; l <= n; l++)
        {
            string temp = s.substr(idx, l);

            if(st.find(temp) != st.end() && solve(idx + l, s))
            {
                return true;
            }
        }

        return false;
    }

    bool solveMem(int idx, string& s, vector<int>& dp)
    {
        // Base case
        if(idx == n)
        {
            return true;
        }

        if(dp[idx] != -1)
        {
            return dp[idx];
        }

        if(st.find(s) != st.end())
        {
            return true;
        }

        for(int l = 1; l <= n; l++)
        {
            string temp = s.substr(idx, l);

            if(st.find(temp) != st.end() && solveMem(idx + l, s, dp))
            {
                return dp[idx] = true;
            }
        }

        return dp[idx] = false;
    }

    bool solveTab(string s)
    {
        vector<int> dp(n + 1, 0);

        dp[n] = true;

        for(int idx = n - 1; idx >= 0; idx--)
        {
            if(st.find(s) != st.end())
            {
                return true;
            }

            dp[idx] = false;

            for(int l = 1; l <= n - idx; l++)
            {
                string temp = s.substr(idx, l);

                if(st.find(temp) != st.end() && dp[idx + l])
                {
                    dp[idx] = true;
                    break;
                }
            }
        }

        return dp[0];
    }

    bool wordBreak(string s, vector<string>& wordDict)
    {
        n = s.length();

        st.clear();

        for(string &word : wordDict)
        {
            st.insert(word);
        }

        // Uncomment whichever approach you want to test.

        // return solve(0, s);

        // vector<int> dp(n + 1, -1);
        // return solveMem(0, s, dp);

        return solveTab(s);
    }
};

int main()
{
    Solution obj;

    string s;
    cout << "Enter the string: ";
    cin >> s;

    int m;
    cout << "Enter number of words in dictionary: ";
    cin >> m;

    vector<string> wordDict(m);

    cout << "Enter the dictionary words:\n";
    for(int i = 0; i < m; i++)
    {
        cin >> wordDict[i];
    }

    bool ans = obj.wordBreak(s, wordDict);

    if(ans)
        cout << "\nWord Break is Possible\n";
    else
        cout << "\nWord Break is Not Possible\n";

    return 0;
}