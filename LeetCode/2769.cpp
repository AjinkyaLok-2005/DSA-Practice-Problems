#include<iostream>
using namespace std;

class Solution {
public:
    int theMaximumAchievableX(int num, int t) {
        return num + 2*t;
    }
};

int main() {
    int num, t;

    cout << "Enter num: ";
    cin >> num;

    cout << "Enter t: ";
    cin >> t;

    Solution obj;
    int result = obj.theMaximumAchievableX(num, t);

    cout << "The Maximum Achievable X = " << result << endl;

    return 0;
}