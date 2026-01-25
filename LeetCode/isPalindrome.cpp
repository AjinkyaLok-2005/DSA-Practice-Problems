#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
        
        if (x < 0 || (x % 10 == 0 && x != 0))
            return false;

        int reversedHalf = 0;

        while (x > reversedHalf) {
            reversedHalf = reversedHalf * 10 + x % 10;
            x /= 10;
        }

        // even : x == reversedHalf
        // odd: x == reversedHalf / 10 (middle digit ignored)
        return (x == reversedHalf || x == reversedHalf / 10);
    }
};


int main() {
    Solution obj;

    int x;
    cout << "Enter a number: ";
    cin >> x;

    if (obj.isPalindrome(x))
        cout << "Palindrome" << endl;
    else
        cout << "Not Palindrome" << endl;

    return 0;
}
