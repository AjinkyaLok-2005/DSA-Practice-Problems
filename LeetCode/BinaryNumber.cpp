#include<iostream>
using namespace std;

class Solution {
public:
    bool hasAlternatingBits(int n) {

        unsigned int x = n ^ (n >> 1);

        return (x & (x + 1)) == 0;
    }
};

int main()
{
    Solution s;
    int n = 5;
    bool ans = s.hasAlternatingBits(n);
    cout << ans << endl;

    return 0;
}