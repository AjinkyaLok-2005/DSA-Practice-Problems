#include<iostream>
using namespace std;

class Solution {
public:
    int reverseBits(int n) {
        if(n == 0)
            return 0;

        int result = 0;
        for(int i = 1; i <= 32; i++)
        {
            result <<= 1;

            result = (result | (n & 1));

            n >>= 1; 
        }

        return result;
    }
};

int main()
{
    Solution s;
    int n = 43261596;
    cout << s.reverseBits(n) << endl;
    return 0;
}