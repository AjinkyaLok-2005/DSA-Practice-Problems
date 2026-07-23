#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int solve(int i, string& s, int n)
    {
        if(i == n)
        {
            return 1;
        }

        if(s[i] == '0')
        {
            return 0;
        }

        int result = solve(i+1, s, n);

        if(i+1 < n)
        {
            if(s[i] == '1' || (s[i] == '2' && s[i+1] <= '6'))
            {
                result += solve(i+2, s, n);
            }
        }

        return result;
    }

    int solveMem(int i, string& s, int n, vector<int>& dp)
    {
        if(i == n)
        {
            return 1;
        }

        if(dp[i] != -1)
        {
            return dp[i];
        }

        if(s[i] == '0')
        {
            return 0;
        }

        int result = solveMem(i+1, s, n, dp);

        if(i+1 < n)
        {
            if(s[i] == '1' || (s[i] == '2' && s[i+1] <= '6'))
            {
                result += solveMem(i+2, s, n, dp);
            }
        }

        return dp[i] = result;
    }

    int numDecodings(string s)
    {
        int n = s.length();

        // return solve(0, s, n);

        vector<int> dp(n + 1, -1);

        return solveMem(0, s, n, dp);
    }
};

int main()
{
    Solution obj;

    string s;

    cout << "Enter the encoded string: ";
    cin >> s;

    int ans = obj.numDecodings(s);

    cout << "Number of possible decodings: " << ans << endl;

    return 0;
}