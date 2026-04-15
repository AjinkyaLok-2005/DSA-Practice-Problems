#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    int closestTarget(vector<string>& words, string target, int startIndex) {
        int n = words.size();
        int result = INT_MAX;

        for(int i = 0; i < n; i++)
        {
            if(words[i] == target)
            {
                int straightDistance = abs(i - startIndex);
                int circularDistance = n - straightDistance;

                result = min({result, straightDistance, circularDistance});
            }
        }

        if(result == INT_MAX)
            return -1;
        else
            return result;
    }
};

int main() {
    Solution obj;

    vector<string> words = {"hello", "i", "am", "hello", "world"};
    string target = "hello";
    int startIndex = 1;

    int result = obj.closestTarget(words, target, startIndex);

    cout << "Closest distance: " << result << endl;

    return 0;
}