#include<iostream>
#include<string>
using namespace std;

class Solution {
public:
    bool isSubsequence(string s, string t) {
        int n1 = s.length();
        int n2 = t.length();

        int i = 0;
        int j = 0;

        int count = 0;

        while(i < n1 && j < n2)
        {
            if(s[i] == t[j])
            {
                i++;
                j++;
                count++;
            }
            else
            {
                j++;
            }
        }

        if(count == n1)
            return true;
        else
            return false;
    }
};

int main()
{
    Solution s;
    string str1 = "abc";
    string str2 = "ahbgdc";

    bool ans = s.isSubsequence(str1, str2);

    if(ans)
        cout<<"True"<<endl;
    else
        cout<<"False"<<endl;

    return 0;
}
