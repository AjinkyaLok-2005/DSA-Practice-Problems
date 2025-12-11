#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int arrangeCoins(int n) {
        long long x = n;
        long long k = (sqrt(1 + 8*x) - 1) / 2;
        return (int)k;
    }
};

int main() {
    int n;
    cout << "Enter number of coins: ";
    cin >> n;

    Solution sol;
    int result = sol.arrangeCoins(n);

    cout << "Complete rows of staircase: " << result << endl;

    return 0;
}
