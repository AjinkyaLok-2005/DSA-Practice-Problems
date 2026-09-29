#include <iostream>
#include <string>
#include <stack>
#include <vector>
#include <algorithm>

using namespace std;


// ============================================================
// APPROACH 1
// Stack + Reverse Substring
// Time Complexity: O(n^2) in worst case
// Space Complexity: O(n)
// ============================================================

class Solution1 {
public:
    string reverseParentheses(string s) {

        stack<int> lastSkipLength;

        string result;

        for(char ch : s)
        {
            if(ch == '(')
            {
                lastSkipLength.push(result.length());
            }
            else if(ch == ')')
            {
                int l = lastSkipLength.top();
                lastSkipLength.pop();

                reverse(result.begin() + l, result.end());
            }
            else
            {
                result.push_back(ch);
            }
        }

        return result;
    }
};


// ============================================================
// APPROACH 2
// Matching Parentheses + Direction/Jump Technique
// Time Complexity: O(n)
// Space Complexity: O(n)
// ============================================================

class Solution2 {
public:
    string reverseParentheses(string s) {

        int n = s.length();

        stack<int> openBracketIdx;

        vector<int> door(n);

        // Find the matching parenthesis for every bracket
        for(int i = 0; i < n; i++)
        {
            if(s[i] == '(')
            {
                openBracketIdx.push(i);
            }
            else if(s[i] == ')')
            {
                int j = openBracketIdx.top();
                openBracketIdx.pop();

                door[i] = j;
                door[j] = i;
            }
        }

        string result;

        int flag = 1;

        for(int i = 0; i < n; i += flag)
        {
            if(s[i] == '(' || s[i] == ')')
            {
                // Jump to the matching bracket
                i = door[i];

                // Change direction
                flag = -flag;
            }
            else
            {
                result.push_back(s[i]);
            }
        }

        return result;
    }
};


// ============================================================
// MAIN FUNCTION
// ============================================================

int main()
{
    string s;

    cout << "Enter string: ";
    cin >> s;

    // --------------------------------------------------------
    // Approach 1
    // --------------------------------------------------------

    Solution1 sol1;

    string result1 = sol1.reverseParentheses(s);

    cout << "\nApproach 1 Result: " << result1 << endl;


    // --------------------------------------------------------
    // Approach 2
    // --------------------------------------------------------

    Solution2 sol2;

    string result2 = sol2.reverseParentheses(s);

    cout << "Approach 2 Result: " << result2 << endl;


    return 0;
}