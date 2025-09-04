#include <iostream>
#include <cmath> // For abs() function
using namespace std;

int findClosest(int x, int y, int z) {
    int diff1 = abs(z - x);
    int diff2 = abs(z - y);

    if (diff1 < diff2) {
        return 1; // x is closer to z
    } else if (diff1 == diff2) {
        return 0; // both are equally close
    } else {
        return 2; // y is closer to z
    }
}

int main() {
    // Test cases
    int testCases[][3] = {
        {5, 10, 7},    // x=5, y=10, z=7
        {3, 8, 5},     // x=3, y=8, z=5
        {2, 2, 2},     // x=2, y=2, z=2
        {1, 4, 3},     // x=1, y=4, z=3
        {10, 20, 15},  // x=10, y=20, z=15
        {5, 5, 10}     // x=5, y=5, z=10
    };

    cout << "Testing findClosest function:\n";
    cout << "Return values: 1 (x is closer), 2 (y is closer), 0 (equal distance)\n\n";

    for (int i = 0; i < sizeof(testCases) / sizeof(testCases[0]); i++) {
        int x = testCases[i][0];
        int y = testCases[i][1];
        int z = testCases[i][2];
        
        int result = findClosest(x, y, z);
        
        cout << "Test " << i + 1 << ": x=" << x << ", y=" << y << ", z=" << z;
        cout << " -> Result: " << result << " (";
        
        if (result == 1) {
            cout << "x is closer)";
        } else if (result == 2) {
            cout << "y is closer)";
        } else {
            cout << "equal distance)";
        }
        cout << endl;
    }

    // Interactive testing
    cout << "\nInteractive testing (enter 0 0 0 to exit):\n";
    while (true) {
        int x, y, z;
        cout << "Enter x, y, z: ";
        cin >> x >> y >> z;
        
        if (x == 0 && y == 0 && z == 0) {
            break;
        }
        
        int result = findClosest(x, y, z);
        cout << "Result: " << result << " - ";
        
        if (result == 1) {
            cout << x << " is closer to " << z << " than " << y << endl;
        } else if (result == 2) {
            cout << y << " is closer to " << z << " than " << x << endl;
        } else {
            cout << "Both " << x << " and " << y << " are equally close to " << z << endl;
        }
        cout << endl;
    }

    return 0;
}