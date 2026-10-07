#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int n;
    unordered_set<string> st;

    void solve(string& s, int i, string& curr, int count, int& maxLen)
    {
        if(count < 0)
            return;

        if(i == n)
        {
            if(count == 0)
            {
                if(curr.length() > maxLen)
                {
                    maxLen = curr.length();
                    st.clear();
                }

                if(curr.length() == maxLen)
                {
                    st.insert(curr);
                }
            }

            return;
        }

        // Alphabet
        if(s[i] != '(' && s[i] != ')')
        {
            curr.push_back(s[i]);

            solve(s, i + 1, curr, count, maxLen);

            curr.pop_back();

            return;
        }

        // Option 1: Keep the current parenthesis
        curr.push_back(s[i]);

        if(s[i] == '(')
            solve(s, i + 1, curr, count + 1, maxLen);
        else
            solve(s, i + 1, curr, count - 1, maxLen);

        curr.pop_back();

        // Option 2: Remove the current parenthesis
        solve(s, i + 1, curr, count, maxLen);
    }

    vector<string> removeInvalidParentheses(string s)
    {
        n = s.length();
        st.clear();

        int maxLen = 0;
        string curr = "";

        solve(s, 0, curr, 0, maxLen);

        return vector<string>(begin(st), end(st));
    }
};

int main()
{
    Solution obj;

    string s;

    cout << "Enter the string: ";
    cin >> s;

    vector<string> result = obj.removeInvalidParentheses(s);

    cout << "Valid strings with minimum removals:\n";

    for(string str : result)
    {
        cout << str << endl;
    }

    return 0;
}