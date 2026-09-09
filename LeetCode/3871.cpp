#include <iostream>
using namespace std;

#define ll long long

class Solution {
public:
    long long countCommas(long long n) {
        ll result = 0;

        ll start = 1000;

        while (start <= n) {
            result += (n - start + 1);
            start *= 1000;
        }

        return result;
    }
};

int main() {
    Solution sol;

    ll n;
    cin >> n;

    cout << sol.countCommas(n) << endl;

    return 0;
}