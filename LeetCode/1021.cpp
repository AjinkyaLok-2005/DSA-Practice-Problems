#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string removeOuterParentheses(string s) {
        int depth = 0;

        string result = "";

        for(char &ch : s)
        {
            if(ch == '(')
            {
                if(depth != 0)
                    result.push_back(ch);

                depth++;
            }
            else
            {
                depth--;

                if(depth != 0)
                    result.push_back(ch);
            }
        }

        return result;
    }
};

int main()
{
    Solution obj;

    string s;
    cin >> s;

    string result = obj.removeOuterParentheses(s);

    cout << result << endl;

    return 0;
}