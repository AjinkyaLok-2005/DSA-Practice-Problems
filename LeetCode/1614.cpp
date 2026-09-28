#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxDepth(string s) {
        int depth = 0;
        int count = 0;

        for(char ch : s)
        {
            if(ch == '(')
            {
                count++;
                depth = max(depth, count);
            }
            else if(ch == ')')
            {
                count--;
            }
        }

        return depth;
    }
};

int main()
{
    Solution solution;

    string s;
    cout << "Enter parentheses string: ";
    cin >> s;

    int result = solution.maxDepth(s);

    cout << "Maximum Depth: " << result << endl;

    return 0;
}