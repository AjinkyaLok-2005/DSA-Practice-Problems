
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canAliceWin(int n) {
        int take = 10;
        int steps = 0;

        while (n >= take)
        {
            n -= take;
            take--;
            steps++;
        }

        return steps % 2 == 1;
    }
};

int main() {
    int n;
    cin >> n;

    Solution obj;

    if (obj.canAliceWin(n))
        cout << "Alice" << endl;
    else
        cout << "Bob" << endl;

    return 0;
}
