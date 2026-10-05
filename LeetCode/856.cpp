#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    int scoreOfParentheses(string s) {
        int n = s.length();

        // APPROACH 1

        // vector<int> vec;

        // int score = 0;

        // for(int i = 0; i < n; i++)
        // {
        //     if(s[i] == '(')
        //     {
        //         vec.push_back(score);
        //         score = 0;
        //     }
        //     else
        //     {
        //         if(s[i-1] == '(')
        //         {
        //             score = vec.back() + 1;
        //         }
        //         else
        //         {
        //             score = (2*score) + vec.back();
        //         }
        //         vec.pop_back();
        //     }
        // }

        // return score;


        // APPROACH 2

        int score = 0;
        int depth = 0;

        for(int i = 0; i < n; i++)
        {
            if(s[i] == '(')
            {
                depth++;
            }
            else
            {
                depth--;

                if(s[i-1] == '(')
                {
                    score += (1 << depth);
                }
            }
        }

        return score;
    }
};

int main()
{
    Solution obj;

    string s = "((()))()";

    int result = obj.scoreOfParentheses(s);

    cout << "Score: " << result << endl;

    return 0;
}