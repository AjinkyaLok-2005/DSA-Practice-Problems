#include<iostream>
#include<string>
using namespace std;

class Solution {
public:
    bool rotateString(string s, string goal) {
        int m = s.length();
        int n = goal.length();

        if(m != n)
            return false;

        //APPROACH 1
 
        // for(int count = 1; count <= m; count++)
        // {
        //     rotate(begin(s), begin(s)+1, end(s));

        //     if(s == goal)
        //         return true;
        // }

        // return false;


        //APPROACH 2

        string doubled = s + s;

        if(doubled.find(goal) != -1)
            return true;

        return false;
    }
};

int main()
{
    Solution s;

    string str1 = "abcde";
    string str2 = "cdeab";

    bool ans = s.rotateString(str1, str2);

    cout << ans << endl;

    return 0;
}