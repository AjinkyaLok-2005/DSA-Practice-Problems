#include<iostream>
#include<string>
using namespace std;

class Solution {
public:
    int countBinarySubstrings(string s) {
        int result = 0;

        int prevCount = 0;
        int currCount = 1;

        for(int i = 1; i < s.length(); i++)
        {
            if(s[i] == s[i-1])
            {
                currCount++;
            }
            else
            {
                result += min(prevCount, currCount);;
                prevCount = currCount;
                currCount = 1;
            }
        }

        return result + min(prevCount, currCount);
    }
};

int main()
{
    Solution s;
    string str = "00110011";
    int ans = s.countBinarySubstrings(str);
    cout << ans << endl;

    return 0;
}