#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int gcd(int a, int b)
    {
        if (b > a)
            return gcd(b, a);

        if (b == 0)
            return a;

        return gcd(b, a % b);
    }

    int findGCD(vector<int>& nums)
    {
        sort(nums.begin(), nums.end());

        int minVal = nums[0];
        int maxVal = nums[nums.size() - 1];

        return gcd(maxVal, minVal);
    }
};

int main()
{
    int n;

    cout << "Enter the number of elements: ";
    cin >> n;

    vector<int> nums(n);

    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }

    Solution obj;

    int ans = obj.findGCD(nums);

    cout << "GCD of the minimum and maximum element is: " << ans << endl;

    return 0;
}