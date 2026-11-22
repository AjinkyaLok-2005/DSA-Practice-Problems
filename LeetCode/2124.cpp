#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    bool checkString(string s) {
        int n = s.length();

        // int count = 0;
        bool isCorrect = true;

        // Approach 1 
        // for(int i = 1; i < n; i++)
        // {
        //     if(s[i] - s[i-1] == 0)
        //         continue;
        //     else if(s[i] - s[i-1] == 1 && count == 0)
        //     {
        //         count++;
        //     }
        //     else
        //     {
        //         isCorrect = false;
        //         break;
        //     }
        // }

        // Approach 2 - Best 
        for(int i = 0; i < n-1; i++)
        {
            if(s[i] == 'b' && s[i+1] == 'a')
            {
                return false;
            }
        }

        return true;
    }
};

int main() {
    Solution sol;
    string s;

    cout << "Enter the string: ";
    cin >> s;

    if(sol.checkString(s))
        cout << "true" << endl;
    else
        cout << "false" << endl;

    return 0;
}