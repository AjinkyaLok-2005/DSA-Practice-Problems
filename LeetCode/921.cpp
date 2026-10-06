#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    int minAddToMakeValid(string s) {
        int open = 0;
        int moves = 0;

        for(char ch : s)
        {
            if(ch == '(')
                open++;
            else
            {
                if(open > 0)
                    open--;
                else
                    moves++;
            }
        }

        return moves + open;
    }
};

int main() {
    string s;

    cout << "Enter parentheses string: ";
    cin >> s;

    Solution obj;

    int result = obj.minAddToMakeValid(s);

    cout << "Minimum additions required: " << result << endl;

    return 0;
}