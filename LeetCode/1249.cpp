#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string minRemoveToMakeValid(string s) {
        int n = s.length();

        int count = 0;

        // Left to Right
        // Remove invalid ')'
        for(int i = 0; i < n; i++)
        {
            if(s[i] == '(')
                count++;

            else if(s[i] == ')')
            {
                if(count == 0)
                    s[i] = '#';
                else
                    count--;
            }
        }

        count = 0;

        // Right to Left
        // Remove invalid '('
        for(int i = n - 1; i >= 0; i--)
        {
            if(s[i] == ')')
                count++;

            else if(s[i] == '(')
            {
                if(count == 0)
                    s[i] = '#';
                else
                    count--;
            }
        }

        // Build final result
        string result;

        for(char ch : s)
        {
            if(ch != '#')
                result.push_back(ch);
        }

        return result;
    }
};

int main()
{
    Solution obj;

    string s;

    cout << "Enter the string: ";
    cin >> s;

    string result = obj.minRemoveToMakeValid(s);

    cout << "Valid string: " << result << endl;

    return 0;
}