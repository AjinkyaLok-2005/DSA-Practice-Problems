#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

class Solution {
public:
    int minimumPushes(string word) {
        vector<int> mp(26, 0);

        // Count the frequency of each character
        for (char &ch : word) {
            mp[ch - 'a']++;
        }

        // Sort frequencies in descending order
        sort(begin(mp), end(mp), greater<int>());

        int result = 0;

        // Calculate the minimum pushes
        for (int i = 0; i < 26; i++) {
            int freq = mp[i];
            int press = i / 8 + 1;

            result += press * freq;
        }

        return result;
    }
};

int main() {
    Solution obj;

    string word;

    cout << "Enter the word: ";
    cin >> word;

    int ans = obj.minimumPushes(word);

    cout << "Minimum Pushes: " << ans << endl;

    return 0;
}