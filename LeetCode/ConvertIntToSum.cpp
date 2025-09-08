#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool hasNoZeroDigits(int num)
    {
        // Handle the case when num is 0 (should return false since 0 contains 0)
        if (num == 0) return false;
        
        while (num > 0)
        {
            if (num % 10 == 0) // if any digit is zero
            {
                return false;
            }
            num = num / 10; // remove the last digit
        }
        return true; // no zero digits found
    }

    vector<int> getNoZeroIntegers(int n) {
        vector<int> ans;
        
        for (int i = 1; i < n; i++)
        {
            int a = i;
            int b = n - i;
            
            if (hasNoZeroDigits(a) && hasNoZeroDigits(b))
            {
                ans.push_back(a);
                ans.push_back(b);
                break;
            }
        }
        
        return ans;
    }
};

// Main function to test the code
int main() {
    Solution sol;
    int n;
    
    // Test case 1
    n = 2;
    vector<int> result1 = sol.getNoZeroIntegers(n);
    cout << "For n = " << n << ": [" << result1[0] << ", " << result1[1] << "]" << endl;
    
    // Test case 2
    n = 11;
    vector<int> result2 = sol.getNoZeroIntegers(n);
    cout << "For n = " << n << ": [" << result2[0] << ", " << result2[1] << "]" << endl;
    
    // Test case 3
    n = 1000;
    vector<int> result3 = sol.getNoZeroIntegers(n);
    cout << "For n = " << n << ": [" << result3[0] << ", " << result3[1] << "]" << endl;
    
    // Test case 4
    n = 1019;
    vector<int> result4 = sol.getNoZeroIntegers(n);
    cout << "For n = " << n << ": [" << result4[0] << ", " << result4[1] << "]" << endl;
    
    return 0;
}