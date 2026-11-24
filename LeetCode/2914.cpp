
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minChanges(string s) {
        int n = s.length();
        int count = 0;

        for(int i = 0; i < n; i += 2)
        {
            if(s[i] != s[i+1])
            {
                count++;
            }
        }

        return count;
    }
};

int main() {
    string s;

    cout << "Enter the binary string: ";
    cin >> s;

    Solution obj;

    int result = obj.minChanges(s);

    cout << "Minimum changes required: " << result << endl;

    return 0;
}
