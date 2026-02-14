#include<iostream>
using namespace std;

class Solution {
public:
    int solve(int n)
    {
        if(n == 0)
            return 1;

        if(n == 1)
            return 1;

        int ways = solve(n-1) + solve(n-2);

        return ways;
    }

    int climbStairs(int n) {
        return solve(n);
    }
};

int main()
{
    Solution s;
    int n = 5;
    cout << s.climbStairs(n) << endl;
    return 0;
}