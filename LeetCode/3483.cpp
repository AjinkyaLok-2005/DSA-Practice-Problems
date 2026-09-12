#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int totalNumbers(vector<int>& digits) {
        int count = 0;
        vector<int> mp(10, 0);

        for (int& digit : digits) {
            mp[digit]++;
        }

        for (int i = 1; i <= 9; i++) {
            if (mp[i] == 0) continue;
            mp[i]--;

            for (int j = 0; j <= 9; j++) {
                if (mp[j] == 0) continue;
                mp[j]--;

                for (int k = 0; k <= 8; k += 2) {
                    if (mp[k] == 0) continue;
                    mp[k]--;

                    count++;

                    mp[k]++;
                }

                mp[j]++;
            }

            mp[i]++;
        }

        return count;
    }
};

int main() {
    Solution obj;

    vector<int> digits = {1, 2, 3, 4};

    int result = obj.totalNumbers(digits);

    cout << "Total 3-digit even numbers: " << result << endl;

    return 0;
}