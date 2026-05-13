#include<iostream>
#include<vector>
#include<string>
#include<stack>
using namespace std;

class Solution {
public:
    vector<int> separateDigits(vector<int>& nums) {

        //APPROACH 1

        // vector<int> ans;
        // stack<int> st;

        // for(int i = 0; i < nums.size(); i++)
        // {
        //     int num = nums[i];
        //     while(num > 0)
        //     {
        //         int digit = num % 10;
        //         st.push(digit);

        //         num = num / 10;
        //     }
            
        //     while(!st.empty())
        //     {
        //         ans.push_back(st.top());

        //         st.pop();
        //     }

        // }

        // return ans;


        //APPROACH 2

        vector<int> ans;

        for(int num: nums)
        {
            string s = to_string(num);

            for(char ch : s)
            {
                ans.push_back(ch - '0');
            }
        }

        return ans;
    }
};