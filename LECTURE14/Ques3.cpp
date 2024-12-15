#include <iostream>
using namespace std;

class Solution {
public:
    long long int binarySearch(int n)
    {
        int s = 0;
        int e = n;
        long long int mid = s + (e - s) / 2;

        long long int ans = -1;
        while (s <= e)
        {
            long long int square = mid * mid;

            if (square == n)
                return mid;

            if (square < n)
            {
                ans = mid;
                s = mid + 1;
            }
            else
            {
                e = mid - 1;
            }
            mid = s + (e - s) / 2;
        }
        return ans;
    }

    int mySqrt(int x) {
        return binarySearch(x);
    }
};

int main() {
    Solution solution;
    int num;
    cout << "Enter a number: ";
    cin >> num;

    cout << "Square root (integer part) of " << num << " is: " << solution.mySqrt(num) << endl;

    return 0;
}
