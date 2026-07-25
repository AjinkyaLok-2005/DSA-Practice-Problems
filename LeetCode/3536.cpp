#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int maxProduct(int n) {
        vector<int> digits;

        while(n > 0)
        {
            int d = n % 10;
            digits.push_back(d);
            n = n / 10;
        }

        int N = digits.size();

        // approach 3 - O(N)
        int maxi1 = INT_MIN;
        int maxi2 = INT_MIN;

        for(int i = 0; i < N; i++)
        {
            if(digits[i] >= maxi1)
            {
                maxi2 = maxi1;
                maxi1 = digits[i];
            }
            else if(digits[i] >= maxi2)
            {
                maxi2 = digits[i];
            }
        }

        return maxi1 * maxi2;
    }
};

int main()
{
    Solution sol;

    vector<int> testCases = {31, 22, 124, 245, 39, 100, 987654321};

    for(int n : testCases)
    {
        cout << "n = " << n << " -> Max Product = " << sol.maxProduct(n) << endl;
    }

    return 0;
}