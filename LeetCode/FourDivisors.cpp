#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int findSumDivisiors(int num)
    {
        int divisors = 0;
        int sum = 0;

        for(int fact = 1; fact*fact <= num; fact++)
        {
            if(num % fact == 0)
            {
                int other = num/fact;

                if(other == fact)//perfect square number
                {
                    divisors += 1;
                    sum += fact; 
                }
                else
                {
                    divisors += 2;
                    sum += (fact + other);
                }
            }

            if(divisors > 4)
                return 0;
        }

        if(divisors == 4)
            return sum;

        return 0;
    }

    int sumFourDivisors(vector<int>& nums) {
        int result = 0;

        for(int &num : nums)
        {
            result += findSumDivisiors(num);
        }

        return result;
    }
};

int main()
{
    int n;
    cin >> n;

    vector<int> nums(n);
    for(int i = 0; i < n; i++)
        cin >> nums[i];

    Solution obj;
    cout << obj.sumFourDivisors(nums);

    return 0;
}
