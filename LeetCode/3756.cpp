#include<iostream>
#include<vector>
#include<string>
using namespace std;

class Solution {
public:
    int MOD = 1e9 + 7;
    typedef long long ll;

    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        int n = s.size();

        vector<int> digitSum(n, 0);
        vector<ll> numberUpto(n, 0);
        vector<ll> nonZeroCount(n, 0);
        vector<ll> pow10(n + 1, 0);

        digitSum[0] = s[0] - '0';
        for (int i = 1; i < n; i++) {
            int digit = s[i] - '0';
            digitSum[i] = digitSum[i - 1] + digit;
        }

        numberUpto[0] = s[0] - '0';
        for (int i = 1; i < n; i++) {
            int digit = s[i] - '0';
            if (digit != 0) {
                numberUpto[i] = ((numberUpto[i - 1] * 10) + digit) % MOD;
            } else {
                numberUpto[i] = numberUpto[i - 1];
            }
        }

        nonZeroCount[0] = (s[0] != '0') ? 1 : 0;

        for (int i = 1; i < n; i++) {
            int digit = s[i] - '0';
            nonZeroCount[i] = nonZeroCount[i - 1] + (digit != 0);
        }

        pow10[0] = 1;
        for (int i = 1; i <= n; i++) {
            pow10[i] = (pow10[i - 1] * 10) % MOD;
        }

        int q = queries.size();
        vector<int> result(q);

        for (int i = 0; i < q; i++) {
            int l = queries[i][0];
            int r = queries[i][1];

            ll sum = digitSum[r] - ((l == 0) ? 0 : digitSum[l - 1]);

            ll numBefore = (l == 0) ? 0 : numberUpto[l - 1];

            int k = nonZeroCount[r] - ((l == 0) ? 0 : nonZeroCount[l - 1]);

            ll x = (numberUpto[r] - (numBefore * pow10[k]) % MOD + MOD) % MOD;

            result[i] = (int)((x * sum) % MOD);
        }

        return result;
    }
};

int main() {
    string s;
    cout << "Enter the string: ";
    cin >> s;

    int q;
    cout << "Enter number of queries: ";
    cin >> q;

    vector<vector<int>> queries(q, vector<int>(2));

    cout << "Enter each query (l r):\n";
    for (int i = 0; i < q; i++) {
        cin >> queries[i][0] >> queries[i][1];
    }

    Solution obj;
    vector<int> ans = obj.sumAndMultiply(s, queries);

    cout << "Output:\n";
    for (int x : ans) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}
