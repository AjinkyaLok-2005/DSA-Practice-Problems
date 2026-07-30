#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

class Solution {
public:
    int minimumPushes(string word) {
        int result = 0;

        unordered_map<int, int> mp;

        int assign_key = 2;
        for (char &ch : word) {
            if (assign_key > 9) {
                assign_key = 2;
            }

            mp[assign_key]++;

            result += mp[assign_key];

            assign_key++;
        }

        return result;
    }
};

int main() {
    Solution obj;

    string word;

    cout << "Enter the word: ";
    cin >> word;

    int answer = obj.minimumPushes(word);

    cout << "Minimum Pushes = " << answer << endl;

    return 0;
}