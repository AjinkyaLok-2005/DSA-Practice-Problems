#include<iostream>
#include<unordered_set>
using namespace std;

class Solution {
public:
    int countPrimeSetBits(int left, int right) {
        unordered_set<int> primes = { 2, 3, 5, 7, 11, 13, 17, 19};

        int result = 0;

        for(int num = left; num <= right; num++)
        {
            int setBits = __builtin_popcount(num);

            if(primes.count(setBits))
                result += 1;
        }

        return result;
    }
};

int main()
{
    int left, right;

    cout << "Enter left and right range: ";
    cin >> left >> right;

    Solution obj;
    int ans = obj.countPrimeSetBits(left, right);

    cout << "Count of numbers having prime set bits = " << ans << endl;

    return 0;
}