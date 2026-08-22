#include <iostream>
using namespace std;

class Solution {
public:
    bool checkDivisibility(int n) {
        int N = n;
        int sum = 0;
        int pdt = 1;

        while(N != 0)
        {
            int digit = N % 10;
            sum += digit;
            pdt *= digit;
            N = N / 10;
        }

        int tSum = sum + pdt;

        if(n % tSum == 0)
        {
            return true;
        }  
        else
        {
            return false;
        }
    }
};

int main()
{
    Solution sol;

    int n;
    cout << "Enter a number: ";
    cin >> n;

    bool result = sol.checkDivisibility(n);

    if(result)
        cout << n << " is divisible by (sum of digits + product of digits)." << endl;
    else
        cout << n << " is NOT divisible by (sum of digits + product of digits)." << endl;

    return 0;
}