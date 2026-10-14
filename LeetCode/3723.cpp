
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        if (sum > num * 9)
            return "";

        int nines = sum / 9;
        int remain = sum % 9;

        string result(nines, '9');

        if (remain > 0) {
            result.push_back(remain + '0');
        }

        result.append(num - result.length(), '0');

        return result;
    }
};

int main() {
    Solution sol;

    int num, sum;
    cin >> num >> sum;

    cout << sol.maxSumOfSquares(num, sum) << endl;

    return 0;
}
