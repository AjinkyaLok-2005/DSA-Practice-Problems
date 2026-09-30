#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {
        int depth = 0;
        vector<int> result;

        for (int i = 0; i < seq.length(); i++) {
            if (seq[i] == '(') {
                depth++;

                if (depth % 2 == 0)
                    result.push_back(0);
                else
                    result.push_back(1);
            }
            else {
                if (depth % 2 == 0)
                    result.push_back(0);
                else
                    result.push_back(1);

                depth--;
            }
        }

        return result;
    }
};

int main() {
    Solution sol;

    string seq;
    cin >> seq;

    vector<int> result = sol.maxDepthAfterSplit(seq);

    cout << "[";

    for (int i = 0; i < result.size(); i++) {
        cout << result[i];

        if (i != result.size() - 1)
            cout << ",";
    }

    cout << "]" << endl;

    return 0;
}