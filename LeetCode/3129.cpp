#include<iostream>
#include<cstring>
using namespace std;

class Solution {
public:
    int M = 1e9 + 7;
    int t[201][201][2];

    int solve(int onesLeft, int zerosLeft, bool lastWasOne, int limit)
    {
        if(onesLeft == 0 && zerosLeft == 0)
        {
            return 1;
        }

        if(t[onesLeft][zerosLeft][lastWasOne] != -1)
        {
            return t[onesLeft][zerosLeft][lastWasOne];
        }

        int result = 0;

        if(lastWasOne == true)
        {
            for(int len = 1; len <= min(zerosLeft, limit); len++)
            {
                result = (result + solve(onesLeft, zerosLeft - len, false, limit)) % M;
            }
        }
        else
        {
            for(int len = 1; len <= min(onesLeft, limit); len++)
            {
                result = (result + solve(onesLeft - len, zerosLeft, true, limit)) % M;
            }
        }

        return t[onesLeft][zerosLeft][lastWasOne] = result;
    }

    int numberOfStableArrays(int zero, int one, int limit) {
        memset(t, -1, sizeof(t));

        int startWithOne = solve(one, zero, false, limit);
        int startWithZero = solve(one, zero, true, limit);

        return (startWithOne + startWithZero) % M;
    }
};

int main()
{
    Solution s;
    int zero = 2, one = 2, limit = 1;
    cout << s.numberOfStableArrays(zero, one, limit) << endl;

    return 0;
}