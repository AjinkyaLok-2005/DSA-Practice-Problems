#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    string convertToTitle(int columnNumber) {
        string result;

        while (columnNumber > 0)
        {
            columnNumber--;

            int remainder = columnNumber % 26;

            result += 'A' + remainder;

            columnNumber /= 26;
        }

        reverse(begin(result), end(result));

        return result;
    }
};

int main() {
    Solution solution;

    int columnNumber;
    cin >> columnNumber;

    string result = solution.convertToTitle(columnNumber);

    cout << result << endl;

    return 0;
}