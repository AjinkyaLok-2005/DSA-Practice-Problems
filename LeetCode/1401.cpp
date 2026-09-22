#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

class Solution {
public:
    bool checkOverlap(int radius, int xCenter, int yCenter,
                      int x1, int y1, int x2, int y2) {

        int xi = clamp(xCenter, x1, x2);
        int yi = clamp(yCenter, y1, y2);

        return sqrt((xi - xCenter) * (xi - xCenter) +
                    (yi - yCenter) * (yi - yCenter)) <= radius;
    }
};

int main() {

    Solution sol;

    // Example 1
    int radius = 1;
    int xCenter = 0;
    int yCenter = 0;
    int x1 = 1;
    int y1 = -1;
    int x2 = 3;
    int y2 = 1;

    bool result = sol.checkOverlap(
        radius, xCenter, yCenter,
        x1, y1, x2, y2
    );

    cout << boolalpha << result << endl;

    return 0;
}